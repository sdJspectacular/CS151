#ifndef _EVENT_
#define _EVENT_

#include <iostream>
#include <string>
#include "TimeDate.cpp"

using namespace std;

// 4. Create a new class named  Event  which consists of three variables:
// a start time, an end time, and a description
class Event
{
private:
    // Demonstrates composition because the lifetime of the TimeDate objects
    // is limited to the lifetime of the Event object
    TimeDate start_time, end_time;
    string description;

public:
    // 5. Create a constructor for the  Event  class which initializes all variables using an member
    // initializer list and a function to return information about the event
    Event(int start_hour, int start_minute, int start_day,
          string start_month,
          int end_hour, int end_minute, int end_day,
          string end_month, string description) : start_time(start_hour, start_minute, start_day, start_month) ,
          end_time(end_hour, end_minute, end_day, end_month) , description(description) {};

    // Get the Event TimeDates as a signle combined string
    string getEvent()
    {
        return description + " starts at " +
               start_time.getTimeDate() +
               ", ends at " +
               end_time.getTimeDate();
    };
};

#endif // _EVENT_
