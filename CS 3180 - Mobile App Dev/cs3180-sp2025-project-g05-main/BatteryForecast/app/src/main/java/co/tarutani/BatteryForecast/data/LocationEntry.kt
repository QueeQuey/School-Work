package co.tarutani.BatteryForecast.data

import androidx.room.Entity
import androidx.room.PrimaryKey
//Location Entry, only needs lat / long and a name for display. Has a primary key for the database.
@Entity(tableName = "locations")
data class LocationEntry(
    @PrimaryKey(autoGenerate = true) val id: Int = 0,
    val name: String,
    val latitude: Double,
    val longitude: Double
)