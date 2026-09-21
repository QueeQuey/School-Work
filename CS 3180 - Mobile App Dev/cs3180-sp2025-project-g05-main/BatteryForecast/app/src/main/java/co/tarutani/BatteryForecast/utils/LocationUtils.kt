package co.tarutani.BatteryForecast.utils

import androidx.compose.runtime.Composable
import androidx.compose.ui.platform.LocalContext
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.activity.compose.rememberLauncherForActivityResult
import androidx.activity.result.contract.ActivityResultContracts
import androidx.core.content.ContextCompat
import androidx.core.content.PermissionChecker
import androidx.compose.runtime.LaunchedEffect
import com.google.android.gms.location.LocationServices
import com.google.android.gms.location.FusedLocationProviderClient
import android.Manifest
import android.content.Context
import android.location.Location
import android.location.Geocoder
import android.annotation.SuppressLint
import android.location.Address
import androidx.compose.runtime.setValue
import java.util.Locale

@SuppressLint("MissingPermission")
@Composable
fun rememberCurrentAddress(): String {
    val context = LocalContext.current
    var address by remember { mutableStateOf("Fetching address...") }
    val fusedLocationClient = remember {
        LocationServices.getFusedLocationProviderClient(context)
    }
    val locationPermissionLauncher = rememberLauncherForActivityResult(
        ActivityResultContracts.RequestPermission()
    ) { isGranted ->
        if (isGranted) {
            fetchLocationAndAddress(context, fusedLocationClient) { fetchedAddress ->
                address = fetchedAddress ?: "Unable to fetch address"
            }
        } else {
            address = "Permission denied"
        }
    }

    LaunchedEffect(Unit) {
        when (ContextCompat.checkSelfPermission(context, Manifest.permission.ACCESS_FINE_LOCATION)) {
            PermissionChecker.PERMISSION_GRANTED -> {
                fetchLocationAndAddress(context, fusedLocationClient) { fetchedAddress ->
                    address = fetchedAddress ?: "Unable to fetch address"
                }
            }
            else -> locationPermissionLauncher.launch(Manifest.permission.ACCESS_FINE_LOCATION)
        }
    }
    return address
}

@SuppressLint("MissingPermission")
fun fetchLocationAndAddress(
    context: Context,
    fusedLocationClient: FusedLocationProviderClient,
    onAddressFetched: (String?) -> Unit
) {
    fusedLocationClient.lastLocation.addOnSuccessListener { location ->
        location?.let {
            getAddressFromLocation(context, it) { address ->
                onAddressFetched(address)
            }
        } ?: onAddressFetched("Location not found")
    }.addOnFailureListener {
        onAddressFetched("Error fetching location: ${it.message}")
    }
}

private fun getAddressFromLocation(
    context: Context,
    location: Location,
    onAddressFetched: (String?) -> Unit
) {
    val geocoder = Geocoder(context, Locale.getDefault())
    val latitude = location.latitude
    val longitude = location.longitude

    try {
        val addresses: MutableList<Address>? = geocoder.getFromLocation(latitude, longitude, 1)
        if (addresses != null) {
            if (addresses.isNotEmpty()) {
                val address = addresses[0].getAddressLine(0)
                onAddressFetched(address)
            } else {
                onAddressFetched("No address found")
            }
        }
    } catch (e: Exception) {
        e.printStackTrace()
        onAddressFetched("Error fetching address: ${e.message}")
    }
}

