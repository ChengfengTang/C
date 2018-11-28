#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(char* newfirstname, char* newlastname, int newid, float newgpa)
{
  firstname = newfirstname;
  lastname = newlastname;
  id = newid;
 gpa  = newgpa;
}
Student::~Student()
{
  delete[] firstname;
  delete[] lastname;
}

char* Student::getfirstname()
{
  return firstname;
}
char* Student::getlastname()
{
  return lastname;
}
int Student::getid()
{
  return id;
}
float Student::getgpa()
{
  return gpa;
}
