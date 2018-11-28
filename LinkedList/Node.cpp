#include "Node.h"
#include <iostream>
#include "Student.h"
Node::Node()
{
 
  next = NULL;
}
Node::~Node()
{
  delete &Student;
  next = NULL;
}
void Node::setStudent(Student* newStudent)
{
  Student = newStudent;
}
Student* Node::getStudent()
{
  return Student;
}
void Node::setnext(Node* newnext)
{
  next = newnext;
}
Node* Node::getnext()
{
  return next;
  
}
