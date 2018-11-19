#ifndef NODE_H
#define NODE_H

#include <iostream>


class Node
{
 public:
  Node();
  ~Node();
  void setvalue(int newvalue);
  int getvalue();
  void setnext(Node* newnext);
  Node* getnext();

 private:
  int value;
  Node* next;




};
#endif
