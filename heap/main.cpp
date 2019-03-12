#include <iostream>
#include <cstring>
#include <queue>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;


char* input;
char* numbers;
void printArray(int array[])
{
       
  cout << endl;
  cout << endl;
  int f = 0;
 
  for (f = 0; f <= 100; f++)
    {
      if (array[f] == -1)
	{
	  break;
	}
    
    }
  int rows = log2(f) + 1 ;
 
  
  //cout << rows << endl;

 
  cout << endl;
  cout <<setw((rows)*3.5) << " " <<  array[0] << endl;
     
  int min = 1;
  int max = 1;
  int currentrow = log2(min) + 1;
  while (max <= 100)
    {
      min = 2 * min;
      max = 2 * max + 1;
      currentrow = log2(min) + 1 ;
      //cout << "currentrow" << currentrow << endl;
      
      for (int i = min; i <= max; i++)
	{
	  
	  if (array[i-1] == -1)
	    {
	      break;
	      break;
	    }
	  else
	    {
	      if ( i/2 != (i+1)/2)
		{
		  
		  cout << setw( pow(2 ,(rows-currentrow)) *3 ) << " " << array[i-1] ;
		}
	      else
		{
		  cout << setw( (rows-currentrow+1) *3 -1)  << " " << array[i-1] ;
		}
		    
	       
	    }
	}
      cout << endl;
    }
}
void checkbackward(int array[], int i)
{ // everytime a number is replaced with an element after it check everything before the number and make sure they are all bigger than the element 

  if (i != 1)
    {
      if (array[i-1] > array[i/2-1]) // if the parent of this new element is smaller, switch them and keep checking until we are at the head
	{
	      
	  int temp = array[i-1];
	  array[i-1] = array[i/2-1];
	  array[i/2-1] = temp;

	  //printArray(array);
	  checkbackward(array, i);
	}
    }
     
  if (array[0] < array[1]) // constantly check if the head's two children are bigger than it (not sure if i even need this, just to make sure)
    {
      int temp = array[0];
      array[0] = array[1];
      array[1] = temp;
    }
  if (array[0] < array[2]) // constantly check if the head's two children are bigger than it (not sure if i even need this, just to make sure)
    {
      int temp = array[0];
      array[0] = array[2];
      array[2] = temp;
    }
  
   
}
void processArray(int array[])
{

  int i = 1; // first number, aka index 0;
  while ((i <= 100) && (array[i] != -1)) 
    {
      if (array[2*i-1] != -1) // if it has a child and its child is bigger, swap them and check all of its parent
	{
	  if (array[i-1] < array[2*i-1])
	    {
	      
	      int temp = array[i-1];
	      array[i-1] = array[2*i-1];
	      array[2*i-1] = temp;
	      //printArray(array);
	      checkbackward(array,i);
	    }
	}
      if (array[2*i] != -1) // same here
	{
	  if (array[i-1] < array[2*i])
	    {

	      
	      int temp = array[i-1];
	      array[i-1] = array[2*i];
	      array[2*i] = temp;
	      //printArray(array);
	      checkbackward(array, i);
	    }
	}
      
      i ++ ;
    }
  
  printArray(array);
  
}

int main()
{
  cout << "Welcome to Cheng's heap project" << endl;
  int a = 0;
  int array [100];
 
  for (int abc = 0; abc <= 100; abc++)
    {
      array[abc] = -1;

    }
  
  while (a!=3)
    {
      cout << "Enter 1 if you  would like to enter the numbers manually." << endl;
      cout << "Enter 2 if you would like to read in a file with inputs." << endl;
      cout << "Enter 3 if you would like to close the program" << endl;
  
      cin >> a;
      cin.get();
      input = new char[100];
      if (a == 1)
	{
	  cout <<"Please enter numbers with spaces between them (put a space after the last number). " << endl;
	  cin.get(input, 100, '\n');
	  cin.get();
	  // read in the numbers
	  
	  int a = strlen(input);
	  int sp = 0;
	  queue<int> spaces; // this is to keep track of the digits of each number so I can directly read from the input array through index
	  for (int y= 0; y < a ; y++)
	    {
	      
	      
	      if (input[y] == ' ') // if it's the end of a number
		{
		  if (sp != 0) // push the numbers of digits to the queue
		    {
			    
		      spaces.push(sp);
		      sp = 0;
			    
		    }
		}
	      else // else the digits ++
		{
		  sp += 1;
		}
	      
	    }
	  /*
	    while (!spaces.empty())
	    {
	    cout << spaces.front() << endl;
	    spaces.pop();
	    }*/
	  //testing all the digits
	  int inputindex = 0; // keep track of the input array
	  int arrayindex = 0; // keep ptrack of the output array
	  int c = 0;
	  int d = 0;
	  
	  while(!spaces.empty()) // while there are still more numbers
	    {
	      
	      c = spaces.front(); 
	      //cout << "c" << c << endl;
	      
	      numbers = new char [100]; // a char array to help change each char to int
	      for (int y = 0; y < c; y++)  // keep read in from the input array until it reaches the size of the number
		{
		  //cout << "index" << inputindex << endl;
		  numbers[y] = input[inputindex];
		  // cout <<"number" <<  input[inputindex] << endl;// put that number into the char array
		  inputindex ++;
		  
		  //input moves towards the left as you read
		}
	      numbers[c] = '\0';
	      inputindex ++;
	      //  cout << "index" << inputindex << endl;// this is the space
	      spaces.pop(); // pop the number of digits from the spaces since we already got the number out

	      d = atoi(numbers); // turn the char array into a number
	      //cout << d << endl; ; // test
	      
	      array[arrayindex++] = d; // add it to the int array
	      
	      
	    }
	  //printArray(array);	 
	  processArray(array);
	      
	  
	  return 0;
	}
      else if (a == 2)
	{
	  cout <<"Please enter the name of the text file. " << endl;
	  cin.get(input,99, '\n');
	  ifstream myfile;
	  myfile.open(input);
	  // read in the name of the file, if it failed to open, close the program
	  if (!myfile)
	    {
	      cout << "There is an error opening the file" << endl;
	      return 13;
	      
     	    }
	  else
	    {
	  
	      // if it opens 
	      int size = 0; //index of the int array
	      while (true)
		{
		  int b;
		  myfile >> b; 
		  if (myfile.eof())
		    {
		      break;
		    }
		  // keep read in numbers until the file is at the end
		  array[size++] = b; // set the next index to the number that just read in

		}
	      myfile.close();
	      // print out the array
	      for (int i = 0; i < size; i++)
		{
		  cout << array[i] << " ";
		}
	      cout << endl;
	      processArray(array);
	      
	      return 0;
	      
	    }
      
	}
      else if (a == 3) // close
	{
	  cout << "Bye" << endl;
	}
      else  //if anything other than 1,2,3 then tell them to retype
	{
	  cout << "Invalid #" << endl;
	  cout << endl;
	}
    }
  return 0;
}
