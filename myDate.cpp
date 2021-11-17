//  Navarro, Julia
//  Class (CECS 282-02)
//  Prog 2 – myDate Object
//  Due 9/27/21
// 
//  I certify that this program is my own original work. I did not copy any part of this program from 
//  any other source. I further certify that I typed each and every line of code in this program.

#include "myDate.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//converts a Gregorian date t oa Julian date
int Greg2Julian(int month, int day, int year){
  int J = month;
  int K = day;
  int I = year;

  int JD = K - 32075 + 1461 * (I + 4800 + (J - 14)/12)/4 + 367 * (J - 2 - (J - 14)/12 * 12)/12 - 3 * ((I + 4900 + (J - 14)/12)/100)/4;

  return JD;
}

//converts a Julian date to a Gregorian date
void Julian2Greg(int JD, int & month, int & day, int & year){
  
  int L = JD + 68569;
  int N = 4 * L/146097;
  L = L - (146097 * N + 3)/4;
  int I = 4000 * (L + 1)/1461001;
  L = L - 1461 * I/4 + 31;
  int J = 80 * L/2447;
  int K = L - 2447 * J/80;
  L = J / 11;
  J = J + 2 - 12 * L;
  I = 100 * (N - 49) + I + L;

  year = I;
  month = J;
  day = K;


}

//default constructor sets the date to May 11, 1959, the day of the week to Monday, the total days in the year to 365, and the current day of the year is 131
myDate::myDate(){
  month = 5;
  day = 11;
  year = 1959;
  monthStr = monthArr[month - 1];
  weekStr = weekArr[1];  
  daysInYear = 365;
  currDayOfYear = 131;
}

//constructor for date entered by user
myDate::myDate(int M, int D, int Y){
  //if the month is invalid, the date will be the default date: May 11, 1959
  if(M > 12 || M < 1){
    month = 5;
    day = 11;
    year = 1959;
    monthStr = monthArr[month - 1];
    weekStr = weekArr[1];  
    daysInYear = 365;
    currDayOfYear = 131;
  }
  //if the day is invalid, the date will be the default date: May 11, 1959
  else if(D > 31 || D < 1){
    month = 5;
    day = 11;
    year = 1959;
    monthStr = monthArr[month - 1];
    weekStr = weekArr[1];  
    daysInYear = 365;
    currDayOfYear = 131;
  }
  //if the day in February is invalid, the date will be the default date: May 11, 1959
  else if(D > 29 && M == 2){
    month = 5;
    day = 11;
    year = 1959;
    monthStr = monthArr[month - 1];
    weekStr = weekArr[1];  
    daysInYear = 365;
    currDayOfYear = 131;
  }
  //if the day in February is invalid, the date will be the default date: May 11, 1959
  else if(D > 28 && M == 2){
    if(leapYear(Y) == false){
      month = 5;
      day = 11;
      year = 1959;
      monthStr = monthArr[month - 1];
      weekStr = weekArr[1];  
      daysInYear = 365;
      currDayOfYear = 131;
    }
  }
  //if the day in April is invalid, the date will be the default date: May 11, 1959
  else if( D > 30 && M == 4){
    month = 5;
    day = 11;
    year = 1959;
    monthStr = monthArr[month - 1];
    weekStr = weekArr[1];  
    daysInYear = 365;
    currDayOfYear = 131;
  }
  //if the day in June is invalid, the date will be the default date: May 11, 1959
  else if(D > 30 && M == 6){
    month = 5;
    day = 11;
    year = 1959;
    monthStr = monthArr[month - 1];
    weekStr = weekArr[1];  
    daysInYear = 365;
    currDayOfYear = 131;
  }
  //if the day in September is invalid, the date will be the default date: May 11, 1959
  else if(D > 30 && M == 9){
    month = 5;
    day = 11;
    year = 1959;
    monthStr = monthArr[month - 1];
    weekStr = weekArr[1];  
    daysInYear = 365;
    currDayOfYear = 131;
  }
  //if the day in November is invalid, the date will be the default date: May 11, 1959
  else if(D > 30 && M == 11){
    month = 5;
    day = 11;
    year = 1959;
    monthStr = monthArr[month - 1];
    weekStr = weekArr[1];  
    daysInYear = 365;
    currDayOfYear = 131;
  }
  //otherwise, date will be constructed depending on user input
  else{
    month = M;
    day = D;
    year = Y;
    monthStr = monthArr[M - 1];
    leapYear(year);
    //get initial day of year
    if(leapYear(year) == false){
      //January ----> day of year ranges between 1 - 31
      if(month == 1){
        currDayOfYear = day;
      }
      //February ----> day of year ranges between 32 - 59 and is added by 31
      else if(month == 2){
        currDayOfYear = day + 31;
      }
      //March ----> day of year ranges between 60 - 90 and is added by 59
      else if(month == 3){
        currDayOfYear = day + 59;
      }
      //April ----> day of year ranges between 91 - 120 and is added by 90
      else if(month == 4){
        currDayOfYear = day + 90;
      }
      //May ----> day of year ranges between 121 - 151 and is added by 120
      else if(month == 5){
        currDayOfYear = day + 120;
      }
      //June ----> day of year ranges between 152 - 181 and is added by 151
      else if(month == 6){
        currDayOfYear = day + 151;
      }
      //July ----> day of year ranges between 182 - 212 and is added by 181
      else if(month == 7){
        currDayOfYear = day + 181;
      }
      //August ----> day of year ranges between 213 - 243 and is added by 212
      else if(month == 8){
        currDayOfYear = day + 212;
      }
      //September ----> day of year ranges between 244 - 273 and is added by 243
      else if(month == 9){
        currDayOfYear = day + 243;
      }
      //October ----> day of year ranges between 274 - 304 and is added by 273
      else if(month == 10){
        currDayOfYear = day + 273;
      }
      //November ----> day of year ranges between 305 - 334 and is added by 304
      else if(month ==11){
        currDayOfYear = day + 304;
      }
      //December ----> day of year ranges between 335 - 365 and is added by 334
      else if(month == 12){
        currDayOfYear = day + 334;
      }
    }
    else if(leapYear(year) == true){
      //January ----> day of year ranges between 1 - 31
      if(month == 1){
        currDayOfYear = day;
      }
      //February ----> day of year ranges between 32 - 60 and is added by 31
      else if(month == 2){
        currDayOfYear = day + 31;
      }
      //March ----> day of year ranges between 61 - 91 and is added by 60
      else if(month == 3){
        currDayOfYear = day + 60;
      }
      //April ----> day of year ranges between 92 - 121 and is added by 91
      else if(month == 4){
        currDayOfYear = day + 91;
      }
      //May ----> day of year ranges between 122 - 152 and is added by 121
      else if(month == 5){
        currDayOfYear = day + 121;
      }
      //June ----> day of year ranges between 153 - 182 and is added by 152
      else if(month == 6){
        currDayOfYear = day + 152;
      }
      //July ----> day of year ranges between 183 - 213 and is added by 182
      else if(month == 7){
        currDayOfYear = day + 182;
      }
      //August ----> day of year ranges between 214 - 244 and is added by 213
      else if(month == 8){
        currDayOfYear = day + 213;
      }
      //September ----> day of year ranges between 245 - 274 and is added by 244
      else if(month == 9){
        currDayOfYear = day + 244;
      }
      //October ----> day of year ranges between 275 - 305 and is added by 274
      else if(month == 10){
        currDayOfYear = day + 274;
      }
      //November ----> day of year ranges between 306 - 335 and is added by 305
      else if(month ==11){
        currDayOfYear = day + 305;
      }
      //December ----> day of year ranges between 336 - 366 and is added by 335
      else if(month == 12){
        currDayOfYear = day + 335;
      }
    }
  }
}

string myDate::display(){
  //find the month's string
  monthStr = monthArr[month - 1];
  string bday = monthStr + to_string(day) + ", " + to_string(year);
  //display the month string, the day off the month, and the year
  return bday;
  
}

void myDate::increaseDate(int N){
  //generate a temp variable to keep track of the days
  int tempDay;
  //set the temp day to the new amount of days to the current day of the year
  tempDay = N + currDayOfYear;
  //while the temp day is greater than or equal to 366, subtract 1 years worth of days (depending on leap years)
  while(tempDay >= 366){
    //if the current year is a leap year....
    if(leapYear(year) == true){
      //make sure that the temp day is not the last day of a leap year. If it is, break the while loop, since you are on Dec. 31st of that year.
      if(tempDay == 366){
        break;
      }
      //otherwise, subtract & set the temp day by 366 and add & set the current year by 1
      else{
        tempDay -= 366;
        year += 1;
      }
    }
    //If it is not a leap year, then subtract & set the temp day by 365 days and add and set the current year by 1
    else if(leapYear(year) == false){
      tempDay -= 365;
      year += 1;
    }
  }
  //set the current day of the year to the temp day
  currDayOfYear = tempDay;
  leapYear(year); //check for leap year
  getMonth(); //set month to the correct month
  getDay(); //set day to the correct day
}

void myDate::decreaseDate(int N){
  //generate variable to keep track of what day we are on during the year
  int tempDay;
  //if the decreasing amount is less than or equal to the current day of the year, subract the decreasing amount from the current day of the year and set it to the temp day
  if(N <= currDayOfYear){
    tempDay = currDayOfYear - N;
    //if the temp day is 0, that means you are at Dec 31st of the previous year
    if(tempDay == 0){
      year -= 1;
      //if that previous year is a leap year, Dec 31st is the 366th day of the year
      if(leapYear(year) == true){
        currDayOfYear = 366;
      }
      //otherwise, it is the 365th day of the year
      else{
        currDayOfYear = 365;
      }
    }
    //if the temp day is not equal to 0, then simply set the curr day of the year to the temp day
    else{
      currDayOfYear = tempDay;
    }
  }
  //if the decreasing amount is more than the the current day of the year find the year and day of the year you should be in
  else if(N > currDayOfYear){
    //set the date to December 31st of the previous year
    tempDay = N - currDayOfYear;
    year -= 1; //keep track of the year you are in
    //while the temporary day is greater than 365, you will continue to subtract a year's worth of days.
    while(tempDay > 365){
      //if the year you are in is a leap year, subtract 366 days
      if(leapYear(year) == true){
        tempDay -= 366;
      }
      //if the year you are in is not a leap year, subract 365 days
      else if(leapYear(year) == false){
        tempDay -= 365;
      }
      //everytime 366 or 365 days are subtracted, you must set the year back 1.
      year -= 1;
    }
    //once the tempDays is less than 366 days you will find the day of the year starting from December 31st and subracting what is left from the temp day (aka the rest of the decreasing amount)
    if(leapYear(year) == true){
      currDayOfYear = 366 - tempDay;
    }
    else if(leapYear(year) == false){
      //if the year is not a leap year, and the temp day still has a year's worth of days to deduct, deduct 1 year
      if(tempDay == 365){
        year -= 1;
        //if that new deducted year is a leap year, set the curr day of the year to 366
        if(leapYear(year) == true){
          currDayOfYear = 366;
        }
        //otherwise, the curr day fo the year is 365
        else{
          currDayOfYear = 365;
        }
      }
      //if the temp day does not have at least a years worth of days left to deduct, simply subtract 365 days from the tep day and set it to the curr day of the year
      else{
        currDayOfYear = 365 - tempDay;
      }
    }
  }
  leapYear(year);//check the leap year
  getMonth();//get the month
  getDay();//get the day of the month
}

int myDate::daysBetween(myDate D){
  //convert gregorian date to julian date
  int Julian = Greg2Julian(month, day, year);
  //convert d's date to julian date as well and subract it form the original julian date to get the toal days between both dates
  Julian = Greg2Julian(D.getMonth(), D.getDay(), D.getYear()) - Julian;
  return Julian;

}

int myDate::getMonth(){
  //if the year is not a leap year find the month based off the day of the year
  if(leapYear(year) == false){
    //January ----> 1 - 31
    if(dayOfYear() >=1 && dayOfYear() <= 31){
      month = 1;
    }
    //February ----> 32 - 59
    else if(dayOfYear() >= 32 && dayOfYear() <= 59){
      month = 2;
    }
    //March ----> 60 - 90
    else if(dayOfYear() >= 60 && dayOfYear() <= 90){
      month = 3;
    }
    //April ----> 91 - 120
    else if(dayOfYear() >= 91 && dayOfYear() <= 120){
      month = 4;
    }
    //May ----> 121 - 151
    else if(dayOfYear() >= 121 && dayOfYear() <= 151){
      month = 5;
    }
    //June ----> 152 - 181
    else if(dayOfYear() >= 152 && dayOfYear() <= 181){
      month = 6;
    }
    //July ----> 182 - 212
    else if(dayOfYear() >= 182 && dayOfYear() <= 212){
      month = 7;
    }
    //August ----> 213 - 243
    else if(dayOfYear() >= 213 && dayOfYear() <= 243){
      month = 8;
    }
    //September ----> 244 - 273
    else if(dayOfYear() >= 244 && dayOfYear() <= 273){
      month = 9;
    }
    //October ----> 274 - 304
    else if(dayOfYear() >= 274 && dayOfYear() <= 304){
      month = 10;
    }
    //November ----> 305 - 334
    else if(dayOfYear() >= 305 && dayOfYear() <= 334){
      month = 11;
    }
    //December ----> 335 - 365
    else if(dayOfYear() >= 335 && dayOfYear() <= 365){
      month = 12;
    }
  }
  else if(leapYear(year) == true){
    //January ----> 1 - 31
    if(dayOfYear() >=1 && dayOfYear() <= 31){
      month = 1;
    }
    //February ----> 32 - 60
    else if(dayOfYear() >= 32 && dayOfYear() <= 60){
      month = 2;
    }
    //March ----> 61 - 91
    else if(dayOfYear() >= 61 && dayOfYear() <= 91){
      month = 3;
    }
    //April ----> 92 - 121
    else if(dayOfYear() >= 92 && dayOfYear() <= 121){
      month = 4;
    }
    //May ----> 122 - 152
    else if(dayOfYear() >= 122 && dayOfYear() <= 152){
      month = 5;
    }
    //June ----> 153 - 182
    else if(dayOfYear() >= 153 && dayOfYear() <= 182){
      month = 6;
    }
    //July ----> 183 - 213
    else if(dayOfYear() >= 183 && dayOfYear() <= 213){
      month = 7;
    }
    //August ----> 214 - 244
    else if(dayOfYear() >= 214 && dayOfYear() <= 244){
      month = 8;
    }
    //September ----> 245 - 274
    else if(dayOfYear() >= 245 && dayOfYear() <= 274){
      month = 9;
    }
    //October ----> 275 - 305
    else if(dayOfYear() >= 275 && dayOfYear() <= 305){
      month = 10;
    }
    //November ----> 306 - 335
    else if(dayOfYear() >= 306 && dayOfYear() <= 335){
      month = 11;
    }
    //December ----> 335 - 365
    else if(dayOfYear() >= 336 && dayOfYear() <= 366){
      month = 12;
    }
  }
  //return the month in integer form
  return month;
}

//MONTH MUST BE FOUND BEFORE CALLING THIS METHOD
int myDate::getDay(){
  //if the year is not a leap year, then find the day according to the day of the year
  if(leapYear(year) == false){
    //January ----> the day of the year should match the numbers 1 - 31
    if(month == 1){
      day = dayOfYear();
    }
    //February ----> day of year ranges between 32 - 59 and is subtracted by 31
    else if(month == 2){
      day = dayOfYear() - 31;
    }
    //March ----> day of year ranges between 60 - 90 and is subtracted by 59
    else if(month == 3){
      day = dayOfYear() - 59;
    }
    //April ----> day of year ranges between 91 - 120 and is subtracted by 90
    else if(month == 4){
      day = dayOfYear() - 90;
    }
    //May ----> day of year ranges between 121 - 151 and is subtracted by 120
    else if(month == 5){
      day = dayOfYear() - 120;
    }
    //June ----> day of year ranges between 152 - 181 and is subtracted by 151
    else if(month == 6){
      day = dayOfYear() - 151;
    }
    //July ----> day of year ranges between 182 - 212 and is subtracted by 181
    else if(month == 7){
      day = dayOfYear() - 181;
    }
    //August ----> day of year ranges between 213 - 243 and is subtracted by 212
    else if(month == 8){
      day = dayOfYear() - 212;
    }
    //September ----> day of year ranges between 244 - 273 and is subtracted by 243
    else if(month == 9){
      day = dayOfYear() - 243;
    }
    //October ----> day of year ranges between 274 - 304 and is subtracted by 273
    else if(month == 10){
      day = dayOfYear() - 273;
    }
    //November ----> day of year ranges between 305 - 334 and is subtracted by 304
    else if(month == 11){
      day = dayOfYear() - 304;
    }
    //December ----> day of year ranges between 335 - 365 and is subtracted by 334
    else if(month == 12){
      day = dayOfYear() - 334;
    }
  }
  else if(leapYear(year) == true){
    //January ----> the day of the year should match the numbers 1 - 31
    if(month == 1){
      day = dayOfYear();
    }
    //February ----> day of year ranges between 32 - 60 and is subtracted by 31
    else if(month == 2){
      day = dayOfYear() - 31;
    }
    //March ----> day of year ranges between 61 - 91 and is subtracted by 60
    else if(month == 3){
      day = dayOfYear() - 60;
    }
    //April ----> day of year ranges between 92 - 121 and is subtracted by 91
    else if(month == 4){
      day = dayOfYear() - 91;
    }
    //May ----> day of year ranges between 122 - 152 and is subtracted by 121
    else if(month == 5){
      day = dayOfYear() - 121;
    }
    //June ----> day of year ranges between 153 - 182 and is subtracted by 152
    else if(month == 6){
      day = dayOfYear() - 152;
    }
    //July ----> day of year ranges between 183 - 213 and is subtracted by 182
    else if(month == 7){
      day = dayOfYear() - 182;
    }
    //August ----> day of year ranges between 214 - 244 and is subtracted by 213
    else if(month == 8){
      day = dayOfYear() - 213;
    }
    //September ----> day of year ranges between 245 - 274 and is subtracted by 244
    else if(month == 9){
      day = dayOfYear() - 244;
    }
    //October ----> day of year ranges between 275 - 305 and is subtracted by 274
    else if(month == 10){
      day = dayOfYear() - 274;
    }
    //November ----> day of year ranges between 306 - 335 and is subtracted by 305
    else if(month == 11){
      day = dayOfYear() - 305;
    }
    //December ----> day of year ranges between 336 - 366 and is subtracted by 335
    else if(month == 12){
      day = dayOfYear() - 335;
    }
  }
  //return the day of the month
  return day;
}

int myDate::getYear(){
  //return the year
  return year;
}

int myDate::dayOfYear(){
  //return the number of days since the current year began
  return currDayOfYear;
}

string myDate::dayName(){
  int track;
  //create a default date (because we know that this is on a Monday)
  myDate d;
  //initialize the amount of days between the current day of the year and the default date
  int week = daysBetween(d);
  //if the days between comes out negative, then the date is ahead of the default date (starting on a monday)
  if(week < 0){
    //convert the days between to a positive number then use MOD to determine how many days after 7 even days have occured after the default date
    week = week *(-1);
    week = week%7;
    track = week;
    week = 1;
    //count foward the days left until you reach the correct day of the week
    while(track != 0 ){
      week += 1;
      track -= 1;
      if(week == 7){
        week = 0;
      }
    }
  }
  //if the number came out positive then the date is before the default date, where we will count backwards until we reachthe correct day of the week
  else if(week > 0){
    week = week%7;
    track = week;
    week = 1;
    while(track != 0){
      week -= 1;
      track -= 1;
      if(week == -1){
        week = 6;
      }
    }
  }
  //if the MOD turns out to be an even amount of 7 days and no remaining days, then the day of the week is Monday
  else{
    week = 1;
  }
  //set the string to the index that holds the correct day of the week
  weekStr = weekArr[week];
  //return the string with the day of the week
  return weekStr;
}

bool myDate::leapYear(int y){
  bool leap = false;
  //if the year is not divisible by 400 then it is not a leap century 
  if(y%100 > 0){
    //it it is not a leap century and the year is not divisible by 4 then it is not a leap year - thus a total of 365 days in the year
    if(y%4 > 0){
      daysInYear = 365;
      leap = false;
    }
    //if it is not a leap century but the year IS divisible by 4 then it is a leap year - thus a total of 366 days in the year
    else if(y%4 == 0){
      daysInYear = 366;
      leap = true;
    }
  }
  //if the year IS divisible by 400, then it is a leap century - thus 366 days in the year
  else if(y%100 == 0){
    if(y%400 > 0){
      daysInYear = 365;
      leap = false;
    }
    else if(y%400 == 0){
      daysInYear = 366;
      leap = true;
    }
  }
  return leap;
}
