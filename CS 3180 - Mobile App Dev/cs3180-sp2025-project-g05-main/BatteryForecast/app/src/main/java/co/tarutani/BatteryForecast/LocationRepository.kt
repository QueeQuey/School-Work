package co.tarutani.BatteryForecast.data

import android.content.Context

class LocationRepository(context: Context) {
    private val locationDao = AppDatabase.getDatabase(context).locationDao()

    suspend fun insertLocation(location: LocationEntry) = locationDao.insertLocation(location)

    suspend fun deleteLocation(location: LocationEntry) = locationDao.deleteLocation(location)

    suspend fun getAllLocations(): List<LocationEntry> = locationDao.getAllLocations()
}
