#ifndef room_H
#define room_H
#include <iostream>
#include <string.h>
#include <vector>
#include "item.h"
using namespace std;



class room
{
 public:
  room(char* newname, char* newdescription);

  char* getname();
  char* getdescription();

  void additem(item* item);
  bool checkitem();
  void deleteitem();
  void start();
  item* itemsintheroom();
  
  
  
  ~room ();
  
 private:
  
  char* name;
  char* description;
  vector<item*> items;

  room* north = nullptr;
  room* east = nullptr;
  room* south = nullptr;
  room* west = nullptr;


};

#endif
