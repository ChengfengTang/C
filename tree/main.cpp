
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

void calculatespaces (int intarray[],int rows, int longestnumber, int numbers, int numbersize[]);
void print(int spacing[], int intarray[], int rows, int longestnumber, int numbers, int numbersize[], int lastrow);

int main()
{
    int intarray[100] =  { 108,39,48,17,16,5,4,3,2,1,-1,-1,-1,-1 };
    int longestnumber = 3;
    int numbersize[100] = {3,2,2,2,2,1,1,1,1,1};
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
        
    }
    cout << endl;
    int rows =  log2(numbers) + 1; 
    calculatespaces (intarray, rows,longestnumber, numbers, numbersize);
    return 0 ;
}

void calculatespaces (int intarray[],int rows, int longestnumber, int numbers, int numbersize[])
{
 
 
  int lastrow = pow(2 , rows-1) -1 ;
   
  int spacing[] = {};
  int spacingindex = 0;
  int spaces = 0;
  if (rows = log2(numbers) + 1) // if this is the bottom row
    {
      print(spacing, intarray, rows, longestnumber, numbers, numbersize, lastrow);
      for (int a = lastrow ; a<= 100; a++)
	{
	  if (intarray[a] != -1)
	    { 
	      
	     
	      spaces += (longestnumber + 1);
	      
	      if (a%2 == 0)
		{
		  spacing[spacingindex++] = spaces -1; 
		
		}
	      //   002      
	      // 001 004 008 007
	    }
	  else
	    {
	      spacing[spacingindex] = '\0';
	      break;
	    }
            
	}
      rows = rows - 1;
      lastrow = pow(2,rows-1) -1 ;
      print(spacing, intarray, rows, longestnumber, numbers, numbersize, lastrow);
     
      
    }
  else 
    {
      
    }
    
}
void print(int spacing[], int intarray[], int rows, int longestnumber, int numbers, int numbersize[], int lastrow)
{
  if (spacing[0] == NULL)
    {
        cout <<"this is row # : " << rows << endl;

    cout << "index for the beginning of the row is: " << lastrow << endl;

      for (int a = lastrow ; a<= 100; a++)
	{
	  if (intarray[a] != -1)
	    { 
	      if (numbersize[a] <= longestnumber)
		{
		   for (int x = 1; x<= longestnumber-numbersize[a]; x++)
		    {
		      cout << "0"; // 1 -> 001 if the longest digit is 3
		    }
		    cout << intarray[a] << " ";
		}
	    }
	  else
	    {
	      break;
	    }
        }
    }
  else 
    {
        cout <<"this is row # : " << rows << endl;
	cout << "index for the beginning of the row is: " << lastrow << endl;
	for (int i = 0; i<= 100; i++)
	  {
	    while (spacing[i] != '\0')
	      {
	    cout << "index of center " << spacing[i] << endl;
	      }
	  }
	
      int y = 0;
     
      for (int a = lastrow; a<= 100; a ++)
	{
	  if (intarray[a] != -1)
	    {
	      if (y == 0)
		{
		  for (int i = 0; i <= spacing[y]  - (longestnumber/2) -1 ; i++ )
		    {
		      cout << i;
		      cout << " ";
		    }
		  y++;
		}
	      else
		{
		  for (int i =0; i<= spacing[y] - spacing[y-1] - (longestnumber/2) - 1; i++)
		    {
		      cout << i;
		      cout << " ";
		    }
		  y++;
		}
	      if (numbersize[a] <= longestnumber)
		{
		  for (int x = 1; x<= longestnumber-numbersize[a]; x++)
		    {
		      cout << "0"; // 1 -> 001 if the longest digit is 3
		    }
		   cout << intarray[a] ;
	     
		}
	      
	    }
	  else
	    {
	      break;
	    }

	}
      
    }
} 
