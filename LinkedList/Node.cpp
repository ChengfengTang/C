#include "Node.h"
#include <iostream>
#include "Student.h"
Node::Node()
{
 
  next = NULL;
}
Node::~Node()
{
  delete &student;
  next = NULL;
}
void Node::setStudent(Student* newStudent)
{
  student = newStudent;
}
Student* Node::getStudent()
{
  return student;
}
void Node::setnext(Node* newnext)
{
  next = newnext;
}
Node* Node::getnext()
{
  return next;
  
}
