#include <iostream>
#include <string.h>
#include "room.h"
#include "item.h"
using namespace std;


room::room (char* newname, char* newdescription)
{
  name = newname;
  description = newdescription;
}

char* room::getname()
{
  return name;

}
char* room::getdescription()
{
  return description;
}
void room::start()
{
  
  if (items.empty() == 1)
    {
      cout << "There is nothing in this room!" << endl;
    }
  else
    {
  cout << "Items in the room: " ;
  for(vector<item*>::iterator it = items.begin(); it != items.end(); ++it)
    {
      cout << (*it)->getname();
    }
    }
}
void room::additem(item* item)
{
  items.push_back(item);
}

bool room::checkitem()
{
  if (items.empty() == 1)
    {
      return false;
    }
  else
    {
      return true;
    }
}
item* room::itemsintheroom()
{
  for(vector<item*>::iterator it = items.begin(); it != items.end(); ++it)
    {
      return (*it);
    }
}
void room::deleteitem()
{
for(vector<item*>::iterator it = items.begin(); it != items.end(); ++it)
    {
      items.erase(it);
	
    }
}


room::~room()
{
  delete []name;
  delete []description;
}
