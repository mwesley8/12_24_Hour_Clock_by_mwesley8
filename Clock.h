#ifndef CLOCK_H                                                  // precessor derective
#define CLOCK_H                                                  // precessor derective

#include <iomanip>												 // precessor derectives
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

class Clock                                                       // create clock class
{
private:													      // access specifier
	int m_hour;                                                   // member variables
	int m_min;
	int m_sec;
public:                                                           // access specifier
	int GetHour();                                                // function declarations
	int GetMin();
	int GetSec();
	void IncrementHour(int& t_hour, int& t_min, int& t_sec); 
	void IncrementMin(int& t_hour, int& t_min, int& t_sec); 
	void IncrementSec(int& t_hour, int& t_min, int& t_sec);
	void GetTime(int& t_hour, int& t_min, int t_sec);      
};
#endif