# CheckIn_05.md
### P7: Check In #5

**Layne**
- <<TODO>>

**Ben**
- Between this and the last check in, I have partially implemented calls to NOAA's weather API. Created data and utils packages for better organization. The data package houses data classes for metadata of coordinate pairs, as well as the outputs of weather forecast calls.
- This check in, I built a better understanding of how API calls are done.
- I may need help connecting the two API calls, as the call to one depends on a value from the other.
- From now to the next check-in, I plan to sort out displaying and using information from the API calls, and implement some logic for wind resistance calculation.

**Noah**
- Between this check in and the last, I finished woking on the location system. It now can return latitude/longitude, or your approximate adress.
    - A new *utils* folder/package has also been added, holding the location file for now but will also house API integrations or other utilities that would be nice to call from multiple files
    - I have also begun working on some persistant storage stuff too, specifically looking into a UUID system with a given username we can pass as a user agent into the weather API
- This check in, I have learned about how apps store data and access the web via APIs
- I might need help with the persistant storage, as I am not the expert on that in my group, but it should not hold me back too much
- Between this check in and the next, I plan on creating a user account system, and using the location system to map trips and pull the weather in coordination with my teammates.
