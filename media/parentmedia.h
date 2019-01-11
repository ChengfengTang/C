
#ifndef PARENTMEDIA_H
#define PARENTMEDIA_H

#include <iostream>
#include <string.h>

using namespace std;

class media {
 public:

  media(char* newname, int newyear, int newtype);

  char* getname();
  int getyear();
 ~media();
  int gettype();
 private:
  int type;
  char* name;
  int year;
};

#endif 
    
