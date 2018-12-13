#include <iostream>
#include <string.h>
#include "room.h"
#include "item.h"
using namespace std;


room::room (char* newname, char* newdescription)
{ // create a room
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
/*

I am too lazy to comment all of them, just check the .h file, it tells you what
all the functions do


 */
void room::start()
{
  
  if (items.empty() == 1)
    {
      cout << "There is nothing in this room!" << endl;
    }
  else
    {
      cout << "Items in the room: " <<endl ;
  for(vector<item*>::iterator it = items.begin(); it != items.end(); ++it)
    {
      cout << (*it)->getname() << endl;
    }
    }
}
void room::additem(item* item)
{
  items.push_back(item);
}
void room::getdirections()
{
  cout << endl;
  cout << "Exits: " ;
  if(west != nullptr)
    {
      cout << "WEST ";
    }
  if(east != nullptr)
    {
      cout << "EAST ";
    }
  if(north != nullptr)
    {
      cout << "NORTH ";
    }
  if(south != nullptr)
    {
      cout << "SOUTH ";
     
    }
  cout << endl;
  
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
void room::deleteitem(char* name) // delete items based on their names
{
for(vector<item*>::iterator it = items.begin(); it != items.end(); ++it)
    {
      if (strcmp((*it)->getname(), name) == 0)
	{
	  cout << "You have picked up " << name << endl;
	  items.erase(it);
	}
	break;
    }
}

void room::setnorthexit(room* room)
{
  north = room;
}

void room::setsouthexit(room* room)
{
  south = room;
}
void room::setitself(room* room)
{
  itself = room;
}
void room::seteastexit(room* room)
{
  east = room;
}

void room::setwestexit(room* room)
{
  west = room;
}
room* room::gonorth()
{
  if (north != nullptr)
    {
      return north;
    }
  else
    {
      cout << "There isn't an exit in this direction!!!" << endl;
      return itself;
    }

}
room* room::gowest()
{
  if (west != nullptr)
    {
  return west;
    }
  else
    {
      cout << "There isn't an exit in this direction!!!" << endl;
      return itself;
    }

}
room* room::goeast()
{
  if (east != nullptr)
    {
  return east;
    }
  else
    {
      cout << "There isn't an exit in this direction!!!" << endl;
      return itself;
    }

}
room* room::gosouth()
{
  if (west != nullptr)
    {
  return south;
    }
  else
    {
      cout << "There isn't an exit in this direction!!!" << endl;
      return itself;
    }

}
room::~room() // desctructor
{
  delete []name;
  delete []description;
}
