#include <iostream>
#include <cstring>
#include <queue>
#include <math.h>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

void printArray (int intarray[],int rows, int longestnumber, int numbers);
char* input;
char* numbers;
void printArray (int intarray[],int rows, int longestnumber, int numbers)
{
 
  int indexbegin = pow(2,rows-1) -1;  // if the row that's passed in is 3, index starts 3 which is the 4th element
  int indexend = pow(2,rows) -1; // and ends at 7, which is the 8th element

  for (int i= indexbegin; i<= indexend; i++)
    {
      if (intarray[i] == -1)
	{
	  intarray[i] = -2;
	}
    }
  for (int i =0; i<= 100; i++)
    {
      cout << intarray[i] << endl;
      if (intarray[i] == -1)
	{
	  break;
	}
    }
   
  int arrayindex = 0; // keep track of the elements in the elementsindex
  int numbersofelements = pow(2,rows-1);
  cout << "Numbers of number in the bottom row: " << numbersofelements << endl;
  int elementsindex [numbersofelements] = {};

  for (int i = 1; i<= numbersofelements; i++ )
    {
      
      int position = ((i-1) * longestnumber) + (i-1)* 1 ; // 1 here is spacing between each element
      elementsindex[arrayindex] = position;
      
      arrayindex++;
      
    }
  
  //calculate everything above this level now
  int d = 0;
  int m = numbersofelements -1;
  
  for(int r = rows; r > 1; r--)
    {
       
      for ( int v = d;  v<= m ; v++)
	{
	  if (v%2 ==0 )
	    {
	      
	      int add =  (elementsindex[v] + elementsindex[v+1]) /2;
	      
	     
	      elementsindex[arrayindex] = add;
	      
	      arrayindex++;
	      
	    }
	}
       d = m +1;
      
      m += pow(2,r-2);
    }
  elementsindex[arrayindex] == '\0';
  cout << arrayindex << endl;
  for (int n = 0           ; n<=arrayindex-1  ; n++ )
    {
      cout << "Index: " <<elementsindex[n] << endl;
      }

  
  int length = longestnumber*pow(2,rows-1) + (pow(2,rows-1) * 1 -1) - 1;
  cout << "Every row should have a index length of: " << length << endl;
  int a = 0;

  for (int j = rows; j > 0;  j--)
  {
    int x = pow(2,j-1) -1;	
    if ( x == 0)
      {
    for (int lastforloopipromise = 0; lastforloopipromise < elementsindex[a]; lastforloopipromise++)
	  {
	    cout <<" ";
	  }
	int l = log10(intarray[0])+1;
	if (l % 2 == 0)
	  {
	    cout << "0" ; // add a 0 if it has even nums of digits
	  }
	cout << intarray[0] << endl;
        
      }
    else
      {
	for (int i = 0; i<= length;)
	  {
         
	    if (i == elementsindex[a])
	      {
		if (intarray[x] == -2)
		  {
		    for( int k = 0; k <= longestnumber; k++ )
		      {
			cout << " ";
		      }
		    i+= longestnumber;
		    a++;
		    x++;
		  }
		else if ((intarray[x] != -1) && (x !=0))
		  {
		    int p = log10(intarray[x])+1;
		    if (p <= longestnumber)
		      {
			for (int b = 0; b< longestnumber-p; b++)
			  {
			    cout << "0"; // 1 -> 001 if the longest digit is 3
			  }
			cout << intarray[x];
			i += longestnumber;
		  
			a++;
			x++;
		      }
		  }
		else
		  {
		    break;
		  }
	 
	      }
	    else
	      {
		cout <<" ";
		i++;
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
  int longestnumber = 0;
  for (int i = 0; i<= 100; i++)
    {
      if (array[i] != -1)
	{
	  if (log10(array[i]) +1 > longestnumber)
	    {
	      longestnumber = log10(array[i])+1; 
	    }
	}
      else
	{
	  break;
	}
    }
  
  if (longestnumber %2 == 0) // make sure it's an odd digit.
    {
      longestnumber ++;
    }
  cout << "The longestnumber in the array list has a digit of: " << longestnumber << endl; 
  int numbers = 0;
  for ( int i = 0; i <= 100; i++)
    {
      if (array[i] != -1)
        {
	  cout << array[i] << " ";
        }
      else
        {
	  numbers = i;
	  break;
        }
        
    } // print out all the valid numbers, which are non -1s
  cout << endl;

  //calculate # of rows
  int rows =  log2(numbers) + 1;
    
  printArray (array, rows,longestnumber, numbers);
 
  
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
