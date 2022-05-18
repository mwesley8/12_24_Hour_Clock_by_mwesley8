// Project 1
// CS 210 Programming Languages
// Created by Maurice Wesley
// May 4, 2022

#include <iomanip>                                                        // preproccessor directives
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
#include "Clock.h"

using namespace std;

void ShowMenu() {                                                         // function declaration/definition
    cout << "\n\n";                                                       // formatted output to user
    cout << setw(70) << right << "**************************" << endl;
    cout << setw(70) << right << "* 1--Add One Hour        *" << endl;
    cout << endl;
    cout << setw(70) << right << "* 2--Add One Minute      *" << endl;
    cout << endl;
    cout << setw(70) << right << "* 3--Add One Second      *" << endl;
    cout << endl;
    cout << setw(70) << right << "* 4--Exit Program        *" << endl;
    cout << setw(70) << right << "**************************" << endl;
}
int CheckInput() {                                                        // function declaration/definition
    int userInput{ 0 };                                                   // variable declaration/initialization

    cout << "Please enter your selection: \n";                            // output to user
    cin >> userInput;                                                     // get user input
    while (1)                                                             // infinite loop
    {
        if (cin.fail())                                                   // check user input for an integer
        {
            cin.clear();                                                  // clear input stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n');          // clear input after spaces
            cout << "\nYou have entered a wrong option." << endl;         // output to user when condition true
            cout << endl;                                                
            cout << "Please enter a valid option: " << endl;              // output to user when condition true
            cin >> userInput;                                             // get uer input
        }
        if (!cin.fail())                                                  // user entered an integer
            break;
    }
    return userInput;                                                     // return user integer to previous location
}
void runProgram() {                                                       // function declaration/definition
    auto clk = make_shared <Clock>();                                     // smart pointer of object type Clock
    int hour{ clk->GetHour() };                                           // variable declaration initialized to hour value
    int min{ clk->GetMin() };                                             // variable declaration initialized to minute value
    int sec{ clk->GetSec() };                                             // variable declaration initialized to second value
    int option{ 0 };                                                      // variable declaration initialized to zero
    int userNum{ 0 };                                                     // variable declaration initialized to zero

    clk->GetTime(hour, min, sec);                                         // function call with arguments 
    ShowMenu();                                                           // function call

    while (option != 4) {                                                     // loop for user input
        userNum = CheckInput();                                               // fuction call for correct user input
        if (userNum == 1 || userNum == 2 || userNum == 3 || userNum == 4) {   // check user input conditions
            switch (userNum) {                                                // check conditions based on user input
            case 1:                                                           // user entered the number 1 condition
                clk->IncrementHour(hour, min, sec);                           // function call with arguments
                clk->GetTime(hour, min, sec);                                 // function call with arguments
                ShowMenu();                                                   // function call
                break;                                                        // ignore following conditions
            case 2:                                                           // user entered the number 2 condition
                clk->IncrementMin(hour, min, sec);                            // function call with arguments
                clk->GetTime(hour, min, sec);                                 // function call with arguments
                ShowMenu();                                                   // function call
                break;                                                        // ignore following conditions
            case 3:                                                           // user entered the number 3 condition
                clk->IncrementSec(hour, min, sec);                            // function call with arguments
                clk->GetTime(hour, min, sec);                                 // function call with arguments
                ShowMenu();                                                   // function call
                break;                                                        // ignore following conditions
            case 4:                                                           // user entered the number 4 condition
                cout << "You have chosen to exit the program." << endl;       // output to user
                cout << endl;                                                 // blank line
                cout << "Goodbye!!";                                          // output to user
                exit(0);                                                      // end loop
                break;
            default:                                                          // when user input not match previous conditions
                cout << "Please enter a valid selection: " << endl;        // output to user
                system("pause");                                              // pause program
                system("cls");                                                // clear console
                clk->GetTime(hour, min, sec);                                 // function call with arguments
                ShowMenu();                                                   // function call
                break;                                                        // exit switch refresh loop
            }
        }
    }
}

// Driver Code
int main() {                                                                  // program start
    runProgram();                                                             // function call
}