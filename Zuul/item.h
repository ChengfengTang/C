#ifndef item_H
#define item_H
#include <iostream>
using namespace std;

class item
{
 public:
  item(char* name, int roomnumber);
  char* getname();
  int getroomnumber();
  ~item();
 private:

  char* name;
  int roomnumber;
};

#endif
