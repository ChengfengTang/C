#include <iostream>
#include <string.h>
#include "movie.h"
#include "parentmedia.h"
using namespace std;

movie::movie(char* newname,int newyear,char* newdirector, int newduration, float newrating, int newtype):media(newname, newyear, newtype)
{
  

    
      director = newdirector;
      duration = newduration;
      rating = newrating;
      
 
}

char* movie::getdirector()
{
  return director;
}

int movie::getduration()
{
  return duration;
}
float movie::getrating()
{
  return rating;
}
movie::~movie()
{
 delete[] director; 
}
