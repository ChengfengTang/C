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

  cout << "Welcome to Cheng's Graph Creator!" << endl;

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
  
  while (a != 7 )
    {
      
      cout << "To add a vertex, enter \"1\"." << endl;
      cout << "To add an edge, enter \"2\"." << endl;
      cout << "To delete a vertex, enter \"3\"." << endl;
      cout << "To delete an edge, enter \"4\"." << endl;
      cout << "To see the adjacency matrix, enter \"5\"." << endl;
      cout << "To find the closest path between two nodes, enter \"6\"." << endl;
      cout << "To close the program, enter \"7\"." << endl;
      
      cout << "----------------------------------------" << endl;
		 
      cin >> a;
      cin.get();

      
      if (a == 1) // add vertex
	{
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the vertex that you would like to add?" << endl;
	  
	  cout << "----------------------------------------" << endl;
		 
	  input = new char[100];
	  cin.get(input,100);
	  cin.get();
	  
	  
	  if(vertex.size() != 0)
	    {
	      int z = 0;
	      for( z = 0; z <= vertex.size()-1; z++)
		{
		  
		  if (strcmp(vertex[z] , input ) == 0)
		    {	      
		      break;
		    }
		}
	      if ((z <= vertex.size()-1)) // just to make sure that the node is not even on the list, the counter would
		// therefore, be greater than the index
		{
		  cout << "----------------------------------------" << endl;
		 
		  cout << "The Node already exists in the graph creator." << endl;
		  cout << "----------------------------------------" << endl;
		}
	      else
		{
		  cout << "----------------------------------------" << endl;
		  cout << "Vertex " << input << " is created. " << endl;
		  vertex.push_back(input); // put this in the vector of all nodes
		  arr[vertex.size()-1][vertex.size()-1] = 0; //the distance of a node to itsself is always 0
		  cout << "----------------------------------------" << endl;
		}
	      
	    }
	  else
	    {
	      cout << "----------------------------------------" << endl;
	      cout << "Vertex " << input << " is created. " << endl;
	      vertex.push_back(input); // put this in the vector of all nodes
	      arr[vertex.size()-1][vertex.size()-1] = 0; //the distance of a node to itsself is always 0
	      cout << "----------------------------------------" << endl;
	    
	    }
	}
      else if (a == 2)
	{
	  start = new char[100];
	  end = new char[100];
	  int weight = 0;
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the starting vertex?" << endl;
	  
	  cout << "----------------------------------------" << endl;
		 
	  cin.get(start,100);
	  cin.get();
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the ending vertex?" << endl;
	  
	  cout << "----------------------------------------" << endl;
		 
	  cin.get(end,100);
	  cin.get();
	  cout << "----------------------------------------" << endl;
	  cout<< "What's the weight of the edge going from " << start << " to " << end << " ?" << endl;
	  
	  cout << "----------------------------------------" << endl;
		 
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
	      if (q > vertex.size()-1) // just to make sure that the node is not even on the list, the counter would
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
	  //delete a vertex
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the vertex that you would like to delete?" << endl;
	  
	  cout << "----------------------------------------" << endl;
		 
	  input = new char[100];
	  cin.get(input,100);
	  cin.get();
	  
	  
	  if(vertex.size() != 0)
	    {
	      int z = 0;
	      for( z = 0; z <= vertex.size()-1; z++)
		{
		  
		  if (strcmp(vertex[z] , input ) == 0)
		    {	      
		      break;
		    }
		}
	      if ((z <= vertex.size()-1)) // just to make sure that the node is not even on the list, the counter would
		// therefore, be greater than the index
		{
		  cout << "----------------------------------------" << endl;
		 
		  cout << "Vertex " << input << " has been deleted" << endl;
		  //delete it frrom the vector first then fix the tree
		  vertex.erase(vertex.begin() + z);
		  
		  for(int i = 0; i < vertex.size(); i++ )
		    {
		      //cout << vertex.at(i) << endl;
		      
		    }
		  //if deleted vertex is the last one in the list, then just set that row and column to -1
		  if ( z == vertex.size()-1)
		    {
		      for(int i = 0; i< vertex.size(); i++)
			{
			  arr[z][i] = -1;
			}
		      for( int  k = 0; k < vertex.size(); k++)
			{
			  arr[k][z] = -1;
			}
		    }
		  
		  //else fill the blank with stuff afterward
		  else
		    {

		    }
		  cout << "----------------------------------------" << endl;
		}
	      else
		{
		  cout << "----------------------------------------" << endl;
		  cout << "Vertex " << input << " does not exist! " << endl;
		  cout << "----------------------------------------" << endl;
		}
	      
	    }
	  else
	    {
	      cout << "----------------------------------------" << endl;
	      cout << "There is no vertex at all! " << endl;
	      cout << "----------------------------------------" << endl;
	    
	    }
	}
      else if (a == 4)
	{
	  start = new char[100];
	  end = new char[100];
	  int weight = 0;
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the starting vertex?" << endl;
	  
     	  cout << "----------------------------------------" << endl;
		 
	  cin.get(start,100);
	  cin.get();
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the ending vertex?" << endl;
	  cout << "----------------------------------------" << endl;
		 
	  cin.get(end,100);
	  cin.get();
	  
	  if (strcmp(start,end) == 0) // can not connect a node with it self
	    {
	      cout << "----------------------------------------" << endl;
	      cout << "Can't delete a Node's connection to itself. "  << endl;
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
	      if (q > vertex.size()-1) // just to make sure that the node is not even on the list, the counter would
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
	  
		  arr[q][w] = -1;
	      
		  cout << "----------------------------------------" << endl;
		  cout << "The weight that goes from "<< start << " to " << end << " is deleted" << endl;
		  cout << "----------------------------------------" << endl;
		}
	    }
	}
      else if (a == 5)
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
      else if (a == 6 )
	{
	  start = new char[100];
	  end = new char[100];
	  int weight = 0;
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the starting vertex?" << endl; 
          cout << "----------------------------------------" << endl;
		 
	  cin.get(start,100);
	  cin.get();
	  cout << "----------------------------------------" << endl;
	  cout << "What's the name of the ending vertex?" << endl;
      	  cout << "----------------------------------------" << endl;
	  cin.get(end,100);
	  cin.get();	 
	 
	  if (strcmp(start,end) == 0) // can not connect a node with it self
	    {
	      cout << "----------------------------------------" << endl;
	      cout << "A node's distance to itself is always 0. "  << endl;
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
	      if (q > vertex.size()-1) // just to make sure that the node is not even on the list, the counter would
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
	      else
		{
		  // a queue for all the path
		  int size = vertex.size();
		  int arra [size][size];
		  int go = q;
		  
		  int stop = w;
		  
		  for(int i = 0; i< size; i++)
		    {
		      for(int k = 0; k< size; k++)

			{
			  arra[i][k] = -1;
			}
		      
		    }
	      
		  int shortest = 0;
		      int index = go;
		      int indexx = 0;
		     		      vector <int> whereihavebeen;
		      for(int i =0; i<size; i++) // do this 5 times becuase we will be filling5 rows
		    {
		      //cout << "Trial: " << i + 1 << endl;
		      //cout <<"Index: " << index << endl;
		      //cout << "Indexx: " << indexx << endl;
		      //cout << "Shortest: " << shortest << endl;
		      //cout << "Size: " << size << endl;
		       // arr original arra new
		      for(int k = 0; k < size; k++) // for each row,
			{
			  if(arr[index][k] != -1) // if the original distance is not null
			    {
			      if ((i == 0) || (arra[i-1][k] == -1))
				{
		      	    arra[indexx][k] = arr[index][k] + shortest;
			    // cout << arr[index][k] <<" + " << shortest << " = " << arra[i][k] << endl;
			     
				}
			      else
				{
				  arra[indexx][k] = arr[index][k] + shortest;
				  //cout << arr[index][k] <<" + " << shortest << " = " << arra[i][k] << endl;
				
				  if (arra[indexx][k] > arra[indexx-1][k])
			
				    {
				      arra[indexx][k] = arra[indexx-1][k];
			       
				      //      cout << "same as last row" << endl;
				    }
				}
			     			      // the new distance will be filled with original distance + shortest path
			      // for example;
			      /*

				down below is the distance               down below is the shortest distance from 
				  from single node to single node      a node to all its path
				   A B C  D  E                       A B C D  E
			        A  0 4 2 -1 -1                     A 0 4 2 -1 -1         
                                                                   right here, the shortet path is 0, since we are starting from A andd A-> A is 0, so everything is the same
				                                   therefore, we go through the list and figure out that C is the next one, so index would then be 2 since A = 0 B =1 C =2 D = 3

				B -1 0 3  2  3                     C 0 3 2 6 7				                                   
                                                                   now the shortest becomes 2, because we are calculating from A->C->everynode, since C->B is 1 A->C->B = 3 and therefore replaced


				C -1 1 0  4  5                     B 0 3 2 5 6 
				D -1 -1 -1 -1 -1                   D 0 3 2 5 6 
				E -1 -1 -1 1  0                    E 0 3 2 5 6 

			       */
			    }
			  else if (i != 0)
			    {
			      arra[indexx][k] = arra[i-1][k];
			      //  cout << "same as last row: " << arra[i-1][k] << endl;
			    }
			  else
			    {
			      //cout << "-1" << endl;
			    }
			  
			
			}
		      
		      
		      whereihavebeen.push_back(index);
		      shortest = 999;
		      for (int xd = 0; xd < whereihavebeen.size(); xd++ )
			{
			  //   cout << "I have been to: " << whereihavebeen.at(xd) << endl;
			}
		      int yesno = 0;
		      for(int k = 0; k < size; k++)
			{
			  yesno = 0;
			  for (int gg = 0; gg < whereihavebeen.size(); gg++ )
			    {
			     
			      if (k - (whereihavebeen.at(gg)) == 0 )
			      {
			        yesno = 1;
				
			      }
			    }
			  			  
			  if ((arra[indexx][k] > 0 ) && (arra[indexx][k] < shortest) && (yesno == 0))
			    {
			      shortest = arra[indexx][k];
			      index = k;
				  
			      //cout << "new shortest " << shortest << " at " << index << endl;
			    }
			  else if ((arra[indexx][k] > 0) && (shortest == 999 ) && (yesno == 0))
			    {
			      shortest = arra[indexx][k];
			      index = k;
				  
			      //  cout << "new shortest " << shortest << " at " << index << endl;
			    }
			 
		    
			  
			    

			} 
		    
		      indexx++;
		     
		  
		    }
		             
		  for(int i = 0; i< size; i++)
		    {
		      for(int k = 0; k< size; k++)

			{
			  // cout << arra[i][k] << " ";
			}
		      cout << endl;
		    }
		
	  cout << "----------------------------------------" << endl;

	  if (arra[size-1][stop] == -1)
	    {
	      cout << "No possible path" << endl;
	      
	    }
	  else
	    {
	
	      int weight = 9999999;
	      cout << vertex.at(go); 
		  for(int l = 0; l < whereihavebeen.size(); l++)
		    {
		      if (l == 0)
			{
			  weight =  arra[l][stop] ;
			}
		      else
			{
			  if (arra[l][stop] != arra[l-1][stop])
			    {
			      cout << "->" << vertex.at(whereihavebeen.at(l));
			      weight = arra[l][stop];
			    }
			}
			 
		    }
		  
		  cout << "->" << vertex.at(stop);
		  cout << " Weight: " << weight << endl;
	    }
	  cout << "----------------------------------------" << endl;
	 	  
		  
		}
	    }
	}
      else if (a == 7)
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
