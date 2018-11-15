#include <iostream>
#include <string.h>
#include "rooms.h"

using namespace std;

rooms::rooms (char* newname, char* newdescription)
{
  name = newname;
  description = newdescription;


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
  itemsintheroom.putsh_back(item);
}
void rooms::checkitem()
{
  for (vector<item*> it = itemsintheroom.begin(); it != itemsintheroom.end(); ++it)
    {
      cout << (it*).name << endl;
    }
}
rooms::~rooms()
{
  delete []name;
  delete []description;
}
