 #include <iostream>
#include <cstring>
#include <queue>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <math.h>
using namespace std;

char* input;
char* numbers;
int main()
{

  input = new char[999];
  int array [999];
  
  for (int abc = 0; abc <= 999; abc++)
    {
      array[abc] = -1;
    }

  cout << "--------------------------------------------" << endl;
  cout << "Please enter numbers with spaces between them (put a space after the last number)." << endl;
	  
  cout << "--------------------------------------------" << endl;
  cin.get(input,100);
  cin.get();

  int a  = strlen(input); // length of the input
  int sp = 0; // number of spaces
  queue<int> spaces; // keep track of the digits of each number so I can directly read from the input array
  // and turn them from separate numbers to one int
  for (int y=0; y<a; y++) // a for loop that goes through the entire intput array, since max index should be length - 1, I used < instead of <=
    {
      if (input[y] == ' ') // if it's space, that represents the end of a number
	{
	  if (sp!=0)  // push the numbers of digits to the queue
	    {
	      spaces.push(sp);
	      sp =0; //reset spacing
	    }

	}
      else // if it's not the end of a number, the number of digits of the current number ++
	{
	  sp += 1;
	}

    }
  int inputindex = 0; // keep track of the input array
  int arrayindex = 0; // keep track of the output array
  int c = 0; // the number of spaces for a number
  int d = 0; // the number
  while (!spaces.empty()) // when the number of spacing queue isn't empty, that means there is more numbers to be read
    {
      c = spaces.front(); // c represents the number of space of the current number
      numbers = new char[100]; // a char array to help change each char to int
      for (int y = 0; y<c; y++) // keep reading in from the input array until it reaches the size of the number
	{ //for example, if the first number is 350, c here would be 3, and we read in the number til digits hit 3
	  numbers[y] = input[inputindex];
	  inputindex ++; // put that number into the char array
	}
      numbers[c] = '\0';
      inputindex++; // the next number would start at index 5, if the first number was 350, since there is space in between numbers
      spaces.pop(); // keep going through the space queue move on to the next int by popping the top
      d = atoi(numbers); // turn char array into a number
      array[arrayindex++] = d; // add to the int array
    }
	  
  cout << "--------------------------------------------" << endl;
      cout << "The numbers are: " << endl;
      for (int i = 0; i <= arrayindex-1; i++) // print the array  out
	{
	  cout << array[i] << " ";
	}
  
      cout << endl;
	  
      cout << "--------------------------------------------" << endl;
}
