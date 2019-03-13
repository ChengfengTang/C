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
void add(int array[], Node* &head);
char* input;
char* numbers;
int main()
{
  cout << "Welcome to Chengfeng Tang's Binary Search Project" << endl ;

  int a = 0;
  int array[100];
  Node* head = NULL;
  for (int abc = 0; abc <= 100; abc++)
    {
      array[abc] = -1;
    }

  while( a!= 3)
    {
      cout << "Enter 1 if you would like to enter the numbers manually." << endl;
      cout << "Enter 2 if you would like to read in a file with inputs." << endl;
      cout << "Enter 3 if you would like to close the program." << endl;
      cin >> a;
      cin.get();

      input = new char[100];

      if (a == 1)
	{
	  cout << "Please enter numbers with spaces between them (put a space after the last number)." << endl;
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
	  cout << " The numbers are: " << endl;
	  for (int i = 0; i <= arrayindex-1; i++) // print the array  out
	    {
	      cout << array[i] << " ";
	    }
	  cout << endl;
	  add(array, head);
	  return 0;
	}
      else if (a ==2)
	{
	  cout << "please enter the name of the test file." << endl;
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
	      add (array,head);
	      
	      return 0;
	    }
	}
      else if (a == 3)
	{
	  cout << "Bye" << endl;
	  
	}
      else
	{
	  cout << "Invalid #" << endl;
	  cout << endl;
	}

    }

  return 0;
}
void add (int array[], Node* &head)
{
  
  if (head == NULL)
    {
      array[i] ==
    }
}
