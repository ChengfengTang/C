#include <iostream>
#include "item.h"

using namespace std;

item::item(char* newname, int newroomnumber)
{// create items
  name = newname;
  roomnumber =  newroomnumber;

}
//check .h file, too lazy :
char* item::getname()
{
  return name;
}
int item::getroomnumber()
{
  return roomnumber;
}
item::~item()
{
  delete []name;
}
