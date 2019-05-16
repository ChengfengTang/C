#include <iostream>
#include <math.h>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;
char* vertex;

  char* input;
  char* start;
  char* end;
  
int main()
{
  int a = 10;
  vector<char*> vertex ;

  int arr[20][20];
  for(int q = 0; q <= 19; q++)
    {
      for (int w = 0; w <= 19; w++)
	{
	  arr[q][w] = -1;
	}
    }
  
  while (a != 5 )
    {
      
      cout << "Welcome to Cheng's Graph Creator!" << endl;
      cout << "To add a vertex, enter \"1\"." << endl;
      cout << "To add an edge, enter \"2\"." << endl;
      cout << "To delete an edge, enter \"3\"." << endl;
      cout << "To see the adjacency matrix, enter \"4\"." << endl;
      cout << "To close the program, enter \"5\"." << endl;
      cin >> a;
      cin.get();

  
      if (a == 1) // add vertex
	{
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the vertex that you would like to add?" << endl;
	  input = new char[100];
	  cin.get(input,100);
	  cin.get();
	  
	  cout << "----------------------------------------" << endl;
	  cout << "Vertex " << input << " is created. " << endl;
	  vertex.push_back(input); // put this in the vector of all nodes
	  arr[vertex.size()-1][vertex.size()-1] = 0; //the distance of a node to itsself is always 0
	  cout << "----------------------------------------" << endl;
	}
      else if (a == 2)
	{
	  start = new char[100];
	  end = new char[100];
	  int weight = 0;
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the starting vertex?" << endl;
	  cin.get(start,100);
	  cin.get();
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the ending vertex?" << endl;
	  cin.get(end,100);
	  cin.get();
	  cout << "----------------------------------------" << endl;
	  cout<< "What's the weight of the edge going from " << start << " to " << end << " ?" << endl;
	  cin >> weight;
	  cin.get();
	  if (strcmp(start,end) == 0) // can not connect a node with it self
	    {
	  cout << "----------------------------------------" << endl;
	  cout << "Can't connect a node with itself. "  << endl;
	  cout << "----------------------------------------" << endl;
	     
	    }
	  else
	    {
	  int q ; // column
	  for( q = 0; q <= vertex.size()-1; q++)
	    {
	      if (strcmp(vertex[q] , start) == 0)
		{
		  break;
		}
	    }
	  
	  int w ; //row
	  for(w = 0; w <= vertex.size()-1; w++)
	    {
	      if (strcmp(vertex[w],end) == 0)
		{
		  break;
		}
	    }
	  /*
	  cout << q << endl;
	  cout << w << endl;
	  cout << vertex.size() -1 << endl;*/
	  if ((q > vertex.size()-1)) // just to make sure that the node is not even on the list, the counter would
	    // therefore, be greater than the index
	    {
	      cout << "----------------------------------------" << endl;
	  

	      cout << "Can not find the beginning node" << endl;
	      cout << "----------------------------------------" << endl;
	  
	    }
	  else if (w > vertex.size()-1)
	    {
	      cout << "----------------------------------------" << endl;
	  
	      cout << "Can not find the ending node" << endl;
	      cout << "----------------------------------------" << endl;
	      
	    }
	  else // if it is located, change that position to the value/
	    {
	  
	      arr[q][w] = weight;
	      
	      cout << "----------------------------------------" << endl;
	      cout << "The weight that goes from "<< start << " to " << end << " is: " << weight << endl;
	      cout << "----------------------------------------" << endl;
	    }
	    }
       }
      else if (a == 3 )
	{
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the starting vertex?" << endl;
	  cin.get(start,100);
	  cin.get();
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the ending vertex?" << endl;
	  cin.get(end,100);
	  cin.get();
	  cout << "----------------------------------------" << endl;
	  cout << "Deleting edge going from " << start << " to " << end << " ." << endl;
	  
	  cout << "----------------------------------------" << endl;
	
	}
      else if (a == 4)
	{
	  
	  /*
	  arr[0][1] =5;
	  arr[0][2] =11;
		
		
	  arr[1][0] = 3;
	 
	  arr[1][2] =1;
		
	  arr[2][0] =7;
	  arr[2][1] =3;
	  */
		
	      cout << "----------------------------------------" << endl;
	      cout << "  " ;
	      // print the a b c on top
	      for(vector<char*>::iterator v = vertex.begin(); v != vertex.end(); v++ )
		{
		  
		  cout << *v << " ";
		}
	      cout << endl;
	      // print a and all of A's distance to abc...
	      //then move on to B's distanec to abc... for a range of the numbers of vertex - 1 as index
	      vector<char*> :: iterator b = vertex.begin();
	      for (int a = 0; a<= vertex.size()-1; a++)
		{
	      
	          
		  cout << *b << " ";
		  for (int c = 0; c<= vertex.size()-1; c++)
		    {
		      
		      
		      cout << arr[a][c] << " ";
			
		    }
		  cout << endl;
		  b++;
		}
	    
	  cout << "----------------------------------------" << endl;
	  
	    
	}
      else if (a == 5)
	{
	  return 0;
	}
      else
	{
	  cout << "----------------------------------------" << endl;
	  
	  cout << "Invalid #! Please reenter." << endl;
	  
	  cout << "----------------------------------------" << endl;
	  
	}
  


    }
  
  
}
