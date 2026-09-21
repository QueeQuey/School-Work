package co.tarutani.BatteryForecast.ui

import android.content.Context
import androidx.compose.foundation.layout.*
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.lifecycle.ViewModel
import androidx.lifecycle.ViewModelProvider
import androidx.lifecycle.viewmodel.compose.viewModel
import androidx.lifecycle.viewModelScope
import androidx.datastore.preferences.core.Preferences
import androidx.datastore.preferences.core.edit
import androidx.datastore.preferences.core.stringPreferencesKey
import androidx.datastore.preferences.preferencesDataStore
import kotlinx.coroutines.flow.*
import kotlinx.coroutines.launch
import co.tarutani.BatteryForecast.data.dataStore
/*
// Create the DataStore
private val Context.dataStore by preferencesDataStore(name = "battery_prefs")
*/
class BatteryViewModel(private val context: Context) : ViewModel() {

    private val BATTERY_CAPACITY_KEY = stringPreferencesKey("battery_capacity")
    private val DISTANCE_PER_AH_KEY = stringPreferencesKey("distance_per_ah")

    private val _batteryCapacity = MutableStateFlow("")
    val batteryCapacity: StateFlow<String> = _batteryCapacity

    private val _distancePerAh = MutableStateFlow("")
    val distancePerAh: StateFlow<String> = _distancePerAh

    init {
        loadFromDataStore()
    }

    private fun loadFromDataStore() {
        context.dataStore.data
            .onEach { prefs ->
                _batteryCapacity.value = prefs[BATTERY_CAPACITY_KEY] ?: ""
                _distancePerAh.value = prefs[DISTANCE_PER_AH_KEY] ?: ""
            }
            .launchIn(viewModelScope)
    }

    fun setBatteryCapacity(value: String) {
        _batteryCapacity.value = value
        viewModelScope.launch {
            context.dataStore.edit { it[BATTERY_CAPACITY_KEY] = value }
        }
    }

    fun setDistancePerAh(value: String) {
        _distancePerAh.value = value
        viewModelScope.launch {
            context.dataStore.edit { it[DISTANCE_PER_AH_KEY] = value }
        }
    }
}

// ViewModel factory to pass context
class BatteryViewModelFactory(private val context: Context) : ViewModelProvider.Factory {
    override fun <T : ViewModel> create(modelClass: Class<T>): T {
        return BatteryViewModel(context) as T
    }
}

@Composable
fun batteryScreen(modifier: Modifier = Modifier) {
    val context = LocalContext.current
    val viewModel: BatteryViewModel = viewModel(factory = BatteryViewModelFactory(context))

    val batteryCapacity by viewModel.batteryCapacity.collectAsState()
    val distancePerAh by viewModel.distancePerAh.collectAsState()

    Column(
        modifier = modifier
            .padding(16.dp)
            .fillMaxWidth(),
        verticalArrangement = Arrangement.spacedBy(12.dp)
    ) {
        Text(
            text = "Battery Forecast",
            fontSize = 32.sp,
            modifier = Modifier.padding(bottom = 8.dp)
        )

        OutlinedTextField(
            value = batteryCapacity,
            onValueChange = { viewModel.setBatteryCapacity(it) },
            label = { Text("Total Battery Capacity (Ah)") },
            modifier = Modifier.fillMaxWidth()
        )

        OutlinedTextField(
            value = distancePerAh,
            onValueChange = { viewModel.setDistancePerAh(it) },
            label = { Text("Distance per Ah") },
            modifier = Modifier.fillMaxWidth()
        )
        /*
        Text(
            text = "Once we have the calculations down, there will be a battery graph here!",
            fontSize = 16.sp,
            modifier = Modifier.padding(top = 16.dp)
        )

         */
    }
}
