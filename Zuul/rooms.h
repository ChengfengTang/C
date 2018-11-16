#ifndef rooms_h
#define rooms_h
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

enum class Direction {
  North,
  East,
  South,
  West
}

class rooms
{
 public:
  rooms(char* newname, char* newdescription);

  char* getname();
  char* getdescription();

  void additem(item* item);
  void listitems();
  item* deleteitem(item* item);

  
  
  ~rooms();
  
 private:
  
  char* name;
  char* description;
  vector<item> items;

  room* north = nullptr;
  room* east = nullptr;
  room* south = nullptr;
  room* west = nullptr;


};

#endif
