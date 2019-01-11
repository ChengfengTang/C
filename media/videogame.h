
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include <iostream>
#include <string.h>
#include "parentmedia.h"

using namespace std;

class videogame : public media {

 public: 
  videogame(char* newname, int newyear, char* newpublisher, float newrating, int type);


   char* getpublisher();
 float getrating();
 ~videogame();
 


    private:

  char* publisher;
  
  float rating;

};

#endif
