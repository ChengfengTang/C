
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
void Node::setColor(int newColor)
{
  color = newColor;
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
int Node::getColor(Node* n)
{
  if (n== NULL)
    {
      return 0;
    }
  else
    {
  return color;
    }
}
