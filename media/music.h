#include <iostream>
#include <string.h>
#include "parentmedia.h"

#ifndef MATH_H
#define MATH_H

using namespace std;

class music : public media {

public:

  music(char* newname, int newyear, char* newpublisher, char* newartist, int newduration, int type);


  char* getpublisher();
  char* getartist();
  int getduration();
  ~music();

private:
  

  char* publisher;
  char* artist;
  int duration;

};

#endif
