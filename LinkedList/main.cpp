#include <iostream>
#include "Node.h"

using namespace std;

void add(int newvalue);
void print(Node* next);

Node* head = NULL;

int main()
{
  add(5);
  print(head);

  add(7);
  print(head);

  add(2);
  print(head);

}

void add(int newvalue)
{
  Node* current = head;
  if (current == NULL)
    {
      head = new Node();
      head -> setvalue(newvalue);
	
    }
  else
    {
      while(current -> getnext() != NULL)
	{
	  current = current->getnext();
	}
      current->setnext(new Node());
      current->getnext()->setvalue(newvalue);
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
      cout << next->getvalue() << " ";
      print(next->getnext());
    }
}
