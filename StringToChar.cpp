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

int main()
{

for (int abc = 0; abc <= 100; abc++)
    {
     array[abc] = -1;
    }
input = new char[100];


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
	      numbersofnumbers = size;
	    }
	}
}
