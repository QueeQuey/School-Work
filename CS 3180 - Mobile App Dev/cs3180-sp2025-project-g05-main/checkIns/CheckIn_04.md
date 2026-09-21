# CheckIn_04.md
### P5: Check In #4

**Layne**
- I FINALLY was able to get an implementation of stored values for locations. Currently stores Lattitude, Longitude, and a Name as a starter.
- The implementation is mostly based off of the Zybook ToDoList implementation. 
- For Dr. Green (more directly) I Added AppDatabase, the LocationDao, the LocationEntry class, a loctionRespository class and redid the tripsScreen. Currently only on layne branch.
- I think address -> Lattitude/Longitude conversions are outside of the scope of the project but if it is easy then we'll see.
- In the future the only thing you can do to the store locations is delete them, but after we can get currentLocation we can calculate distances / start trips on a click.

**Ben**
- Between this check in and the last, I researched weather APIs and how to measure how increased drag due to unfavorable wind affects ebike range. I also fixed and finalized the current implementation of routes. Layne and I accidentally duplicated work, due to bad communication on my part.
- This check in, I have begun implementing a coroutine, which is unfinished, that will pull current weather data from NOAA's weather API and store the results in a data class. 
- I may have difficulty consistently converting the JSON data from the API to numbers, but do not anticipate this being a significant hurdle.
- Between this and the next check in, I plan to complete implementing the mentioned coroutine.

**Noah**
- Between this check in and the last, I have been working on implementing location tracking permissions and passing location data to our app. Unfortuantely, it has been a long journey fixing bugs, so this is not implemented yet.
- This check in, I have been learning about the Android permission system, and (slowly) how to handle geolocation requirements.
- I might need help with the location stuff if I can not figure it out soon, but once I get that implemented it should be fairly smooth sailing.
- Between this check in and the next, I hope to fully add the location data into the app, adding our first layer of completed functionality.
