package co.tarutani.BatteryForecast.data

import androidx.room.Dao
import androidx.room.Delete
import androidx.room.Insert
import androidx.room.OnConflictStrategy
import androidx.room.Query
//Pretty straightforward, Dao to get all locations, insert, and delete.
@Dao
interface LocationDao {
    @Query("SELECT * FROM locations ORDER BY id DESC")
    suspend fun getAllLocations(): List<LocationEntry>

    @Insert(onConflict = OnConflictStrategy.REPLACE)
    suspend fun insertLocation(location: LocationEntry)

    @Delete
    suspend fun deleteLocation(location: LocationEntry)
}