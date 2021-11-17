#include <iostream> 
#include <stdio.h>
#include <string>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <cstring>
#include "myDate.h"
#include "StudentList.h"
using namespace std;

//Student structure that will contain a student's name, ID #, grade, birthdate, and their hometown
struct Student{
  char name[15]; //name must consist of 15 characters
  int ID;
  char grade;
  myDate birthday; //birthday is generated through myDate class
  string hometown;
};

//convert Gregorian date to Julian date
int Greg2Julian2(int month, int day, int year){
  int J = month;
  int K = day;
  int I = year;

  int JD = K - 32075 + 1461 * (I + 4800 + (J - 14)/12)/4 + 367 * (J - 2 - (J - 14)/12 * 12)/12 - 3 * ((I + 4900 + (J - 14)/12)/100)/4;

  return JD;
}

//Convert Julian date to Gregorian date
void Julian2Greg2(int JD, int & month, int & day, int & year){
  
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

//create a pointer that creates a student and all of their information
//Parameters: student's name, ID #, grade, birthday, and hometown
//returns: Student pointer
struct Student *createStudent(string n, int id, char g, myDate bday, string h){
  struct Student * s = new Student;
  strcpy(s->name, n.c_str()); //convert the string name to a char array
  s->ID = id;
  s->grade = g;
  s->birthday = bday;
  s->hometown = h;
  
  return s;
}

//displays the Student structure array of pointers
//parameters: the pointer array and the size of the array
//return: nothing
void display(Student ** myClass, int arrsize){
  cout << "\n\nName" << setw(28) << "Student ID" << setw(15) << "Grade" << setw(15) << "Birthday" << setw(23) << "Hometown" << endl;
  cout << "____" << setw(28) << "__________" << setw(15) << "_____" << setw(15) << "________" << setw(23) << "________" << endl;
  for(int i = 0; i < arrsize; i++){
    int count1 = 0;
    int temp1 = 0;
    int temp2 = 0;
    for(int j = 0; j < sizeof(myClass[i]->name); j++){
      if(myClass[i]->name[j] != '\0'){
        count1 += 1;
      }
    }
    int shift1 = 10 + (15 - count1);
    int shift2 = myClass[i]->birthday.display().size() + 11;
    for(int k = 0; k < 9; k++){
      if(myClass[k]->birthday.display().size() > temp1){
        temp1 = myClass[k]->birthday.display().size();
      }
      if(myClass[k]->hometown.size() > temp2){
        temp2 = myClass[k]->hometown.size();
      }
    }
    int shift3 = (temp1 - myClass[i]->birthday.display().size()) + 18 - (temp2 - myClass[i]->hometown.size());
    cout << myClass[i]->name << setw(shift1) << myClass[i]->ID << setw(18) << myClass[i]->grade << setw(shift2) << myClass[i]->birthday.display() << setw(shift3) << myClass[i]->hometown << endl;
  }
}

//sorts the Student structure array of pointers by the student's name
//parameters: the pointer array and the size of the array
//return: nothing
void sortName(Student ** myClass, int arrsize){
  for(int i = 1; i < arrsize; i++){
    Student *temp[1];
    int j = i - 1;
    temp[0] = myClass[i];
    do{
      for(int k = 0; k < 15;){
      int ascii1 = int(myClass[j]->name[k]);
      int ascii2 = int(temp[0]->name[k]);
      if(ascii1 > ascii2){
        myClass[j+1] = myClass[j];
        myClass[j] = temp[0];
        k = 0;
        break;
      }
      else if(ascii1 < ascii2){
          k = 0;
          break;
      }
      else if(ascii1 ==  ascii2){
        k+=1;
      }
    }
    j = j-1;
  }while(j >= 0);
  }
}

//sorts the Student structure array of pointers by the student's ID #
//parameters: the pointer array and the size of the array
//return: nothing
void sortID(Student ** myClass, int arrsize){
  for(int i = 1; i < arrsize; i++){
    Student *temp[1];
    int j = i - 1;
    temp[0] = myClass[i];
    do{
      int id1 = myClass[j]->ID;
      int id2 = temp[0]->ID;
      if(id1 > id2){
        myClass[j+1] = myClass[j];
        myClass[j] = temp[0];
      }
      j = j - 1;
    }while(j >= 0);
  }
}

//sorts the Student structure array of pointers by the student's grade
//parameters: the pointer array and the size of the array
//return: nothing
void sortGrade(Student ** myClass, int arrsize){
  for(int i = 1; i < arrsize; i++){
    Student *temp[1];
    int j = i - 1;
    temp[0] = myClass[i];
    do{
      int ascii1 = int(myClass[j]->grade);
      int ascii2 = int(temp[0]->grade);
      if(ascii1 > ascii2){
        myClass[j+1] = myClass[j];
        myClass[j] = temp[0];
      }
      j = j - 1;
    }while(j >= 0);
  }
}

//sorts the Student structure array of pointers by the student's birthday
//parameters: the pointer array and the size of the array
//return: nothing
void sortBirthday(Student ** myClass, int arrsize){
  for(int i = 1; i < arrsize; i++){
    Student *temp[1];
    int j = i - 1;
    temp[0] = myClass[i];
    do{
      int JD1 = Greg2Julian2(myClass[j]->birthday.getMonth(), myClass[j]->birthday.getDay(), myClass[j]->birthday.getYear());
      int JD2 = Greg2Julian2(temp[0]->birthday.getMonth(), temp[0]->birthday.getDay(), temp[0]->birthday.getYear());
      if(JD1 > JD2){
        myClass[j+1] = myClass[j];
        myClass[j] = temp[0];
      }
      j = j - 1;
    }while(j >= 0);
  }
}

//sorts the Student structure array of pointers by the student's hometown
//parameters: the pointer array and the size of the array
//return: nothing
void sortHometown(Student ** myClass, int arrsize){
  for(int i = 1; i < arrsize; i++){
    Student *temp[1];
    int j = i - 1;
    temp[0] = myClass[i];
    do{
      for(int k = 0; k < 30;){
      int ascii1 = int(myClass[j]->hometown[k]);
      int ascii2 = int(temp[0]->hometown[k]);
      if(ascii1 > ascii2){
        myClass[j+1] = myClass[j];
        myClass[j] = temp[0];
        k = 0;
        break;
      }
      else if(ascii1 < ascii2){
          k = 0;
          break;
      }
      else if(ascii1 ==  ascii2){
        k+=1;
      }
    }
    j = j-1;
  }while(j >= 0);
  }
}

int main() {
  Student *myClass[10];
  srand(time(0));
  int id = rand() % 900 + 100;
  int bday = rand() % 9132 + 2451545;
  int month = 1;
  int day = 1;
  int year = 2000;
  Julian2Greg2(bday, month, day, year);
  myDate birth1(month, day, year);
  
  myClass[0] = createStudent("Julia Navarro", id, 'A', birth1, "Long Beach");

  id = rand() % 900 + 100;
  bday = rand() % 9132 + 2451545;
  Julian2Greg2(bday, month, day, year);
  myDate birth2(month, day, year);
  myClass[1] = createStudent("Brian Valdez", id, 'D', birth2, "Anchorage");

  id = rand() % 900 + 100;
  bday = rand() % 9132 + 2451545;
  Julian2Greg2(bday, month, day, year);
  myDate birth3(month, day, year);
  myClass[2] = createStudent("Lily Diaz", id, 'C', birth3, "Long Beach");

  id = rand() % 900 + 100;
  bday = rand() % 9132 + 2451545;
  Julian2Greg2(bday, month, day, year);
  myDate birth4(month, day, year);
  myClass[3] = createStudent("Emma Diaz", id, 'B', birth4, "Long Beach");

  id = rand() % 900 + 100;
  bday = rand() % 9132 + 2451545;
  Julian2Greg2(bday, month, day, year);
  myDate birth5(month, day, year);
  myClass[4] = createStudent("Karla Chavez", id, 'C', birth5, "Long Beach");

  id = rand() % 900 + 100;
  bday = rand() % 9132 + 2451545;
  Julian2Greg2(bday, month, day, year);
  myDate birth6(month, day, year);
  myClass[5] = createStudent("Luis Diaz", id, 'B', birth6, "Long Beach");

  id = rand() % 900 + 100;
  bday = rand() % 9132 + 2451545;
  Julian2Greg2(bday, month, day, year);
  myDate birth7(month, day, year);
  myClass[6] = createStudent("Zach Brown", id, 'C', birth7, "Palos Verdes");

  id = rand() % 900 + 100;
  bday = rand() % 9132 + 2451545;
  Julian2Greg2(bday, month, day, year);
  myDate birth8(month, day, year);
  myClass[7] = createStudent("Carina Sandoval", id, 'A', birth8, "Fullerton");

  id = rand() % 900 + 100;
  bday = rand() % 9132 + 2451545;
  Julian2Greg2(bday, month, day, year);
  myDate birth9(month, day, year);
  myClass[8] = createStudent("Kevin Valdez", id, 'B', birth9, "Whittier");

  id = rand() % 900 + 100;
  bday = rand() % 9132 + 2451545;
  Julian2Greg2(bday, month, day, year);
  myDate birth10(month, day, year);
  myClass[9] = createStudent("Chris Nguyen", id, 'B', birth10, "Garden Grove");

  int choice;
  do{
    cout << "\n\n1) Display list sorted by Name \n2) Display list sorted by Student ID \n3) Display list sorted by Grade \n4) Display list sorted by Birthday \n5) Display list sorted by Hometown \n6) Exit" << endl;
    cin >> choice;
    if(choice == 1){
      sortName(myClass, 10);
      display(myClass, 10);
    }
    else if(choice == 2){
      sortID(myClass, 10);
      display(myClass, 10);
    }
    else if(choice == 3){
      sortGrade(myClass, 10);
      display(myClass, 10);
    }
    else if(choice == 4){
      sortBirthday(myClass, 10);
      display(myClass, 10);
    }
    else if(choice == 5){
      sortHometown(myClass, 10);
      display(myClass, 10);
    }
    else if(choice > 6 || choice < 1){
      cout << "\n\nPlease enter a valid number that is on the menu." << endl;
    }
  }while(choice != 6);
}