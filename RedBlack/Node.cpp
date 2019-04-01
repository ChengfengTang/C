
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
void Node::setValue(int newValue)
{
  value = newValue;
}
void Node::setLeft(Node* newLeft)
{
  left = newLeft;
}
void Node::setBlack()
{
  color = 0;
}
void Node::setRed()
{
  color = 1;
}
void Node::setRight(Node* newRight)
{
  right = newRight;
}
void Node::setParent(Node* newParent)
{
  parent = newParent;
}
Node* Node::getParent()
{
  return parent;
}
Node* Node::getLeft()
{
  return left;
}
Node* Node::getRight()
{
  return right;
}

int Node::getValue()
{
  return value;
}
int Node::getColor()
{
  return color;
}
