#ifndef item_H
#define item_H
#include <iostream>
using namespace std;

class item
{
 public:
  item(char* name, int roomnumber);
  char* getname(); // tells u the name of the room
  int getroomnumber();// tells u what room it belongs
  ~item(); // destructor
 private:

  char* name;
  int roomnumber;
};

#endif
