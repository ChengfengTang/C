#include "Node.h"
#include <iostream>

Node::Node()
{
  value = 0;
  next = NULL;
}
Node::~Node()
{
  delete &value;
  next = NULL;
}
void Node::setvalue(int newvalue)
{
  value = newvalue;
}
int Node::getvalue()
{
  return value;
}
void Node::setnext(Node* newnext)
{
  next = newnext;
}
Node* Node::getnext()
{
  return next;
  
}
