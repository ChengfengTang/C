#include <iostream>
#include "Node.h"

Node::Node()
{
  left = NULL;
  right = NULL;
};
Node::~Node()
{
  
    left = NULL;
  
  right = NULL;
}
void Node::setSymbol(char newSymbol)
{
  symbol = newSymbol;
}
void Node::setLeft(Node* newLeft)
{
  left = newLeft;
}
void Node::setRight(Node* newRight)
{
  right = newRight;
}
Node* Node::getLeft()
{
  return left;
}
Node* Node::getRight()
{
  return right;
}
char Node::getSymbol()
{
  return symbol;
}
