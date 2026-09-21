#ifndef CCC_TIME_H
#define CCC_TIME_H

/**
   A class that describes a time of day
   (between 00:00:00 and 23:59:59)
*/
class Time
{
public:
   /**
      Constructs a time of day.
      @param hour the hours
      @param min the minutes
      @param sec the seconds
   */
   Time(int hour, int min, int sec);
   /**
      Constructs a Time object that is set to 
      the time at which the constructor executes.
   */
   Time();

   /**
      Gets the hours of this time.
      @return the hours
   */
   int get_hours() ;
   /**
      Gets the minutes of this time.
      @return the minutes
   */
   int get_minutes();
   /**
      Gets the seconds of this time.
      @return the seconds
   */
   int get_seconds();

   /**
      Computes the seconds between this time and another.
      @param t the other time
      @return the number of seconds between this time and t
   */
   int seconds_from(Time t);
   /**
      Adds a number of seconds to this time.
      @param s the number of seconds to add
   */
   void add_seconds(int s);

private:
   int time_in_secs;
};

#endif
