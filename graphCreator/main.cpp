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
  
  queue<int> array[20];

  while (a != 4 )
    {
      
      cout << "Welcome to Cheng's Graph Creator!" << endl;
      cout << "To add a vertex, enter \"1\"." << endl;
      cout << "To add an edge, enter \"2\"." << endl;
      cout << "To delete an edge, enter \"3\"." << endl;
      cout << "To close the program, enter \"4\"." << endl;
      cin >> a;
      cin.get();

  
      if (a == 1) // add vertex
	{
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the vertex that you would like to add?" << endl;
	  input = new char[100];
	  cin.get(input,100);
	  cin.get();
	  cout << input << endl;
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
	}
      else
	{
	  return 0;
	}
  


    }
  
  
}
