#include <iostream>
#include "Node.h"

using namespace std;

void add(Student*);
void print(Node* next);

Node* head = NULL;

int main()
{

  
  Student* temp = new Student ( "Chengfeng", "Tang", 465783, 4.0);

  add(temp);

  temp = new Student ( "Zareef", "xd", 453183, 3.0);

  
  add(temp);

  print(head);

}

void add(Student* newStudent)
{
  Node* current = head;
  if (current == NULL)
    {
      head = new Node();
      head -> setStudent(newStudent);
	
    }
  else
    {      while(current -> getnext() != NULL)
	{
	  current = current->getnext();
	}
      current->setnext(new Node());
      current->getnext()->setStudent(newStudent);
    }
}

void print(Node* next)
{
  if (next == head)
    {
      cout << "List" ;
    }

  if (next != NULL)
    {
      cout << next->getStudent()->getfirstname() << " ";
      print(next->getnext());
    }
}
