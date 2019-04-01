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
  void setParent(Node* newParent);
  void setBlack();
  void setRed();
  
  int getColor();
  Node* getParent();
  Node* getLeft();
  Node* getRight();
  int getValue();
  
 private:
  int  value;
  int color;
  Node* parent;
  Node* left;
  Node* right;

};
#endif
