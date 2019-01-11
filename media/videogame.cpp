#include <iostream>
#include <string.h>
#include "videogame.h"
#include "parentmedia.h"
using namespace std;

videogame::videogame(char* newname,int newyear, char* newpublisher,  float newrating, int newtype) : media(newname,newyear,newtype)
{
   publisher = newpublisher;
  rating = newrating;
}


   
char* videogame::getpublisher()
{
  return publisher;
}
 

float videogame::getrating()
{
  return rating;
}
videogame::~videogame()
{
 delete[] publisher; 
}
 
