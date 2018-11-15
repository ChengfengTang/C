#ifndef rooms_h
#define rooms_h
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class rooms
{
 public:
  rooms(char* newname, char* newdescription);

  char* getname();
  char* getdescription();

  void additem(item* item);
  void checkitem();
  void deleteitem(item* item);
  
  ~rooms();
  
 private:
  
  char* name;
  char* description;
  vector<item> itemsintheroom;


};

#endif
