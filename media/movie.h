

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string.h>
#include "parentmedia.h"

using namespace std;

class movie : public media {
public: 
  
  movie(char* newname, int newyear, char*newdirector, int newduration, float newrating, int type);
 
    char* getdirector();
   
    int getduration();
    float getrating();
  ~movie();
 private:
   
    char* director;
    int duration;
    float rating;

};

#endif
