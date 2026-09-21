package co.tarutani.BatteryForecast.ui

import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.Explore
import androidx.compose.material3.Card
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.Icon
import androidx.compose.material3.LinearProgressIndicator
import androidx.compose.material3.OutlinedTextField
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.ui.text.TextStyle
import androidx.compose.material3.TopAppBar
import androidx.compose.material3.TopAppBarDefaults
import androidx.compose.runtime.Composable
import androidx.compose.runtime.collectAsState
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.lifecycle.viewmodel.compose.viewModel
import co.tarutani.BatteryForecast.utils.rememberCurrentAddress

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun homeScreenTest(modifier: Modifier = Modifier) {
    val context = LocalContext.current
    val batteryViewModel: BatteryViewModel = viewModel(factory = BatteryViewModelFactory(context))
    val batteryCapacityAh by batteryViewModel.batteryCapacity.collectAsState()
    val distancePerAhKm by batteryViewModel.distancePerAh.collectAsState()

    var currentInputPercentage by remember { mutableStateOf("") }
    var displayedPercentage by remember { mutableStateOf(0f) }
    var estimatedRangeKm by remember { mutableStateOf("Enter Battery %") }

    val currentAddress = rememberCurrentAddress()

    fun calculateEstimatedRange(percentage: Double?) {
        val capacity = batteryCapacityAh.toDoubleOrNull() ?: 0.0
        val distancePerAh = distancePerAhKm.toDoubleOrNull() ?: 0.0

        if (capacity > 0 && distancePerAh > 0 && percentage != null && percentage in 0.0..100.0) {
            estimatedRangeKm = String.format("%.2f", (capacity * (percentage / 100.0) * distancePerAh))
            displayedPercentage = (percentage / 100.0).toFloat().coerceIn(0f, 1f) // Corrected line
        } else {
            estimatedRangeKm = "Enter Battery %"
            displayedPercentage = 0f
        }
    }

    Scaffold(
        topBar = {
            TopAppBar(
                title = { Text(text = "Battery Forecast") },
                colors = TopAppBarDefaults.topAppBarColors()
            )
        }
    ) { paddingValues ->
        Column(
            modifier = modifier.padding(paddingValues).padding(10.dp)
        ) {
            Card(
                modifier = Modifier
                    .fillMaxWidth()
                    .padding(8.dp)
            ) {
                Column(modifier = Modifier.padding(16.dp)) {
                    Text(
                        text = "Battery estimate:",
                        fontSize = 24.sp,
                    )
                    OutlinedTextField(
                        value = currentInputPercentage,
                        onValueChange = {
                            currentInputPercentage = it
                            calculateEstimatedRange(it.toDoubleOrNull())
                        },
                        label = { Text("Enter Battery (%)") },
                        modifier = Modifier.fillMaxWidth()
                    )
                    Row(
                        modifier = Modifier.fillMaxWidth().padding(top = 8.dp),
                        verticalAlignment = Alignment.CenterVertically
                    ) {
                        Text(
                            text = "$estimatedRangeKm",
                            fontSize = 30.sp,
                        )
                        LinearProgressIndicator(
                            progress = { displayedPercentage },
                            modifier = Modifier.weight(1f).padding(start = 8.dp),
                        )
                    }
                    Text(
                        text = "Estimated Kilometers remaining",
                        fontSize = 16.sp,
                        modifier = Modifier.padding(top = 8.dp)
                    )
                }
            }

            Card(
                modifier = Modifier
                    .fillMaxWidth()
                    .padding(8.dp)
            ) {
                Column(
                    modifier = Modifier.padding(16.dp),
                    horizontalAlignment = Alignment.CenterHorizontally
                ) {
                    Text(
                        text = "Current Location:",
                        fontSize = 25.sp,
                    )
                    Text(
                        text = "Current Address: $currentAddress",
                        fontSize = 18.sp,
                    )
                }
            }

            Card(
                modifier = Modifier
                    .fillMaxWidth()
                    .padding(8.dp)
            ) {
                Column(modifier = Modifier.padding(16.dp)) {
                    Text(
                        text = "Enter your battery information in the settings tab, and plan trips in the trips tab!",
                        fontSize = 18.sp,
                    )
                }
            }


        }
    }
}