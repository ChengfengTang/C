#include <iostream>
#include <cstring>
#include "Node.h"
#include <stack>
#include <queue>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <math.h>
using namespace std;

void PrintTree (int intarray[]);
void deleteNode(Node* & n, Node* &parent, Node* &head);
void findNode(Node* &head, int number, Node* &parent,int numbersofnumbers );
void buildTree(int array[], Node* &head, int size);
void add(Node* &head, int number);
void print(Node* head, int printarray[], int i );
char* input;
char* numbers;
int main()
{
  cout << "Welcome to Chengfeng Tang's Binary Search Project" << endl ;
  cout << "To start you would have to enter some numbers!" << endl;
  int a = 10;
  
  int array[999];
   int printarray[999];
   int numbersofnumbers = 0;
  Node* head = NULL;
  
  for (int abc = 0; abc <= 998; abc++)
    {
     array[abc] = -1;
    }
  
  
  while( a > 3 || a < 1)
    {
      
      cout << "--------------------------------------------" << endl;
      cout << "Enter 1 if you would like to enter the numbers manually." << endl;
      cout << "Enter 2 if you would like to read in a file with inputs." << endl;
      cout << "Enter 3 if you would like to close the program." << endl;
      
      cout << "--------------------------------------------" << endl;
      cin >> a;
      cin.get();

      input = new char[100];

      if (a == 1)
	{
	  
	  cout << "--------------------------------------------" << endl;
	  cout << "Please enter numbers with spaces between them (put a space after the last number)." << endl;
	  
	  cout << "--------------------------------------------" << endl;
	  cin.get(input,100);
	  cin.get();

	  int a  = strlen(input);
	  int sp = 0;
	  queue<int> spaces; // keep track of the digits of each number so I can directly read from the input array
	  // and turn them from separate numbers to one int
	  for (int y=0; y<a; y++)
	    {
	      if (input[y] == ' ') // if it's the end of a number
		{
		  if (sp!=0)  // push the numbers of digits to the queue
		    {
		      spaces.push(sp);
		      sp =0;

		    }

		}
	      else // else the digits ++
		{
		  sp += 1;
		}

	    }
	  int inputindex = 0; // keep track of the innput array
	  int arrayindex = 0; // keep track of the output array
	  int c = 0; // the number of spaces for a number
	  int d = 0; // the number
	  while (!spaces.empty())
	    {
	      c = spaces.front();
	      numbers = new char[100]; // a char array to help change each char to int
	      for (int y = 0; y<c; y++) // keep reading in from the input array until it reaches the size
		// of the number
		{
		  numbers[y] = input[inputindex];
		  inputindex ++; // put that number into the char array
		}
	      numbers[c] = '\0';
	      inputindex++;
	      spaces.pop(); // keep going through the space queue move on to the next int
	      d = atoi(numbers); // turn char array into a number
	      array[arrayindex++] = d; // add to the int array
	    }
	  
	  cout << "--------------------------------------------" << endl;
	  if (arrayindex == 0) // if the user didn't enter anything, let them retype
	    {
	  
	    }
	  else
	    {
	      cout << "The numbers are: " << endl;
	      for (int i = 0; i <= arrayindex-1; i++) // print the array  out
		{
		  cout << array[i] << " ";
		}
	      int size = arrayindex;
	      cout << endl;
	  
	      cout << "--------------------------------------------" << endl;
	      buildTree(array, head, size);
	      numbersofnumbers = size;
	    }
	}
      else if (a ==2)
	{
	  
	  cout << "--------------------------------------------" << endl;
	  cout << "please enter the name of the test file." << endl;
	  
	  cout << "--------------------------------------------" << endl;
	  cin.get(input,100);
	  cin.get();
	  ifstream myfile;
	  myfile.open(input);
	  // read in the name of the file, if failed to open close the program.
	  if (!myfile)
	    {
	      cout << "There is an error opening the file" << endl;
	      return 13;;
	    }
	  else
	    {
	      // if opens
	      
	      int size = 0; // index of the int array
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
	      // print the array
	      for (int i = 0; i< size; i++)
		{
		  cout << array[i] << " ";
	      
		}
	      cout << endl;
	      buildTree (array,head, size);
	      numbersofnumbers = size;
	      
	    }
	}
      else if (a == 3)
	{
	  cout << "Bye" << endl;
	  return 0;
	}
      else
	{
	  cout << "Invalid #" << endl;
	  cout << endl;
	}
      if (array[0] == -1)
	{
	  cout << "You didn't type in anything!" << endl;
	  a = 10;
	}
    }
  cout << endl;

  // now we have a basic tree, we can start doing stuff with it.
  int b = 0;
  while (b != 4)
    {
      cout << "--------------------------------------------" << endl;
      cout << "There are currently " << numbersofnumbers << " nodes" << endl;
      cout << "Now if you would like to add a Node, enter 1" << endl;
      cout << "If you would like to delete a Node, enter 2" << endl;
      cout << "If you would like to print the tree, enter 3" << endl;
      cout << "If you would like to exit, enter 4" << endl;
      
      cout << "--------------------------------------------" << endl;
      cin >> b;
      cin.get();
      if (b == 1)
	{ // if the user wants to add then add on to the array
	  cout << endl;
	  cout << "What's the number that you want to add?" << endl;
	  
	  cout << "--------------------------------------------" << endl;
	  
	  int temp = 0;
	  cin >> temp;
	  cin.get();
	 
	  add ( head, temp);
	  numbersofnumbers++;
	  //Singleadd
	}
      else if (b==2) // if the user wants to delete
	{
	  cout << endl;
	  cout << "-----------------------------------------" << endl;
		  
		  
	  cout << "What's the number that you want to delete?"<<endl;
	  cout << endl;
	  int deleted = 0;
	  cin >> deleted;
	  cin.get();
	  
	  findNode(head, deleted, head, numbersofnumbers);
	  numbersofnumbers --;
	}
      else if (b==3) // if the user wants to print
	{
	  cout << "-----------------------------------------" << endl;
	  for( int i = 0; i<= 998; i++)
	    {
	      printarray[i] = -1;
	    }
	 
	  print(head,printarray,1);
	  
	  cout << endl;
	  if (head != NULL)
	    {
	      int numbers = 0;
	      for(int c = 0; c<= 998; c++)
		{
		  if (printarray[c] != -1)
		    {
		      numbers ++;
		    }
	      
	    
		  if (numbers == numbersofnumbers)
		    {
		      numbers = c;
		      break;
		    }
		  else
		    {
		      if(printarray[c] == -1)
			{
			  printarray[c] = -2;
			}
		    }
		}
	      for (int g = 0; g<= 998; g++)
		{
		  //  cout << printarray[g] << " ";
		}
	  
	      PrintTree(printarray);
	  
	  
	}
      else if (b==4)
	{
	  cout << "bye" << endl;
	  return 0;
	}
      else
	{
	  cout << "Invalid #" << endl;
	  cout << endl;
	}
      




    }
  
    }
}
void print(Node* head, int printarray[], int i)
{
  if (head != NULL)
    {
      //cout << endl;
      //cout << "index: " << i-1 << ": " << head->getValue() << endl;
      
      printarray[i-1] = head->getValue();
      
      cout <<  head->getValue() << endl;
      if (head->getLeft() != NULL)
	{
	   cout << "Left of " << head->getValue() << " : " ;
	  print(head->getLeft(), printarray, i*2);
	  
	}
      if (head->getRight() != NULL)
	{
	  cout << "Right of " << head->getValue() << " : " ;
	  print(head->getRight(), printarray, i*2+1);
      
	}
    }
  else
    {
      cout << "You don't have any numbers in the tree" << endl;
    }
  
  
  
 
}

void findNode(Node* &head, int number, Node* &parent, int numbersofnumbers)
{
  if (head != NULL)
    {
      // go through all the nodes, and find the one that matches it, (not sure what would happen if there is two of the same node)
      Node* current = head;
      if (current->getValue() != number)
	{
	  if(number <= current->getValue())
	    {
	      if (current->getLeft() != NULL)
		{
		  Node* next = current->getLeft();
		  findNode(next,number,current,numbersofnumbers );
		}
	      else
		{
		  cout << "No such number exists" << endl;
		}
	    }
      
	  else if (number > current->getValue())
	    {
	      if (current->getRight() != NULL)
		{
		  Node* next = current->getRight();
		  findNode(next,number,current, numbersofnumbers );
		}
	      else
		{
	      
		  cout << "No such number exists" << endl;
		}
	    }
	}
      else
	{
	  numbersofnumbers = numbersofnumbers - 1;
	  deleteNode(current, parent, head);
	  
	}
    }
  else
    {
      cout << "You don't have any numbers in the tree!" << endl;
     
    }
}
void deleteNode(Node* & n, Node* & parent, Node* & head)
{
  cout << "Node with number: " << n->getValue() << " has been deleted" << endl;
  //4 senarios, leaf, node with 1 left, node with 1 right, node with 2 children but right has no left children, node with two children...    
  if ((n->getLeft() == NULL) && (n->getRight() == NULL))
    {
      //if it's a leaf, just disconnect it wiht its parent and delete it
      if(parent->getLeft() == n)
	{
	  parent->setLeft(NULL);
	  cout << "Parent Node: " << parent->getValue() << "  no longer has a left child of: " << n->getValue() << endl;;
	      
	  cout << "-----------------------------------------" << endl;

	}
      else if(parent->getRight() == n)
	{
	  parent->setRight(NULL);
	  cout << "Parent Node: " << parent->getValue() << "  no longer has a right child of: " << n->getValue() << endl;;
	      
	  cout << "-----------------------------------------" << endl;

	}
      else if (n == head)// this only happenes when parent = n, which is when this is the head
	{
	     
	  cout << "Head Node: " << head->getValue() << "  was deleted" << endl;;
	  head = NULL;
	  cout << "-----------------------------------------" << endl;
	  
	    
	}
       
	  
    }
  else if  (n->getLeft() == NULL)
	{
	  // if the number only has a right child, go right once and go as left as possible
	  Node* bye = n->getRight();
	  Node* byeparent = n;
	  while(bye->getLeft() != NULL)
	    {
	      byeparent = bye;
	      bye = bye->getLeft();
		  
	    }
	  Node* temp = new Node();

	  if (bye == n->getRight())
	    {
	      

	    }
	  else
	    {
	  if (bye->getRight()!= NULL)
	    {
	      temp = bye->getRight();
	    }
	      
	  
	  //disconnect bye with its parent
	  if(byeparent->getLeft() == bye)
	    {
	      if (bye->getRight() != NULL)
		{
		  byeparent->setLeft(temp);
		  cout << "Parent Node: " << byeparent->getValue() << " now has a left child of: " << temp->getValue() << endl;
		}
	      else
		{
	      
	      byeparent->setLeft(NULL);
	      cout << "Parent Node: " << byeparent->getValue() << "  no longer has a left child of: " << bye->getValue() << endl;;
		}
	    }
	   bye->setRight(n->getRight());
	  cout << "Number: " << bye->getValue()  <<" will replace node: " << n->getValue() << " With a right child of: "<< n->getRight()->getValue() << endl;
	    }
	  // now put bye at n's position
	  if(parent->getLeft() == n)
	    {
	      parent->setLeft(bye);
	      cout << "Parent Node: " << parent->getValue() << "  now has a left child of: " << bye->getValue() << endl;;
	      
	      cout << "-----------------------------------------" << endl;
	      
	      n->setRight(NULL);
	      delete n;
	      
	    }
	  else if(parent->getRight() == n)
	    {
	      parent->setRight(bye);
	      cout << "Parent Node: " << parent->getValue() << "  now has a right child of: " << bye->getValue() << endl;;
	      
	      cout << "-----------------------------------------" << endl;
	      
	      n->setRight(NULL);
	      delete n;
	      	    }
	  else //n is the head
	    {
	      head = bye;
	    }
	    
	      
	      
	}
      
      else //if (n->getRight() == NULL)
	{
	  // if the number only has a left child or both children, go left once and go as right as possible
	  Node* bye = n->getLeft();
	  Node* byeparent = n;
	  while(bye->getRight() != NULL)
	    {
	      byeparent = bye;
	      bye = bye->getRight();
		  
	    }
	  Node* temp = new Node();

	  //disconnect bye with its parent
	  if (byeparent != n )
	    {
	  if (bye->getLeft()!= NULL)
	    {
	      // if bye has any left child
	      temp = bye->getLeft();
	  
	    }
	  

	  if (n->getRight() != NULL)
	    {
	      bye->setRight(n->getRight());
	      
	  cout << "Number: " << bye->getValue()  <<" will replace node: " << n->getValue() << " With a right child of: "<< n->getRight()->getValue() << endl;
	      
	    }
	  
	  if(byeparent->getRight() == bye)
	    {
	      //since bye is the most right child, if bye has any left child make that the right child of bye's parent
	      if (bye->getLeft() != NULL)
		{
		  
		  byeparent->setRight(temp);
		  cout << "Parent Node: " << byeparent->getValue() << " now has a right child of: " << temp->getValue() << endl;
		    
		    }
	      else
		{
	      byeparent->setRight(NULL);
	      cout << "Parent Node: " << byeparent->getValue() << "  no longer has a right child of: " << bye->getValue() << endl;;
		}
	    }
	      bye->setLeft(n->getLeft());
	  
	      cout << "Number: " << bye->getValue()  <<" will replace node: " << n->getValue() << " With a left child of: "<< n->getLeft()->getValue() << endl;
	    }
	  else
	    {
	      
	  if (n->getRight() != NULL)
	    {
	      bye->setRight(n->getRight());
	      
	  cout << "Number: " << bye->getValue()  <<" will replace node: " << n->getValue() << " With a right child of: "<< n->getRight()->getValue() << endl;
	      
	    }
	  
	    }
	  
	      
	    
	  
	  // now put bye at n's position
	  if(parent->getLeft() == n)
	    {
	      parent->setLeft(bye);
	      cout << "Parent Node: " << parent->getValue() << "  now has a left child of: " << bye->getValue() << endl;;
	      
	      cout << "-----------------------------------------" << endl;
	      if (n->getRight() != NULL)
	      {
	        n->setRight(NULL);
	      }
	      n->setLeft(NULL);
	      delete n;
	      
	    }
	  else if(parent->getRight() == n)
	    {
	      parent->setRight(bye);
	      cout << "Parent Node: " << parent->getValue() << "  now has a right child of: " << bye->getValue() << endl;;
	      
	      cout << "-----------------------------------------" << endl;
	      if (n->getRight() != NULL)
	      {
	        n->setRight(NULL);
	      }
	      n->setLeft(NULL);
	      delete n;
	      	    }
	  else
	    {
	      head = bye;
	    }
	      
	}
}
         

void add(Node* &head, int number)
{
  
  cout << "--------------------------------------------" << endl;
  if (head != NULL)
    {
      Node * current = head;
      while (head != NULL)
	{
	  if (number <= current->getValue())
	    {
	      if (current->getLeft() == NULL)
		{
		  cout << "left of " << current->getValue() << ": " << number << endl; 
		  Node* node = new Node();
		  node->setValue(number);
		  current->setLeft(node);
		  break;
		}
	      else
		{
		      
		  current = current->getLeft();

		}
	    }
	  else if (number > current->getValue())
	    {
	      if (current->getRight() == NULL)
		{
		  cout << "Right of " <<current->getValue() << ": " << number << endl; 
		  Node* node = new Node();
		  node->setValue(number);
		  current->setRight(node);
		  break;
		}
	      else
		{
		  current = current->getRight();
		}
	    }
	}
    }
  else
    {
           
      Node* whatever = new Node;
      whatever->setValue(number);
      head = whatever;
    }
	  
  
}


void buildTree (int array[], Node* &head, int size)
{
  
  cout << "--------------------------------------------" << endl;
  cout << "There are " << size << " nodes" << endl;
  /*for (int i =0 ; i<=size-1; i++)
    {
    cout << array[i] << " ";
    }
    cout << endl;*/
  cout << "--------------------------------------------" << endl;
  for (int i = 0; i <= size-1; i++)
    {
      if (head == NULL)
	{
	  Node* temp = new Node;
	  temp->setValue(array[i]);
	  head = temp;
	  
	  cout << "head: " << head->getValue() << endl;
	}
      
      else
	{
	  Node * current = head;
	  while (head != NULL)
	    {
	      if (array[i] <= current->getValue())
		{
		  if (current->getLeft() == NULL)
		    {
		      cout << "left of " << current->getValue() << ": " << array[i] << endl; 
		      Node* node = new Node();
		      node->setValue(array[i]);
		      current->setLeft(node);
		      break;
		    }
		  else
		    {
		      
		      current = current->getLeft();

		    }
		}
	      else if (array[i] > current->getValue())
		{
		  if (current->getRight() == NULL)
		    {
		      cout << "Right of " <<current->getValue() << ": " << array[i] << endl; 
		      Node* node = new Node();
		      node->setValue(array[i]);
		      current->setRight(node);
		      break;
		    }
		  else
		    {
		      current = current->getRight();
		    }
		}
	    }
	    
          
	}
    }
  
}

void PrintTree(int intarray[])
{
 //int intarray[999] =  {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,-1,'\0'};
  // people don't really print a tree from int array, but since different trees have different ways of sorting, it's hard to print from node. But feel free to just alter it, the essence of printing shouldn't chagne
  // enter the number in the intarray above to test.
  int longestnumber = 0; // keep track of the longest number in the entire tree
  for (int i = 0; i<= 998; i++)
    {
      if (intarray[i] != -1) // go through the entire list. -2 by default means null in a tree, and -1 means the end of the list
	{
	  if (log10(intarray[i]) +1 > longestnumber) //log10 of a numb + 1 gives the digits of numbers 
	    {
	      longestnumber = log10(intarray[i])+1; //keep track of the longest number til the end of list
	    }
	}
      else
	{
	  break;
	}
    }
  // the longestnumber will be used to determine the length of every single number
  if (longestnumber %2 == 0) // make sure every number has a odd length, since there isn't a "center" for even digits
    {
      longestnumber ++;
    }
  //cout << "The longestnumber in the array list has a digit of: " << longestnumber << endl;
  
  int numbers = 0;
  for ( int i = 0; i <= 998; i++)
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
  // print out all the valid numbers, which are non -1s and keep track of the numbers of elements in the tree
  cout << "There are " << numbers << " numbers in the tree." <<endl;
  cout << endl;
  
  //calculate # of rows
  int rows =  log2(numbers) + 1; // 1 row has 1 number which is 2 to the 0 power+1. 2 rowshave 3 number which is 2 to the 1 power +1
   
  int indexbegin = pow(2,rows-1) -1;  // if there are 3rows, the bottom row should start at index 3 which is the 4th element
  int indexend = pow(2,rows) -2; // and ends at 6, which is the 7th element
  //if there are 4 rows, the bottom row should start at index 7, which is the 8th element
  //and end at 14, the 15th element
  
  int arrayindex = 0; // keep track of the elements' positions in the elementsindex
  int numberofpositions = indexend+1; // this is the number of positions the tree should contain, including spaces, basically
  // if a tree has 3 rows, it should have 7 numbers despite empty / null
  int elementsindex [numberofpositions] = {}; //basically where all the elements should be

  for (int i = 1; i<= (indexend - indexbegin +1); i++ ) // this calculate all of the bottom row's position
  {
  int position = ((i-1) * longestnumber) + (i-1)* 1 ; // 1 here is spacing between each element
  elementsindex[arrayindex] = position;    
  //cout << elementsindex[arrayindex] << endl;
  arrayindex++;
      
  }
  //calculate everything above this level now
  //basically, if the bottom row has 4 numbers, add up 1 and 2 to get 5, 3 and 4 to get 6, and add up 5 and 6 to get 1
  // when there is only 1 being added, that's the head and the last row since we are going backward.
  int initialindex = 0; 
  int maxindex = pow(2,rows-1)-1; // since we are starting from the last row, the max index should start from the number of elements of the bottom row
  for(int r = rows; r > 1; r--) //let's imagine there is 3 rows, which therefore 7 elements and a max index of 3, init of 0
    {
      for ( int i = initialindex;  i<= maxindex ; i++) // go from 0 to 3
	{
	  if (i%2 == 0 ) //if the number is even add this number and the previous one to calculate the position of the element in the next row
	    {     
	      int newnum =  (elementsindex[i] + elementsindex[i+1])/2;
	      elementsindex[arrayindex] = newnum; // add it to the elementsindex
	      arrayindex++;
	    }
	}
      initialindex = maxindex +1; // now initial index becomes max index + 1, so 4 in this case
      maxindex += pow(2,r-2); // and max index becomes 5, add by number of elements in the upcoming row, which is 2 for the second row
    }
  elementsindex[arrayindex] == '\0';
  
  // now we have the position for each number, we just need to print it!
  //but since we worked our way from the bottom, to print the tree would be backward, now let's flip it
  int newelementsindex [arrayindex] = {}; //printing in the right order
  int newarrayindex = 0; // keep track of the new array
  
  initialindex = arrayindex-1; // again let's imagine it's a perfect 3 rows binary tree
  maxindex = arrayindex-1; // the intial would then be 6, since there is 7 elements, and the max would also be 6 since the head always has one number.
  for (int r = 1; r<= rows; r++) //starting from row 1, which is the head
	{
	  for( int i = initialindex; i <= maxindex; i++)
	    {
	      newelementsindex[newarrayindex++] = elementsindex[i]; //add that to the new elementsindex 
	      //cout << elementsindex[i] << endl;
	    }
	  initialindex -= pow(2,r);
	  //cout << "init" << initialindex << endl;//go backward more, for example the intial should start at 4
	  maxindex -= pow(2,r-1);
	  //cout << "max: " << maxindex << endl;// and max should start at 5
	}
  newelementsindex[newarrayindex] == '\0';
  
  for (int i = 0; i<= newarrayindex -1; i++)
    {
      cout << newelementsindex[i] << endl;
    }
  //actual time to print
  int length = longestnumber*pow(2,rows-1) + (pow(2,rows-1) * 1 -1) - 1; // calculate the length of each row
  //imagine a 3 rows binary search tree with 3 digits numbers. that would just be 3 * 4 + 3 spaces = 15units, however since we are gonna be dealing with indexes, I am just gonna put an extra -1, so that the max index is actually 14
  cout << "Every row should have a index length of: " << length << endl;

  
  int a = 0;//basically a index indicator that helps me run through the program
  for (int j = 1; j <= rows; j++) // starting from the first row
    {
      int x = pow(2,j-1) -1; // x is basically the int array index indicator
      if (x == 0) // if this is the head
	{
	  for (int i = 0; i < newelementsindex[a]; i++)//keep the spacing
	    {
	      cout <<" ";
	    }
	  int l = log10(intarray[x])+1; // this is to make sure everything has the same length
	  for(int b= 0; b<longestnumber-l; b++)
	    {
	      cout << "0" ; // add a 0 if it has even nums of digits
	    }
	  cout << intarray[x] << endl;
	  a++;
	}
      else // if it's not a head
	{
	  for (int i = 0; i <= length;) //since every row has a set amount of index, we use this to determine the end of a row
	    {
	      if (i == newelementsindex[a]) //all the elementsindex are the position of a num, aka the numbers of spaces
		{ 
		  if (intarray[x] == -2) //-2 means null, if null just print the amount of space equal to the longest num
		    {
		      for (int b =0; b< longestnumber; b++)
			{
			  cout << " ";
			}
		      i+= longestnumber; // keep counting index for each row
		      a++; //next position
		      x++; //next number
		    }
		  else if (intarray[x] != -1)
		    {
		      int p = log10(intarray[x])+1; // p is the length of the current number
		      if (p <= longestnumber) // if it's shorter
			{
			  for (int b = 0; b< longestnumber-p; b++) // add 0s
			    {
			      cout << "0"; // 1 -> 001 if the longest digit is 3
			    }
			  cout << intarray[x];
			  i += longestnumber;
		  
			  a++;
			  x++;
			}
		    }
	      	  else //if it's -1 it's at the end of the int array
		    {
		      break;
		    }
		}
	      else //if there isn't a number at the current i position, just print space and keep going
		{
		  cout <<" ";
		  i ++;
		}
	    }
	  cout << endl; //move on to next row if current row is full
	}
    }
}



