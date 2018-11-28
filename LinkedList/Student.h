#ifndef STUDENT_H
#define STUDENT_H

#include<iostream>

class Student
{
 public:
  Student(char*, char*, int, float);
  ~Student();
  char* getfirstname();
  char* getlastname();
  int getid();
  float getgpa();


 private:
  char* firstname;
  char* lastname;
  int id;
  float gpa;

};
#endif
