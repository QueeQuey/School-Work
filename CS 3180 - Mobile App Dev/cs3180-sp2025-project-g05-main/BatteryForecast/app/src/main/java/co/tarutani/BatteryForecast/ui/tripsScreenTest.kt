
import android.app.Application
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Delete
import androidx.compose.material3.Button
import androidx.compose.material3.Card
import androidx.compose.material3.CardDefaults
import androidx.compose.material3.Icon
import androidx.compose.material3.IconButton
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.LaunchedEffect
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateListOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.text.input.TextFieldValue
import androidx.compose.ui.unit.dp
import androidx.lifecycle.AndroidViewModel
import androidx.lifecycle.ViewModelProvider
import androidx.lifecycle.viewModelScope
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.lifecycle.viewmodel.initializer
import androidx.lifecycle.viewmodel.viewModelFactory
import co.tarutani.BatteryForecast.data.LocationEntry
import co.tarutani.BatteryForecast.data.LocationRepository
import kotlinx.coroutines.launch
import co.tarutani.BatteryForecast.utils.rememberCurrentAddress
import co.tarutani.BatteryForecast.utils.fetchLocationAndAddress
import android.location.Location
import androidx.compose.ui.platform.LocalContext
import com.google.android.gms.location.LocationServices
import androidx.datastore.preferences.core.Preferences
import androidx.datastore.preferences.core.stringPreferencesKey
import androidx.datastore.preferences.preferencesDataStore
import kotlinx.coroutines.flow.first
import kotlinx.coroutines.runBlocking
import android.content.Context
import android.util.Log
import co.tarutani.BatteryForecast.data.dataStore


class TripsViewModel(application: Application) : AndroidViewModel(application) {
    //Mutable, set to null initally to get overriden by Noah's code
    var currentLocation by mutableStateOf<Location?>(null)
        private set

    //Added to update the current Location, as it says
    fun updateCurrentLocation(location: Location) {
        currentLocation = location
    }
    //Grabs the locs
    private val locationRepository = LocationRepository(application)
    companion object {
        val Factory: ViewModelProvider.Factory = viewModelFactory {
            initializer {
                val application = (this[ViewModelProvider.AndroidViewModelFactory.APPLICATION_KEY] as Application)
                TripsViewModel(application)
            }
        }
    }
//Used to be modified later
    var locationList = mutableStateListOf<LocationEntry>()
        private set
//Used to be used but not used anymore/
    var confirmDelete by mutableStateOf(true)
    var errorMessage by mutableStateOf<String?>(null)

    //Exactly what it says. Adds locations to the Repo
    fun addLocation(name: String, latitude: Double, longitude: Double) {
        viewModelScope.launch {
            try {
                //New Object to insert
                val newLocation = LocationEntry(name = name, latitude = latitude, longitude = longitude)
                //Adding to the repository
                locationRepository.insertLocation(newLocation)
                //Logged
                Log.d("LocationInserted", "Location added: $newLocation")
                //Adding location to the list
                locationList.add(newLocation)
            } catch (e: Exception) {
                errorMessage = "Error adding location"
                Log.e("LocationError", "Error inserting location", e)
            }
        }
    }

    //Does what it says from the Location Repo
    fun deleteLocation(location: LocationEntry) {
        viewModelScope.launch {
            try {
                locationRepository.deleteLocation(location)
                locationList.remove(location)
            } catch (e: Exception) {
                errorMessage = "Error deleting location"
            }
        }
    }
//Call from location Rep, clears before calls just in case
    fun loadLocations() {
        viewModelScope.launch {
            try {
                val locations = locationRepository.getAllLocations()
                locationList.clear()
                locationList.addAll(locations)

                // Log the list of loaded locations
                Log.d("LocationsLoaded", "Loaded locations: $locations")
            } catch (e: Exception) {
                errorMessage = "Failed to load locations"
                Log.e("LocationError", "Error loading locations", e)
            }
        }
    }
}


//Importing everything from the Battery Page
//private val Context.dataStore by preferencesDataStore(name = "battery_prefs")

private fun getBatterySettings(context: Context): Pair<Float?, Float?> {
    val capacityKey = stringPreferencesKey("battery_capacity")
    val distanceKey = stringPreferencesKey("distance_per_ah")
    return runBlocking {
        val prefs = context.dataStore.data.first()
        val capacity = prefs[capacityKey]?.toFloatOrNull()
        val distancePerAh = prefs[distanceKey]?.toFloatOrNull()
        Pair(capacity, distancePerAh)
    }
}

//The actual screen
@Composable
fun tripsScreen(viewModel: TripsViewModel = viewModel(factory = TripsViewModel.Factory)) {
    var name by remember { mutableStateOf(TextFieldValue("")) }
    var latitude by remember { mutableStateOf<Double?>(null) }
    var longitude by remember { mutableStateOf<Double?>(null) }
    var latitudeText by remember { mutableStateOf("") }
    var longitudeText by remember { mutableStateOf("") }
    var curLatitude by remember { mutableStateOf<Double?>(null) }
    var curLongitude by remember { mutableStateOf<Double?>(null) }

    val context = LocalContext.current
    val address = rememberCurrentAddress()
    val fusedLocationClient = remember {
        LocationServices.getFusedLocationProviderClient(context)
    }

    //Doesn't handle when a user says no, but we didn't plan for that lol
    fun autofillCoordinates() {
        fusedLocationClient.lastLocation.addOnSuccessListener { location ->
            location?.let {
                curLatitude = it.latitude
                curLongitude = it.longitude
                viewModel.updateCurrentLocation(it)
                //Updates UI
                viewModel.updateCurrentLocation(it)
                latitudeText = it.latitude.toString()
                longitudeText = it.longitude.toString()
            }
        }
    }


    LaunchedEffect(Unit) {
        viewModel.loadLocations()
        autofillCoordinates()
    }

    Column(modifier = Modifier.padding(16.dp)) {
        Text("Your current address:")
        Text(address, style = MaterialTheme.typography.bodyMedium)
        Spacer(modifier = Modifier.height(8.dp))

        Button(
            onClick = { autofillCoordinates() },
            modifier = Modifier.fillMaxWidth()
        ) {
            Text("Use Current Location")
        }

        Spacer(modifier = Modifier.height(16.dp))
        //Location Name Card
        OutlinedTextField(
            value = name,
            onValueChange = { name = it },
            label = { Text("Location Name") },
            modifier = Modifier.fillMaxWidth()
        )
        //Latitude Card
        Spacer(modifier = Modifier.height(8.dp))
        OutlinedTextField(
            value = latitudeText,
            onValueChange = {
                latitudeText = it
                //latitude = it.toDouble()
            },
            label = { Text("Latitude") },
            modifier = Modifier.fillMaxWidth()
        )
        //Longitude Card
        Spacer(modifier = Modifier.height(8.dp))
        OutlinedTextField(
            value = longitudeText,
            onValueChange = {
                longitudeText = it
                //longitude = it.toDouble()
            },
            label = { Text("Longitude") },
            modifier = Modifier.fillMaxWidth()
        )

        //Add Location Card
        Spacer(modifier = Modifier.height(16.dp))
        Button(
            onClick = {
                //Had to move the latitude and longitude down here because if you do the on change, if the . is removed Kotlin doesn't know what to do and crashes.
                latitude = latitudeText.toDouble()
                longitude = longitudeText.toDouble()
                // Ensure latitude and longitude are valid before adding the location
                if (latitude != null && longitude != null) {
                    // Call the viewModel to add the location to the database
                    Log.d("DistanceDebug BEFORE ADD", "Current: ${latitude}, ${longitude}")
                    viewModel.addLocation(name.text, latitude!!, longitude!!)

                    // Clear the input fields after adding the location
                    name = TextFieldValue("")
                    latitudeText = ""
                    longitudeText = ""
                    latitude = null
                    longitude = null
                }
            },
            modifier = Modifier.fillMaxWidth()
        ) {
            Text("Add Location")
        }

        Spacer(modifier = Modifier.height(24.dp))
        Text("Saved Trips", style = MaterialTheme.typography.titleLarge)
        Spacer(modifier = Modifier.height(8.dp))

        // Display saved locations
        LazyColumn {
            items(viewModel.locationList) { locationEntry ->
                Card(
                    modifier = Modifier
                        .fillMaxWidth()
                        .padding(vertical = 4.dp),
                    elevation = CardDefaults.cardElevation(4.dp)
                ) {
                    Row(
                        modifier = Modifier
                            .fillMaxWidth()
                            .padding(16.dp),
                        horizontalArrangement = Arrangement.SpaceBetween
                    ) {
                        //Gets a location Entry
                        Column {
                            Text(locationEntry.name, style = MaterialTheme.typography.bodyLarge)
                            Text("Lat: ${locationEntry.latitude}, Lon: ${locationEntry.longitude}", style = MaterialTheme.typography.bodyMedium)
                            Log.d("DistanceDebug Current Location", "Location: ${locationEntry.name} ${locationEntry.latitude}, ${locationEntry.longitude}")

                            //Sets that location as the target (calculating distance from current location to this target location)
                            val target = Location("targetPleaseWorkFinally")
                                target.latitude = locationEntry.latitude
                                target.longitude = locationEntry.longitude
                            Log.d("PRE IF STATEMENT DistanceDebug", "Target:  ${target.latitude}, ${target.longitude}")
                            // Show distance if current location is available

                            //Brings in current location as a val to do the calulation
                            val current = viewModel.currentLocation
                            if (current != null && current.latitude != 0.0 && current.longitude != 0.0) {
                                Log.d("DistanceDebug", "Current: ${current.latitude}, ${current.longitude}")
                                Log.d("DistanceDebug", "Target:  ${target.latitude}, ${target.longitude}")

                                //Default is in meters so just divide by 1000
                                val distanceKm = current.distanceTo(target) / 1000
                                Text(String.format("Distance: %.2f km", distanceKm), style = MaterialTheme.typography.bodySmall)

                                //Gets the battery settings from the battery page
                                val (capacity, distancePerAh) = getBatterySettings(context)
                                if (capacity != null && distancePerAh != null && capacity > 0 && distancePerAh > 0) {
                                    val totalRange = capacity * distancePerAh
                                    val batteryUsedPercent = (distanceKm / totalRange) * 100
                                    Text(
                                        String.format("Battery Used: %.1f%%", batteryUsedPercent),
                                        style = MaterialTheme.typography.bodySmall,
                                        color = MaterialTheme.colorScheme.primary
                                    )
                                }
                            }
                        }
                        //Just for deleting, still on the same card.
                        IconButton(onClick = { viewModel.deleteLocation(locationEntry) }) {
                            Icon(Icons.Default.Delete, contentDescription = "Delete")
                        }
                    }
                }
            }
        }
    }
}

