//  Navarro, Julia
//  Class (CECS 282-02)
//  Prog 2 – myDate Object
//  Due 9/27/21
// 
//  I certify that this program is my own original work. I did not copy any part of this program from 
//  any other source. I further certify that I typed each and every line of code in this program.

#ifndef myDate_h
#define myDate_h
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

class myDate{
  private:
  
  int month;
  int day;
  int year;
  string monthArr[12] = {"January ", "February ", "March ", "April ", "May ", "June ", "July ", "August ", "September ", "October ", "November ", "December "};
  string monthStr;
  string weekArr[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  string weekStr;
  int daysInYear;
  int currDayOfYear;
  public:
  //default constructor. This will set the date to May 11, 1959
  myDate();

  //overloaded constructor. this will set the date to the values passed in through the parameter list represented by Month, Day, and Year
  myDate(int M, int D, int Y);

  //display the date in the following format (May 11, 1959) Do NOT print a linefeed after the date
  string display();

  //increment the date by N days
  void increaseDate(int N);

  //decrement the date by N days
  void decreaseDate(int N);

  //returnt he number of days between this date and the date D. If date D is a future date, the return value will be a positive int. If date D is in the past, the return value will be a negative int.
  int daysBetween(myDate D);

  //return the month in integer form
  int getMonth();

  //return the day of the month
  int getDay();

  //return the Year
  int getYear();

  //return the number of days since the current year began. Example Jan1 is 1, Feb 1 is 32
  int dayOfYear();

  //returns Monday, Tuesday, Wednesday, etc according othe day of the week. 
  string dayName();

  //returns true if the year is a leap year, returns false if the year is not a leap year
  bool leapYear(int y);

};

#endif