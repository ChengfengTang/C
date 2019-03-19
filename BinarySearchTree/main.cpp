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

void deleteNode(Node* & n, Node* &parent, Node* &head);
void findNode(Node*  &head, int number, Node* &parent);
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
	  if (arrayindex == 0) // if the user didn't enter anything, let them retype
	    {
	  
	    }
	  else
	    {
	      cout << "The numbers are: " << endl;
	      for (int i = 0; i <= arrayindex-1; i++) // print the array  out
		{
		  cout << array[i] << " ";
		}
	      int size = arrayindex;
	      cout << endl;
	  
	      cout << "--------------------------------------------" << endl;
	      buildTree(array, head, size);
	 
	    }
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
      if (array[0] == -1)
	{
	  cout << "You didn't type in anything!" << endl;
	  a = 10;
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

void findNode(Node* &head, int number, Node* &parent)
{
  if (head != NULL)
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
	  deleteNode(current, parent, head);
	}
    }
  else
    {
      cout << "You don't have any numbers in the tree!" << endl;
    }
}
void deleteNode(Node* & n, Node* & parent, Node* & head)
{
  cout << "Node with number: " << n->getValue() << " has been deleted" << endl;
  //4 senarios, leaf, node with 1 left, node with 1 right, node with 2 children but right has no left children, node with two children...    
  if ((n->getLeft() == NULL) && (n->getRight() == NULL))
    {
      //if it's a leaf, just disconnect it wiht its parent and delete it
      if(parent->getLeft() == n)
	{
	  parent->setLeft(NULL);
	  cout << "Parent Node: " << parent->getValue() << "  no longer has a left child of: " << n->getValue() << endl;;
	      
	  cout << "-----------------------------------------" << endl;

	}
      else if(parent->getRight() == n)
	{
	  parent->setRight(NULL);
	  cout << "Parent Node: " << parent->getValue() << "  no longer has a right child of: " << n->getValue() << endl;;
	      
	  cout << "-----------------------------------------" << endl;

	}
      else if (n == head)// this only happenes when parent = n, which is when this is the head
	{
	     
	  cout << "Head Node: " << head->getValue() << "  was deleted" << endl;;
	  head = NULL;
	  cout << "-----------------------------------------" << endl;

	    
	}
       
	  
    }
  else if ((n->getLeft() == NULL)|| (n->getRight() == NULL))
    // one child
    {
      if (n->getLeft() == NULL)
	{
	  // if the number only has a right child, go right once and go as left as possible
	  Node* bye = n->getRight();
	  Node* byeparent = n;
	  while(bye->getLeft() != NULL)
	    {
	      byeparent = bye;
	      bye = bye->getLeft();
		  
	    }
	  bye->setRight(n->getRight());
	  cout << "Number: " << bye->getValue()  <<" will replace node: " << n->getValue() << " With a right child of: "<< n->getRight()->getValue() << endl;
	      
	  //disconnect bye with its parent
	  if(byeparent->getLeft() == bye)
	    {
	      byeparent->setLeft(NULL);
	      cout << "Parent Node: " << byeparent->getValue() << "  no longer has a left child of: " << bye->getValue() << endl;;
	      
	    }
	  else if(byeparent->getRight() == bye)
	    {
	      byeparent->setRight(NULL);
	      cout << "Parent Node: " << byeparent->getValue() << "  no longer has a right child of: " << bye->getValue() << endl;;
	      
	    }
	  // now put bye at n's position
	  if(parent->getLeft() == n)
	    {
	      parent->setLeft(bye);
	      cout << "Parent Node: " << parent->getValue() << "  now has a left child of: " << bye->getValue() << endl;;
	      
	      cout << "-----------------------------------------" << endl;
	      
	      n->setRight(NULL);
	      delete n;
	    }
	  else if(parent->getRight() == n)
	    {
	      parent->setRight(bye);
	      cout << "Parent Node: " << parent->getValue() << "  now has a right child of: " << bye->getValue() << endl;;
	      
	      cout << "-----------------------------------------" << endl;
	      
	      n->setRight(NULL);
	      delete n;
	    }
	  else //n is the head
	    {
	      head = bye;
	    }
	    
	      
	      
	}
      else if (n->getRight() == NULL)
	{
	  // if the number only has a left child, go left once and go as right as possible
	  Node* bye = n->getLeft();
	  Node* byeparent = n;
	  while(bye->getRight() != NULL)
	    {
	      byeparent = bye;
	      bye = bye->getRight();
		  
	    }
	  bye->setLeft(n->getLeft());
	  cout << "Number: " << bye->getValue()  <<" will replace node: " << n->getValue() << " With a left child of: "<< n->getLeft()->getValue() << endl;
	      
	  //disconnect bye with its parent
	  if(byeparent->getLeft() == bye)
	    {
	      byeparent->setLeft(NULL);
	      cout << "Parent Node: " << byeparent->getValue() << "  no longer has a left child of: " << bye->getValue() << endl;;
	      
	    }
	  else if(byeparent->getRight() == bye)
	    {
	      byeparent->setRight(NULL);
	      cout << "Parent Node: " << byeparent->getValue() << "  no longer has a right child of: " << bye->getValue() << endl;;
	      
	    }
	  // now put bye at n's position
	  if(parent->getLeft() == n)
	    {
	      parent->setLeft(bye);
	      cout << "Parent Node: " << parent->getValue() << "  now has a left child of: " << bye->getValue() << endl;;
	      
	      cout << "-----------------------------------------" << endl;
	      
	      n->setLeft(NULL);
	      delete n;
	    }
	  else if(parent->getRight() == n)
	    {
	      parent->setRight(bye);
	      cout << "Parent Node: " << parent->getValue() << "  now has a right child of: " << bye->getValue() << endl;;
	      
	      cout << "-----------------------------------------" << endl;
	      
	      n->setLeft(NULL);
	      delete n;
	    }
	  else
	    {
	      head = bye;
	    }
	      
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
       
void print(Node* head)
{
  if (head != NULL)
    {
      
      cout <<  head->getValue() << endl;
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
  else
    {
      cout << "You don't have any numbers in the tree" << endl;
    }
  
}

void add(Node* &head, int number)
{
  
  cout << "--------------------------------------------" << endl;
  if (head != NULL)
    {
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
  else
    {
           
      Node* whatever = new Node;
      whatever->setValue(number);
      head = whatever;
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

