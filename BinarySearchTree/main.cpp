#include <iostream>
#include <cstring>
#include "Node.h"
#include <stack>
#include <queue>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <math.h>
using namespace std;

void deleteNode(Node* & n, Node* &parent);
void findNode(Node*  head, int number, Node* parent);
void buildTree(int array[], Node* &head, int size);
void add(Node* &head, int number);
void print(Node* head);
char* input;
char* numbers;
int main()
{
  cout << "Welcome to Chengfeng Tang's Binary Search Project" << endl ;
  cout << "To start you would have to enter some numbers!" << endl;
  int a = 10;
  
  int array[100];
  
  Node* head = NULL;
  
  for (int abc = 0; abc <= 100; abc++)
    {
      array[abc] = -1;
    }
  
  
  while( a > 3 || a < 1)
    {
      
      cout << "--------------------------------------------" << endl;
      cout << "Enter 1 if you would like to enter the numbers manually." << endl;
      cout << "Enter 2 if you would like to read in a file with inputs." << endl;
      cout << "Enter 3 if you would like to close the program." << endl;
      
      cout << "--------------------------------------------" << endl;
      cin >> a;
      cin.get();

      input = new char[100];

      if (a == 1)
	{
	  
      cout << "--------------------------------------------" << endl;
	  cout << "Please enter numbers with spaces between them (put a space after the last number)." << endl;
	  
       cout << "--------------------------------------------" << endl;
	  cin.get(input,100);
	  cin.get();

	  int a  = strlen(input);
	  int sp = 0;
	  queue<int> spaces; // keep track of the digits of each number so I can directly read from the input array
	  // and turn them from separate numbers to one int
	  for (int y=0; y<a; y++)
	    {
	      if (input[y] == ' ') // if it's the end of a number
		{
		  if (sp!=0)  // push the numbers of digits to the queue
		    {
		      spaces.push(sp);
		      sp =0;

		    }

		}
	      else // else the digits ++
		{
		  sp += 1;
		}

	    }
	  int inputindex = 0; // keep track of the innput array
	  int arrayindex = 0; // keep track of the output array
	  int c = 0; // the number of spaces for a number
	  int d = 0; // the number
	  while (!spaces.empty())
	    {
	      c = spaces.front();
	      numbers = new char[100]; // a char array to help change each char to int
	      for (int y = 0; y<c; y++) // keep reading in from the input array until it reaches the size
		// of the number
		{
		  numbers[y] = input[inputindex];
		  inputindex ++; // put that number into the char array
		}
	      numbers[c] = '\0';
	      inputindex++;
	      spaces.pop(); // keep going through the space queue move on to the next int
	      d = atoi(numbers); // turn char array into a number
	      array[arrayindex++] = d; // add to the int array
	    }
	  
      cout << "--------------------------------------------" << endl;
	  cout << " The numbers are: " << endl;
	  for (int i = 0; i <= arrayindex-1; i++) // print the array  out
	    {
	      cout << array[i] << " ";
	    }
	  int size = arrayindex;
	  cout << endl;
	  
      cout << "--------------------------------------------" << endl;
	  buildTree(array, head, size);
	 
	}
      else if (a ==2)
	{
	  
      cout << "--------------------------------------------" << endl;
	  cout << "please enter the name of the test file." << endl;
	  
      cout << "--------------------------------------------" << endl;
	  cin.get(input,100);
	  cin.get();
	  ifstream myfile;
	  myfile.open(input);
	  // read in the name of the file, if failed to open close the program.
	  if (!myfile)
	    {
	      cout << "There is an error opening the file" << endl;
	      return 13;;
	    }
	  else
	    {
	      // if opens
	      
	      int size = 0; // index of the int array
	      while (true)
		{
		  int b;
		  myfile >> b;
		  if (myfile.eof())
		    {
		      break;
		    }
		  array[size++] = b;
	      
		}
	      myfile.close();
	      // print the array
	      for (int i = 0; i< size; i++)
		{
		  cout << array[i] << " ";
	      
		}
	      cout << endl;
	      buildTree (array,head, size);
	      
	      
	    }
	}
      else if (a == 3)
	{
	  cout << "Bye" << endl;
	  return 0;
	}
      else
	{
	  cout << "Invalid #" << endl;
	  cout << endl;
	}

    }
  cout << endl;

  // now we have a basic tree, we can start doing stuff with it.
  int b = 0;
  while (b != 4)
    {
      cout << "--------------------------------------------" << endl;
      cout << "Now if you would like to add a Node, enter 1" << endl;
      cout << "If you would like to delete a Node, enter 2" << endl;
      cout << "If you would like to print the tree, enter 3" << endl;
      cout << "If you would like to exit, enter 4" << endl;
      
      cout << "--------------------------------------------" << endl;
      cin >> b;
      cin.get();
      if (b == 1)
	{ // if the user wants to add then add on to the array
	  cout << endl;
	  cout << "What's the number that you want to add?" << endl;
	  
      cout << "--------------------------------------------" << endl;
	  
	  int temp = 0;
	  cin >> temp;
	  cin.get();
	 
	  add ( head, temp);
	  //Singleadd
	}
      else if (b==2) // if the user wants to delete
	{
	  cout << endl;
	  cout << "-----------------------------------------" << endl;
		  
		  
	  cout << "What's the number that you want to delete?"<<endl;
	  cout << endl;
	  int deleted = 0;
	  cin >> deleted;
	  cin.get();
	  findNode(head, deleted, head);
	}
      else if (b==3) // if the user wants to print
	{
	  cout << "-----------------------------------------" << endl;
	  print(head);
	}
      else if (b==4)
	{
	  cout << "bye" << endl;
	  return 0;
	}
      else
	{
	  cout << "Invalid #" << endl;
	  cout << endl;
	}





    }
  
}

void findNode(Node* head, int number, Node* parent)
{
  // go through all the nodes, and find the one that matches it, (not sure what would happen if there is two of the same node)
  Node* current = head;
  if (current->getValue() != number)
    {
      if(number <= current->getValue())
	{
	  if (current->getLeft() != NULL)
	    {
	      Node* next = current->getLeft();
	      findNode(next,number,current);
	    }
	  else
	    {
	      cout << "No such number exists" << endl;
	    }
	}
      
      else if (number > current->getValue())
	{
	  if (current->getRight() != NULL)
	    {
	      Node* next = current->getRight();
	      findNode(next,number,current);
	    }
	  else
	    {
	      
	      cout << "No such number exists" << endl;
	    }
	}
    }
  else
    {
      deleteNode(current, parent);
    }
}
void deleteNode(Node* & n, Node* & parent)
{
  cout << "Node with number: " << n->getValue() << " has been deleted" << endl;
 //4 senarios, leaf, node with 1 left, node with 1 right, node with 2 children but right has no left children, node with two children...    
  if ((n->getLeft() == NULL) && (n->getRight() == NULL))
	{
	  //leaf
	  
	  
	}
  else if ((n->getLeft() == NULL)|| (n->getRight() == NULL))
	// one child
	{
	  if (n->getLeft() == NULL)
	    {


	    }
	  else if (n->getRight() == NULL)
	    {

	      
	    }
	}
      else // two children
	{
	  if (n->getRight()->getLeft() == NULL)
	    {


	    }
	  else
	    {


	    }

	}

}
	/*
      if (current->getLeft() != NULL)
	{
	  Node* replace = current->getLeft();
	  if (replace ->getRight() != NULL)
	    {
	      current->getLeft() == NULL; // disconnect the node with its current parent
	    }
	  else
	    {
	      Node* temp;
	      while (replace->getRight() != NULL) //go left once and keep going right to find the largest number that's smaller than the node being deleted
		{
		  temp = replace;
		  replace = replace->getRight();
		}
	      temp->getRight() == NULL;
	    }
	  replace->setLeft(current->getLeft()); // connect that node's left with current node's left
	  cout << "Number: " << replace->getValue()<< " now has a left of: " << replace->getLeft()->getValue() << endl;
	  if (current->getRight() != NULL)
	    {
	      replace->setRight(current->getRight()); // connect that node with current's right
		
	      cout << "Number: " << replace->getValue()<< " now has a right of: " << replace->getRight()->getValue() << endl;
	    }
	  
	  if (current != parent) // if the node deleted is not the head, connect the replacing node with
	    // current nodes' parent
	    {
	      if (parent->getLeft() == current)
		{
		  parent->setLeft(replace);
		  cout << "After deletion. Num: " << replace ->getValue() << " is the left of: " << parent->getValue()<< endl;
	      
		}
	      else if (parent->getRight() == current)
		{
		  
		  parent->setRight(replace);
		  cout << "After deletion. Num: " << replace ->getValue() << " is the right of: " << parent->getValue()<< endl;
	      
		}
	      delete current;
	      
	    }
	}
      else if (current->getRight() != NULL) // if the node being deleted doens't have a left, but have a right
	{
	  Node* replace = current->getRight(); 
	  if (current == parent) // if this is the head
	    {
	      Node* gone = current;
	     
	      current = replace;
	      delete gone;
	    }
	  else
	    {
	      if (parent->getLeft() == current)
		{
		  cout << "parent: " << parent->getValue() << " now has left of: " << replace->getValue() << endl;
		  parent->getLeft() == replace;
		  delete current;
		}
	      else if (parent->getRight() == current)
		{
		  
		  cout << "parent: " << parent->getValue() << " now has right of: " << replace->getValue() << endl;
		  parent->getRight() == replace;
		  delete current;
		}
	    }
	}
      else
	{
	
	  if (parent->getLeft() == current)
	    {
	      
	      cout << "parent: " << parent->getValue() << " now has nothing on its right" << endl;
	      parent->getLeft() == NULL;
	      delete current;
	    }
	  else if (parent->getRight() == current)
	    {
	      
	      cout << "parent: " << parent->getValue() << " now has nothing on its right" << endl;
	      parent->getRight() == NULL;
	      delete current;
	    }
	}
    }
  

}
	*/
void print(Node* head)
{
  cout << "Head: " << head->getValue() << endl;
  if (head->getLeft() != NULL)
    {
      cout << "Left of " << head->getValue() << " : " ;
      print(head->getLeft());
      
    }
  if (head->getRight() != NULL)
    {
      cout << "Right of " << head->getValue() << " : " ;
      print(head->getRight());
      
    }
  
}

void add( Node* &head, int number)
{
  
  cout << "--------------------------------------------" << endl;
     
	  Node * current = head;
	  while (head != NULL)
	    {
	      if (number <= current->getValue())
		{
		  if (current->getLeft() == NULL)
		    {
		      cout << "left of " << current->getValue() << ": " << number << endl; 
		      Node* node = new Node();
		      node->setValue(number);
		      current->setLeft(node);
		      break;
		    }
		  else
		    {
		      
		      current = current->getLeft();

		    }
		}
	      else if (number > current->getValue())
		{
		  if (current->getRight() == NULL)
		    {
		      cout << "Right of " <<current->getValue() << ": " << number << endl; 
		      Node* node = new Node();
		      node->setValue(number);
		      current->setRight(node);
		      break;
		    }
		  else
		    {
		      current = current->getRight();
		    }
		}
	    }
	
  
}


void buildTree (int array[], Node* &head, int size)
{
  
  cout << "--------------------------------------------" << endl;
  cout << "There are " << size << " nodes" << endl;
  /*for (int i =0 ; i<=size-1; i++)
    {
      cout << array[i] << " ";
    }
  cout << endl;*/
  cout << "--------------------------------------------" << endl;
  for (int i = 0; i <= size-1; i++)
    {
      if (head == NULL)
	{
	  Node* temp = new Node;
	  temp->setValue(array[i]);
	  head = temp;
	  
	  cout << "head: " << head->getValue() << endl;
	}
      
      else
	{
	  Node * current = head;
	  while (head != NULL)
	    {
	      if (array[i] <= current->getValue())
		{
		  if (current->getLeft() == NULL)
		    {
		      cout << "left of " << current->getValue() << ": " << array[i] << endl; 
		      Node* node = new Node();
		      node->setValue(array[i]);
		      current->setLeft(node);
		      break;
		    }
		  else
		    {
		      
		      current = current->getLeft();

		    }
		}
	      else if (array[i] > current->getValue())
		{
		  if (current->getRight() == NULL)
		    {
		      cout << "Right of " <<current->getValue() << ": " << array[i] << endl; 
		      Node* node = new Node();
		      node->setValue(array[i]);
		      current->setRight(node);
		      break;
		    }
		  else
		    {
		      current = current->getRight();
		    }
		}
	    }
	    
          
	}
    }
  
}

