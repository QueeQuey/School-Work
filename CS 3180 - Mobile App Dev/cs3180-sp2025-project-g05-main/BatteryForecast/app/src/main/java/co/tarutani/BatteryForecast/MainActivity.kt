package co.tarutani.BatteryForecast


import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import co.tarutani.BatteryForecast.ui.BatteryForecast
import co.tarutani.BatteryForecast.ui.theme.batteryForecastTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            batteryForecastTheme {
                //Surface(
                //    modifier = Modifier.fillMaxSize(),
                //    color = MaterialTheme.colorScheme.background
                //) {
                    BatteryForecast()
                //}
            }
        }
    }
}
    