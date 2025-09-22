// CS151 Fall 2025, Decimal to Binary Converter
// Author:   Jack Marriott
// Module:   4
// Project:  Time
// Problem Statement: Demonstration of using ctime in C++
//
// Algorithm:
//   1. Demonstrate today's date in three different formats using manual formatting
//   2. Demonstrate the same date in the same formats using strftme
//   3. Demonstrate the current time in 12 and 24 hour formats using strftme
//   4. Demonstrate the date for the next Comic Con and set a 1 week reminder

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

int main(void)
{
    // 4. Make sure to set the time zone to Pacific Time.
    // This is a Linux environment
    setenv("TZ", "PST8PDT", 1);

    // 5. Create a  time_t  variable and set to the current time
    time_t epoch_seconds;
    time_t now = time(&epoch_seconds);

    // 6. Establish a tm structure, then fill it with the information for the current time:
    tm *local = localtime(&now);

    // 7. Print today's date.  Use the individual elements of the local structure and the array of month names
    cout << "Today's date in various formats:\n";
    cout << local->tm_mon + 1 << "/" << local->tm_mday << "/" << local->tm_year + 1900 - 2000 << "\n";
    cout << months[local->tm_mon] << " " << local->tm_mday << ", " << local->tm_year + 1900 << "\n";
    cout << local->tm_mday << "-" << months[local->tm_mon].substr(0, 3) << "-" << local->tm_year + 1900 << "\n\n";

    // 8. Using the  strftime  function, print today's date in the same format as those immediately above
    char timestr[80];
    cout << "Today's date using strftme function:\n";
    strftime(timestr, 80, "%D", local);
    puts(timestr);
    strftime(timestr, 80, "%B %d, %G", local);
    puts(timestr);
    strftime(timestr, 80, "%d-%b-%G", local);
    puts(timestr);
    cout << "\n";

    // 9. Using the strftime function, print the current time in the following format
    cout << "The current time using strftime:\n";
    strftime(timestr, 80, "%H:%M", local);
    puts(timestr);
    strftime(timestr, 80, "%I:%M %p", local);
    puts(timestr);
    cout << "\n";

    // 10. Create another tm structure for an important event: the next Comic-Con July 23, 2026
    tm comic_con;
    comic_con.tm_year = 2026 - 1900; // current year of event
    comic_con.tm_mon = 6;            // month (0 - 11)
    comic_con.tm_mday = 23;          // day (1 - 31)
    comic_con.tm_hour = 8;           // hour (0 - 23)
    comic_con.tm_min = 0;            // minute (0 - 59)
    comic_con.tm_sec = 0;            // second (0 - 59)
    comic_con.tm_isdst = -1;         // daylight savings (true/false)

    // 11. Determine how many seconds after epoch the event occurred
    time_t time_comic_con = mktime(&comic_con);
    cout << "The big event will occur on " <<
        ctime(&time_comic_con) <<
        " and will occur " << time_comic_con <<
        " seconds after epoch!\n";

    // 12. Number of seconds in one week
    const int SEC_PER_WEEK = 60 * 60 * 24 * 7;

    // 13. Subtract the number of seconds in a week from the time_comic_con  variable in step 10, assign to another variable of type time_t.
    time_t time_comic_con_reminder = mktime(&comic_con) - SEC_PER_WEEK;

    // 14. Print the date and time occurring exactly one week before the big event using the ctime function.
    cout << "\nComic Con reminder will occur on " <<
    ctime(&time_comic_con_reminder) <<
    " and will occur " << time_comic_con_reminder <<
    " seconds after epoch!\n";

    // 15. Using the  strftime  function, print the day of the week and the day number of the year for Comic Con
    cout << "\nThe event will be on a " << days[comic_con.tm_wday] << ", day of the year: " << comic_con.tm_yday << "\n\n";

    return 0;
}