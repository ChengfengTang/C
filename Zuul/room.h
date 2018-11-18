#ifndef room_H
#define room_H
#include <iostream>
#include <string.h>
#include <vector>
#include "item.h"
using namespace std;


// this is a room
class room
{
 public:
  room(char* newname, char* newdescription);
  
  char* getname(); // tells u the name
  char* getdescription(); // tells u the description

  void additem(item* item); // add items into the room
  bool checkitem(); // see if there is items in the room, return true false
  void deleteitem(char* name); // delete an item based on its name
  // so don't name two items with the same name ty
  void start();//tells what items are tehre in the room
  item* itemsintheroom(); // returns items in the room

  void setnorthexit(room* room); //  set the exit
  room* gonorth(); // just go that direction

  void seteastexit(room* room);
  room* goeast();

  void setwestexit(room* room);
  room* gowest();

  void setsouthexit(room* room);
  room* gosouth();
  
  void setitself(room* room);
  
  ~room (); // destructor
  
 private:
  
  char* name;
  char* description;
  vector<item*> items;
  
  room* north = nullptr; // pointer that points to certain rooms which wil be set at the beginning of the game
  room* east = nullptr;
  room* south = nullptr;
  room* west = nullptr;
  room* itself = nullptr;


};

#endif
