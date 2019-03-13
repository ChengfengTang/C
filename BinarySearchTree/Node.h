#ifndef NODE_H
#define NODE_H

#include<iostream>

class Node
{
 public:
  Node();
  ~Node();
  void setValue(int newValue);
  void setLeft(Node* newLeft);
  void setRight(Node* newRight);
  Node* getLeft();
  Node* getRight();
  int getValue();
  
 private:
  int  value;
  Node* left;
  Node* right;

};
#endif
