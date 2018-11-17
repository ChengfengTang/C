#include <iostream>
#include "item.h"

using namespace std;

item::item(char* newname, int newroomnumber)
{
  name = newname;
  roomnumber =  newroomnumber;

}
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
