#ifndef NODE_H
#define NODE_H

#include<iostream>

class Node
{
 public:
  Node();
  ~Node();
  void setSymbol(char* newSymbol);
  void setLeft(Node* newLeft);
  void setRight(Node* newRight);
  Node* getLeft();
  Node* getRight();
  char* getSymbol();
  
 private:
  char* symbol;
  Node* left;
  Node* right;

};
#endif
