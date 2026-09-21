package co.tarutani.BatteryForecast.ui

import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.padding
import androidx.compose.material3.Text
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableIntStateOf
import androidx.compose.runtime.mutableStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Modifier
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp


@Composable
fun calcScreen(modifier: Modifier = Modifier) {
    var totalPizzas by remember { mutableIntStateOf(0) }
    var numPeopleInput by remember { mutableStateOf("") }
    var hungerLevel by remember { mutableStateOf("Medium") }

    Column(
        modifier = modifier.padding(10.dp)
    ) {
        Text(
            text = "Battery Forecast",
            fontSize = 38.sp,
            modifier = modifier.padding(bottom = 16.dp)
        )
        Text(
            text = "Speed (box): ",
            fontSize = 18.sp,
            modifier = Modifier.padding(4.dp)
        )
        Text(
            text = "Number of intersects with turns: ",
            fontSize = 5.sp,
            modifier = Modifier.padding(4.dp)
        )

        Text(
            text = "How do you ride?",
            fontSize = 18.sp,
            modifier = Modifier.padding(4.dp)
        )
        Text(
            text = "Climb Box",
            fontSize = 18.sp,
            modifier = Modifier.padding(4.dp)
        )

        /*
        Text(
            text = "How do you ride?",
            fontSize = 18.sp,
            modifier = Modifier.padding(4.dp)
        )

        /*Buttons not implemented yet
        Row(modifier = Modifier.fillMaxWidth(), horizontalArrangement = Arrangement.SpaceEvenly) {
            //Left Button for relaxed Ride
            Button(
                onClick = {
                    //totalPizzas = calculateNumPizzas(numPeopleInput.toIntOrNull() ?: 0, hungerLevel)
                },
                modifier = modifier.fillMaxWidth()
            ) {
                Text("Relaxed Ride")
            }
            //Right button for Forward Ride
            Button(
                onClick = {
                    //totalPizzas = calculateNumPizzas(numPeopleInput.toIntOrNull() ?: 0, hungerLevel)
                },
                modifier = modifier.fillMaxWidth()
            ) {
                Text("Calculate")
            }
        }
         */


        //Has no implmentation yet
        NumberField(
            labelText = "Width of tires?",
            textInput = tiresWidth,
            onValueChange = { tiresWidth = it },
            modifier = modifier.padding(bottom = 16.dp).fillMaxWidth()
        )

        //Has no implementation yet
        NumberField(
            labelText = "Power from rider?",
            textInput = riderPower,
            onValueChange = { riderPower = it },
            modifier = modifier.padding(bottom = 16.dp).fillMaxWidth()
        )

         */
    }
}