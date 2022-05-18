#include "Clock.h"                        // processor derectives
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable : 4996)
#include <string>
#include <ctime>
#include <cstdio>
#include <limits>
#include <sstream>
#undef max

using namespace std;

int Clock::GetHour() {                     // function definition
    //get the time from c library
    tm* my_time;
    time_t t = time(NULL);                 // get current time in format of time_t
    my_time = localtime(&t);               // store object in variable
    int hour{ my_time->tm_hour };          // store hours in variable

    return hour;
}
int Clock::GetMin() {                      // function definition
    //get the time from c library
    tm* my_time;
    time_t t = time(NULL);                 // get current time in format of time_t
    my_time = localtime(&t);               // store object in variable
    int min{ my_time->tm_min };            // store minutes in variable

    return min;
}
int Clock::GetSec() {                      // function definition
    //get the time from c library
    tm* my_time;
    time_t t = time(NULL);                 // get current time in format of time_t
    my_time = localtime(&t);               // store object in variable
    int sec{ my_time->tm_sec };            // store seconds in variable

    return sec;
}
void Clock::IncrementHour(int& hour, int& min, int& sec){    // function definition
    hour = hour + 1;                                         // increment reference variable
    if (hour > 23) {                                         // check condition
        hour = 0;                                            // when true assign hour to zero
    }
}
void Clock::IncrementMin(int& hour, int& min, int& sec) {    // function definition
    min = min + 1;                                           // increment reference variable
    if (min > 59) {                                          // check condition
        min = 0;                                             // when true asign minutes to zero
        hour += 1;                                           // when true increment hour
    }
    if (hour > 23) {                                         // check condition
        hour = 0;                                            // when true assign hour to zero
    }
}
void Clock::IncrementSec(int& hour, int& min, int& sec) {    // function definition
    sec = sec + 1;                                           // increment reference variable
    if (sec > 59) {                                          // check condition
        sec = 0;                                             // when true assign seconds to zero
        min += 1;                                            // when true increment minutes
    }
    if (min > 59) {                                          // check condition
        min = 0;                                             // when true assign minutes to zero
        hour += 1;                                           // when true increment hour
    }
    if (hour > 23) {                                         // check condition
        hour = 0;                                            // when true assign hour to zero
    }
}
void Clock::GetTime(int& hour, int& min, int sec) {                                    // function definition
    system("color 1C");                                                                // change console color
    system("cls");                                                                     // clear console output
    string firstLine{ "***************************     **************************" };  // variable declaration/initialization
    string secondLine{ "*       12-Hour Clock     *     *       24-Hour Clock    *" }; // variable declaration/initialization

    cout << "\n\n" << endl;                                                            // formatted output to user
    cout << setw(85) << right << setfill(' ') << firstLine << endl;
    cout << setw(85) << right << setfill(' ') << secondLine << endl;
    cout << endl;
    cout << setw(35) << right << "*       ";

    if (hour == 0) {                                                           // check condition
        printf("%02d:%02d:%02d A M      *", hour + 12, min, sec);              // when true output to user
    }
    else if (hour > 12) {                                                      // check condition when previous conditions false
        printf("%02d:%02d:%02d P M      *", hour - 12, min, sec);              // when true output to user
    }
    else if (hour == 12) {                                                     // check condition when previous conditions false
        printf("%02d:%02d:%02d P M      *", hour, min, sec);                   // when true output to user
    }
    else {                                                                     // check condition when previous conditions false
        printf("%02d:%02d:%02d A M      *", hour, min, sec);                   // when true output to user
    }
    printf("     *       %02d:%02d:%02d         *\n", hour, min, sec);
    cout << setw(85) << right << setfill(' ') << firstLine << endl;            // formatted output to user
}
