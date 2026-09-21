// co/tarutani/BatteryForecast/data/BatteryDataStore.kt
package co.tarutani.BatteryForecast.data

import android.content.Context
import androidx.datastore.preferences.preferencesDataStore

val Context.dataStore by preferencesDataStore(name = "battery_prefs")
