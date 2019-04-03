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

//void PrintTree (int intarray[]);
Node* insert(Node* head, Node* n);
void insert_repair_tree(Node* n);
void insert_case1(Node* n);
void insert_case2(Node* n);
void insert_case3(Node* n);
void insert_case4(Node* n);
void insert_case4step2(Node* n);
void insert_recurse(Node* head, Node* n);
//void print(Node* head, int printarray[], int i );
void printTree(char prefix[], Node* root, bool isLeft);
char* input;
char* numbers;
//Basically instead of putting it into .h and Node.cpp, define it here, so there is less pointers to be track of
// make it functions that return all these relationships..
//ideas borrowed from website that will be sited next to the insertion method
Node* grandparent(Node *n)
{
  Node* p = n->getParent();
  if (p == NULL)
    {
      return NULL;
    }
  else
    {
      return p->getParent();
    }
}
Node* sibling (Node* n)
{
  Node* p = n->getParent();
  if (p == NULL)
    {
      return NULL;
    }
  if (n == p->getLeft())
    {
      return p->getRight();
    }
  else
    {
      return p->getLeft();
    }
}
Node* uncle(Node* n)
{
  Node* p = n->getParent();
  Node* g = grandparent(n);
  if (g==NULL)
    {
      return NULL;
    }
  return sibling(p);
}
void rotate_left(Node* n)
{
  
  Node* p = n->getParent();
  Node* nnew = n->getRight();
  n->setRight(nnew->getLeft());
  nnew->setLeft(n);
  n->setParent(nnew);
  if(n->getRight() != NULL)
    {
      n->getRight()->setParent(n);
    }
  if (p != NULL)
    {
      if (n == p->getLeft())
	{
	  p->setLeft(nnew);
	}
      else if (n == p->getRight())
	{
	  p->setRight(nnew);
	}
    }
  nnew->setParent(p);
}
void rotate_right(Node* n)
{
  
  Node* p = n->getParent();
  Node* nnew = n->getLeft();
  n->setLeft(nnew->getRight());
  nnew->setRight(n);
  n->setParent(nnew);
  if(n->getLeft() != NULL)
    {
      n->getLeft()->setParent(n);
    }
  if (p != NULL)
    {
      if (n == p->getLeft())
	{
	  p->setLeft(nnew);
	}
      else if (n == p->getRight())
	{
	  p->setRight(nnew);
	}
    }
  nnew->setParent(p);
}
int main()
{
  //int red = 10024;
  //cout << "\033[1;31m" << red << " \033[0m\n";

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
	  cout << "PLEASE DO NOT ENTER #0" <<endl;
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
	      numbersofnumbers = size;
	      for (int i =0; i< size; i++)
		{
		  Node* n = new Node();
		  n->setValue(array[i]);
		  
		  head = insert(head, n);
		  
		}
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
	      
	      numbersofnumbers = size;
	      for (int i =0; i< size; i++)
		{
		  Node* n = new Node();
		  n->setValue(array[i]);
		  head = insert(head, n);
		}
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
	 
	  Node* n = new Node();
	  n->setValue(temp);
	  head = insert(head,n);
	  numbersofnumbers++;
	  //Singleadd
	}
      else if (b==2) // if the user wants to delete
	{
	  cout << endl;
	  /*
	    cout << "-----------------------------------------" << endl;
		  
		  
	    cout << "What's the number that you want to delete?"<<endl;
	    cout << endl;
	    int deleted = 0;
	    cin >> deleted;
	    cin.get();
	  
	    //delete
	    numbersofnumbers --;*/
	  cout << "deleteion doesn't work yet" << endl;
	}
      else if (b==3) // if the user wants to print
	{
	  cout << "-----------------------------------------" << endl;
	  char* str = new char[999];
	  str[0] = '\0';
	  printTree(str,head,false);
	  //This print function is not optimal for RBT go down to the function to see detail
	  /*
	    
	    for( int i = 0; i<= 998; i++)
	    {
	    printarray[i] = '\0';
	    }
	 
	    print(head,printarray,1);
	  
	    cout << endl;
	    if (head != NULL)
	    {
	    int numbers = 0;
	    for(int c = 0; c<= 998; c++)
	    {
	    if (printarray[c] != '\0')
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
	    if(printarray[c] == '\0')
	    {
	    printarray[c] = -999999;
	    }
	    }
	    }
	    for (int g = 0; g<= 998; g++)
	    {
		 
	    if(printarray[g] == '\0')
	    {
	    break;
	    }
	    //cout << printarray[g] << " ";
		  
	    }
	    cout << endl;
	    PrintTree(printarray);
		
	  */ 
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
//Following ideas and defining uncle, grandparent, at the beginning was borrowed from Red-Black Tree Wikipeadia with small adjustment due to different
//implementations of functions
//But I will still try my best to show my understanding
Node* insert(Node* head, Node* n) //insert a node, and we are gonna start from the head everytime a node is inserted and go down til the root
// after it's done pass the new Node back, idk why * & Node wouldn't work but this way does the same thing
{
  insert_recurse(head,n); // recursively go down the tree and insert the new Node at root
  insert_repair_tree(n); // fix all the cases where tree property is volated
  
  head = n; //set head = n, and keep going backward to find the ultimate head
  //this always makes n the head, if there wans't a head since in the insert recursion there isn't actually a case where head == NULL
  while(head->getParent() != NULL)
    {
      head = head->getParent();
    }
  return head; // return the final head

}
void insert_recurse(Node* head, Node* n) 
{
  if(head != NULL && n->getValue() < head->getValue()) // if the current node is not null (starting from the head), and the new num is
    //smaller than current node's value  
    {
      if (head->getLeft() != NULL) // then go left
	{
	  insert_recurse(head->getLeft(),n);
	  return;
	}
      else // if current->getLeft() is null then put the new node there 
	{
	  head->setLeft(n);
	}
    }
  else if (head != NULL) // same with left
    {
      if (head->getRight() != NULL)
	{
	  insert_recurse(head->getRight(), n );
	  return;
	}
      else
	{
	  head->setRight(n);
	}
    }
  n->setParent(head); //connect n with its parent
  n->setLeft(NULL);//set both its leaves null
  n->setRight(NULL);
  n->setColor(1); // new node is always red
}
void insert_repair_tree(Node* n) //now we fix the tree
{

  if (n->getParent() == NULL) // if n is the head, set it to Black
    {
      insert_case1(n); // since every new Node is red, if n is the head, make it black
    }
  else if (n->getParent()->getColor() == 0) // if n's parent is black, and n is red
    {
      insert_case2(n); // everything is fine
    }
  else if (uncle(n) != NULL && uncle(n)->getColor() == 1) // if n has an uncle and its uncle's color is red
    {
      insert_case3(n);
    }
  else
    {
      insert_case4(n); //the rest idrk how they work exactly, I know which cases rotates but I don't really know what the rotation would do to the tree
    }
}
void insert_case1(Node* n)
{
  if (n->getParent() == NULL)
    {
      n->setColor(0);
    }
}
void insert_case2(Node* n)
{
  return;
}
void insert_case3(Node* n)
{
  n->getParent()->setColor(0);
  uncle(n)->setColor(0);
  grandparent(n)->setColor(1);
  insert_repair_tree(grandparent(n));
}
void insert_case4(Node* n)
{
  Node* p = n->getParent();
  Node* g = grandparent(n);
  if (n==p->getRight() && p==g->getLeft())
    {
      rotate_left(p);
      n = n->getLeft();
    }
  else if ( n==p->getLeft() && p == g->getRight())
    { 
      rotate_right(p);
      n = n->getRight();
    }
  insert_case4step2(n);
}
void insert_case4step2(Node* n)
{
  Node* p = n->getParent();
  Node* g = grandparent(n);
  if (n ==p->getLeft())
    {
      rotate_right(g);
    }
  else
    {      
      rotate_left(g);
    }
  p->setColor(0);
  g->setColor(1);
}

//Because of my poor print function, I copied this from //https:
//Original idea from VasiliNovikov, saw this from Zareef
void printTree(char prefix[], Node* root, bool isLeft)
{
  char* prefix = NULL;
  if (root != NULL)
    {
      cout << prefix << (isLeft ? "  " : "  ") << Root->getValue() << endl;
    }
}




//This print function is poor for more than 6-7 rows of single digit numbers
//So probably 4-5 rows of 3-4 digits number would crash it
/*  
    void print(Node* head, int printarray[], int i)
    {
    if (head != NULL)
    {
    //cout << endl;
    //cout << "index: " << i-1 << ": " << head->getValue() << endl;

      
    if (head->getColor() == 1)
    {
    printarray[i-1] = -1* head->getValue();

    }
    else
    {
    printarray[i-1] = head->getValue();

    }
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


    void PrintTree(int intarray[])
    {
    //int intarray[999] =  {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,-1,'\0'};
    // people don't really print a tree from int array, but since different trees have different ways of sorting, it's hard to print from node. But feel free to just alter it, the essence of printing shouldn't chagne
    // enter the number in the intarray above to test.
    int longestnumber = 0; // keep track of the longest number in the entire tree
    for (int i = 0; i<= 998; i++)
    {
    if (intarray[i] != '\0') // go through the entire list. -2 by default means null in a tree, and -1 means the end of the list
    {
    if (log10(intarray[i]) +1 > longestnumber) //log10 of a numb + 1 gives the digits of numbers 
    {
    if(intarray[i] < 0)
    {
    longestnumber = log10(-1*intarray[i])+1; //keep track of the longest number til the end of list

    }
    else
    {
		 
    longestnumber = log10(intarray[i])+1; //keep track of the longest number til the end of list
 
    }
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
    if (intarray[i] != '\0')
    {
    //cout << intarray[i] << " ";
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
    //cout << newelementsindex[i] << endl;
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
    int l = 0;
    if(intarray[x] >0)
    {
    l = log10(intarray[x])+1; // this is to make sure everything has the same length
    }
    else
    {

    l = log10(-1*intarray[x])+1;
    }
    for(int b= 0; b<longestnumber-l; b++)
    {
    if (intarray[x] <0)
    {
		  
    cout << "\033[1;31m0\033[0m";// add a 0 if it has even nums of digits
    }
    else
    {
    cout << "0";
    }
    }
    if (intarray[x] < 0)
    {
    cout << "\033[1;31m" << -1* intarray[x] << " \033[0m" << endl;
    }
    else
    {
    cout << intarray[x] << endl;
    }
    a++;
    }
    else // if it's not a head
    {
    for (int i = 0; i <= length;) //since every row has a set amount of index, we use this to determine the end of a row
    {
    if (i == newelementsindex[a]) //all the elementsindex are the position of a num, aka the numbers of spaces
    { 
    if (intarray[x] == -999999) //-2 means null, if null just print the amount of space equal to the longest num
    {
		      
    for (int b =0; b< longestnumber; b++)
    {
    cout << " ";
    }
		      
    i+= longestnumber; // keep counting index for each row
    a++; //next position
    x++; //next number
    }
    else if (intarray[x] != '\0')
    {
    int  p = 0;
    if(intarray[x] <0)
    {
    p = log10(-1*intarray[x])+1; // p is the length of the current number
			
    }
    else
    {
			  
    p = log10(intarray[x])+1; // p is the length of the current number
			
    }
    if (p <= longestnumber) // if it's shorter
    {
    for (int b = 0; b< longestnumber-p; b++) // add 0s
    {
    if (intarray[x] < 0)
    {
				  
    cout << "\033[1;31m0\033[0m";
    }
    else
    {
    cout << "0" ;
    }
    // 1 -> 001 if the longest digit is 3
    }
    if (intarray[x] < 0)
    {
    cout << "\033[1;31m" << -1* intarray[x] << " \033[0m" ;
    }
    else
    {
    cout << intarray[x] ;
    }
			 
    i += longestnumber;
		  
    a++;
    x++;
    }
    }
    else //if it's '\0' it's at the end of the int array
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
*/


