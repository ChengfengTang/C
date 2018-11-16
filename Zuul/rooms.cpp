#include <iostream>
#include <string.h>
#include "rooms.h"

using namespace std;

#define createRoom(number, description) rooms* room##number = new rooms(#number, description);


rooms::rooms (char* newname, char* newdescription) : name(newname), description(newdescription)
{

}

char* rooms::getname()
{
  return name;

}
char* rooms::getdescription()
{
  return description;
}

void rooms::additem(item* item)
{
  itemsintheroom.push_back(item);
}
void rooms::checkitem()
{
  for (vector<item*> it = itemsintheroom.begin(); it != itemsintheroom.end(); ++it)
    {
      cout << (it*).name << endl;
    }
}

item* rooms::deleteitem(char* name) {
  
}


rooms::~rooms()
{
  delete []name;
  delete []description;
}
