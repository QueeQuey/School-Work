package co.tarutani.BatteryForecast.ui

import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.width
import androidx.compose.material.icons.Icons
import androidx.compose.material.icons.filled.DirectionsBike
import androidx.compose.material.icons.filled.BatteryChargingFull
import androidx.compose.material.icons.filled.Home
import androidx.compose.material.icons.filled.Info
import androidx.compose.material.icons.filled.Navigation
import androidx.compose.material3.AlertDialog
import androidx.compose.material3.Button
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.Icon
import androidx.compose.material3.IconButton
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.NavigationBar
import androidx.compose.material3.NavigationBarItem
import androidx.compose.material3.Scaffold
import androidx.compose.material3.Text
import androidx.compose.material3.TopAppBar
import androidx.compose.material3.TopAppBarDefaults
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.graphics.vector.ImageVector
import androidx.compose.ui.unit.dp
import androidx.navigation.NavController
import androidx.navigation.compose.NavHost
import androidx.navigation.compose.composable
import androidx.navigation.compose.currentBackStackEntryAsState
import androidx.navigation.compose.rememberNavController
import kotlinx.serialization.Serializable
import tripsScreen

sealed class Routes {
    @Serializable
    data object Home

    @Serializable
    data object Battery

    @Serializable
    data object Trips


    /*
    @Serializable
    data class battery(
        val subjectId: Long
    )
     */
}

@OptIn(ExperimentalMaterial3Api::class)
@Composable
fun BatteryForecast() {
    val navController = rememberNavController()
    var showInfoDialog by remember { mutableStateOf(false) }

    Scaffold(
        topBar = {
            TopAppBar(
                title = {
                    Row(verticalAlignment = Alignment.CenterVertically) {
                        Icon(
                            imageVector = Icons.Default.DirectionsBike,
                            contentDescription = "Bike Icon",
                            tint = Color.Blue,
                            modifier = Modifier.size(32.dp)
                        )
                        Spacer(Modifier.width(8.dp))
                        Text("BatteryForecast")
                    }
                },
                actions = {
                    IconButton(onClick = { showInfoDialog = true }) {
                        Icon(Icons.Default.Info, contentDescription = "Info")
                    }
                },
                colors = TopAppBarDefaults.topAppBarColors(
                    containerColor = MaterialTheme.colorScheme.primaryContainer,
                    titleContentColor = MaterialTheme.colorScheme.primary,
                )
            )
        },
        bottomBar = {
            BottomNavBar(navController)
        }
    ) { innerPadding ->
        NavHost(
            navController = navController,
            startDestination = Routes.Home
        ) {
            composable<Routes.Battery> {
                batteryScreen()
            }
            composable<Routes.Trips> {
                tripsScreen()
            }
            composable<Routes.Home> {
                homeScreenTest()
            }
            /*
            composable<Routes.Calculator> {
                calcScreen()
            }
            */
        }

        if (showInfoDialog) {
            AlertDialog(
                onDismissRequest = { showInfoDialog = false },
                title = { Text("BatteryForecast") },
                text = { Text("This app was created by Ben, Layne, and Noah for CS3180") },
                confirmButton = {
                    Button(onClick = { showInfoDialog = false}) {
                        Text(text = "Close")
                    }
                }
            )
        }
    }
}

enum class AppScreen(val route: Any, val title: String, val icon: ImageVector) {
    HOME(Routes.Home, "Home", Icons.Default.Home),
    BATTERY(Routes.Battery, "Settings", Icons.Default.BatteryChargingFull),
    TRIPS(Routes.Trips, "Trips", Icons.Default.Navigation),
    //CALCULATOR(Routes.Calculator, "Calculator", Icons.Default.Calculate)
}

@Composable
fun BottomNavBar(navController: NavController) {
    val backStackEntry by navController.currentBackStackEntryAsState()
    val currentRoute = backStackEntry?.destination?.route

    NavigationBar {
        AppScreen.entries.forEach { item ->
            NavigationBarItem(
                selected = currentRoute?.endsWith(item.route.toString()) == true,
                onClick = {
                    navController.navigate(item.route) {
                        popUpTo(navController.graph.startDestinationId)
                    }
                },
                icon = {
                    Icon(item.icon, contentDescription = item.title)
                },
                label = {
                    Text(item.title)
                }
            )
        }
    }
}