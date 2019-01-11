#include <iostream>
#include <string.h>
#include "music.h"
#include "parentmedia.h"
using namespace std;

music::music(char* newname, int newyear, char* newpublisher, char* newartist, int newduration, int newtype) : media(newname,newyear,newtype)
{
 
  publisher = newpublisher;
  artist = newartist;
  duration = newduration;
}

char* music::getpublisher()
{
  return publisher;
}

char* music::getartist()
{
  return artist;
}

int music::getduration()
{
  return duration;
}
music::~music()
{
 delete[] publisher;
 delete[] artist;
}
