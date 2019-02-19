#include <iostream>
#include <cstring>
#include <queue>
#include <fstream>
using namespace std;


char* input;

int main()
{
  cout << "Welcome to Cheng's heap project" << endl;
  int a = 0;
  int array [100];
  while (a!=3)
    {
      cout << "Enter 1 if you  would like to enter the numbers manually." << endl;
      cout << "Enter 2 if you would like to read in a file with inputs." << endl;
      cout << "Enter 3 if you would like to close the program" << endl;
  
      cin >> a;
      cin.get();
      input = new char[99];
      if (a == 1)
	{
	  cout <<"Please enter numbers with spaces between them (put a space after the last number). " << endl;
	  cin.get(input, 99, '\n');
	  cin.get();                                    
	  int a = strlen(input);
	  int sp = 0;
	  queue<int> spaces;
	  for (int y= 0; y < a ; y++)
	    {
	      
	      sp += 1;
	      if (input[y] == ' ')
		      {
			if (sp != 0)
			  {
			    spaces.push(sp);
			    sp = 0;
			  }
		      }
	    }
	  
	  
	    
	  return 0;
	}
      else if (a == 2)
	{
	  cout <<"Please enter the name of the text file. " << endl;
	  cin.get(input,99, '\n');
	  ifstream myfile;
	  myfile.open(input);
	  
	  if (!myfile)
	    {
	      cout << "There is an error opening the file" << endl;
	      return 13;
	      
     	    }
	  else
	    {
	  
	   
	      int size = 0;
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
	      for (int i = 0; i < size; i++)
		{
		  cout << array[i] << " ";
		}
	      cout << endl;
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
