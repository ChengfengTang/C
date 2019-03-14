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
void add(int array[], Node* &head, int size);
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
	  add(array, head, size);
	 
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
	      add (array,head, size);
	      
	      
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
	{
	  cout << endl;
	  cout << "What's the number that you want to add?" << endl;
	  
      cout << "--------------------------------------------" << endl;
	  
	  int temp = 0;
	  cin >> temp;
	  cin.get();
	  int size2 = 0;
	  while (array[size2] != -1)
	    {
	      size2++;
	    }
	  array[size2] = temp;
	  size2++;
	  add (array, head, size2);
	  //Singleadd
	}
      else if (b==2)
	{
	  cout << endl;
	  cout << "What's the number that you want to delete?"<<endl;
	  cout << endl;
	  //delete
	}
      else if (b==3)
	{
	  cout << "-----------------------------------------" << endl;
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
void add (int array[], Node* &head, int size)
{
  
      cout << "--------------------------------------------" << endl;
  cout << "There are " << size << " nodes" << endl;
  
      cout << "--------------------------------------------" << endl;
  for (int i = 0; i <= size; i++)
    {
      if (head == NULL)
	{
	  Node* head = new Node();
	
	  head->setValue(array[i]);
	}
      else
	{
	  Node * current = head;
	  while (head != NULL)
	    {
	      if (array[i] < current->getValue())
		{
		  if (current->getLeft() == NULL)
		    {
		      Node* node = new Node();
		      node->setValue(array[i]);
				    current->setRight(node);
				    break;
				    }
		      else
			{
			  cout << "smaller" << endl;
			  current->getLeft();

			}
		    }
		  else if (array[i] > current->getValue())
		    {
		      if (current->getRight() == NULL)
			{
			  Node* node = new Node();
			  node->setValue(array[i]);
			  current->setRight(node);
			  break;
			}
		      else
			{
			  cout << "bigger" << endl;
			  current->getRight();
			}
		    }
		}
	    
	    
	    }
	}
  
    }

