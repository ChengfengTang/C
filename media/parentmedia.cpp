#include <iostream>
#include <string.h>
#include "parentmedia.h"

using namespace std;

media::media(char* newname, int newyear, int newtype)
{
 name = newname;
 year = newyear;
 type = newtype;
}

char* media::getname()
{
  return name;
}
int media::getyear()
{
  return year;
}
int media::gettype()
{
  return type;
}
media::~media()
{
 delete[] name; 
}
