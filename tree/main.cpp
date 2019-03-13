/*
  I build the tree all by myself and it took me a long time, so praise me all you want, I just want my credit when you use it :D
  This only works when a tree is built off an int array
  
  The concept is, find the # of rows, put one space in between all the numbers in the bottom row, and work your way up.
  However, I have to go through the arraylist and find the longest number and make everything equally long in digits



*/
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

void calculatespaces (int intarray[],int rows, int longestnumber, int numbers);
int main()
{
  int intarray[100] =  {1080,10,5,-1,'\0'}; // enter the number here
  int longestnumber = 0;
  for (int i = 0; i<= 100; i++)
    {
      if (intarray[i] != -1)
	{
	  if (log10(intarray[i]) +1 > longestnumber)
	    {
	      longestnumber = log10(intarray[i])+1; 
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
  for ( int i = 0; i <= sizeof(intarray); i++)
    {
      if (intarray[i] != -1)
        {
	  cout << intarray[i] << " ";
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
    
  calculatespaces (intarray, rows,longestnumber, numbers);
  return 0 ;
}

void calculatespaces (int intarray[],int rows, int longestnumber, int numbers)
{
 
  int indexbegin = pow(2,rows-1) -1;  // if the row that's passed in is 3, index starts 3 which is the 4th element
  int indexend = pow(2,rows) -1; // and ends at 7, which is the 8th element
  
   
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

 for (int j = rows; j > 0; j--)
  {
    int x = pow(2,j-1) -1;
    if (x == 0) // log 0 is undefined, since the top tree is always the biggest number therefore, just print it out.
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
    for (int i = 0; i<= length;)
      {
         
	if (i == elementsindex[a])
	  {
	  
	    if ((intarray[x] != -1) && (x !=0))
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
    cout << endl;
  
  }
}

