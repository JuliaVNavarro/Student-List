#ifndef StudentList_h
#define StudentList_h
#include <iostream> 
#include <stdio.h>
#include <string>
#include "myDate.h"
using namespace std;



class StudentList{

  public:
    
    void sortName();
    void sortID();
    void sortGrade();
    void sortBirthday();
    void sortHomeTown();
}; 
#endif