#include <iostream>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;

int main()
{
  int a = 10;
  char* input;
  char* start;
  char* end;
  
  vector<vector<int> > vectorsofvectors;
  vector<char*> vertex;
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
	  //vector<int> newv;
	  vertex.push_back(input);
	  //vectorsofvectors.push_back(newv);
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
	  
	  cout << "----------------------------------------" << endl;
	  cout << "The weight that goes from "<< start << " to " << end << " is: " << weight << endl;
	  cout << "----------------------------------------" << endl;
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
	  if (vectorsofvectors.isempty() == 1)
	    {
	  vector <int> a;
	  vector <int> b;
	  vector <int> c;
	  a.push_back(0);
	  a.push_back(5);
	  a.push_back(11);
	  b.push_back(3);
	  b.push_back(0);
	  b.push_back(1);
	  c.push_back(7);
	  c.push_back(3);
	  c.push_back(0);
	  vectorsofvectors.push_back(a);
	  vectorsofvectors.push_back(b);
	  vectorsofvectors.push_back(c);
	  
	  cout << "----------------------------------------" << endl;
	  cout << "  " ;
	  
	  for(     vector<char*>::iterator v = vertex.begin(); v != vertex.end(); v++)
	    {
	      cout << *v <<" ";
	    }
	  cout << endl;
	  vector<char*>::iterator x = vertex.begin();
	  for (vector<vector<int> >::iterator it = vectorsofvectors.begin(); it != vectorsofvectors.end(); it++)
	    {
	      
	          
		  cout << *x << " ";
		  for (vector<int>::iterator itt = (*it).begin(); itt != (*it).end(); itt++)
		    {
		      cout << *itt << " ";
		    }
		  cout << endl;
		  x++;
	    }
	    }
	  else
	    {
	      cout << "There is no vertex in the graph creator" << endl;
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
