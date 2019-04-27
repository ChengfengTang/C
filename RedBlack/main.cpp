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

Node* insert(Node* head, Node* n);
Node* search(Node* n, int number);
void insert_repair_tree(Node* n);
void insert_case1(Node* n);
void insert_case2(Node* n);
void insert_case3(Node* n);
void insert_case4(Node* n);
void insert_case4step2(Node* n);
void insert_recurse(Node* head, Node* n);
int big_delete(Node* head, int number, int numbersofnumbers);
//void print(Node* head, int printarray[], int i );
void printTree(char prefix[], Node* root, bool isLeft);
void delete_case1(Node* n);
void delete_case2(Node* n);
void delete_case3(Node* n);
void delete_case4(Node* n);
void delete_case5(Node* n);
void delete_case6(Node* n);
void detailed_info(Node* head);
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
  while (b != 5)
    {
     
      cout << "--------------------------------------------" << endl;
      cout << "There are currently " << numbersofnumbers << " nodes" << endl;
      cout << "Now if you would like to add a Node, enter 1" << endl;
      cout << "If you would like to delete a Node, enter 2" << endl;
      cout << "If you would like to print the tree, enter 3" << endl;
      cout << "If you would like to search for a Node, enter 4" << endl;
      cout << "If you would like to exit, enter 5" << endl;
      
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
	  cout << "What's the number that you want to delete? " <<endl;
	  cout << "-----------------------------------------" << endl;
	  int number = 0;
	  cin >> number;
	  cin.get();
	  numbersofnumbers = big_delete(head,number,numbersofnumbers);
	  
	}
      else if (b==3) // if the user wants to print
	{
	  cout << "-----------------------------------------" << endl;
	  if (numbersofnumbers != 0)
	    {
	  char* str = new char[999];
	  str[0] = '\0';
	  printTree(str,head,false);
	  delete[] str;
	    }
	  else

	    {
	      cout << "You don't have any Node in the tree!" << endl;
	    }
	  
	}
      else if( b == 4)
	{
	  cout << endl;
	  cout << "What's the number that you are looking for? " <<endl;
	  cout << "-----------------------------------------" << endl;
	  int number = 0;
	  cin >> number;
	  cin.get();
	  if( search(head,number) == NULL)
	    {
	      cout << "The Node does not exist in the tree!" << endl;
	    }
	  else
	    {
	      cout << "The Node exists in the tree!" << endl;
	    }
	}
      else if (b==5)
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
Node* inOrderSuccessor(Node* n)
{
  if(n->getRight() != NULL)
    {
      Node* ios = n->getRight();
      while(ios->getLeft() != NULL)
	{
	  ios = ios->getLeft();
	}
      return ios;
    }
  else if (n->getLeft() != NULL)
    {
      Node* pds = n->getLeft();
      while (pds->getRight() != NULL)
	{
	  pds = pds->getRight();
	}
      return pds;
    }
  else
    {
      return n;
    }
    
}
int big_delete(Node* head, int number, int numbersofnumbers)
{
 
  Node* n = search(head, number);
  if (n != NULL)
    {
      cout << endl;
      
      // find the inorder successor, swap it with the node that's about to be deleted
      // and fix the tree.
      Node* ios = inOrderSuccessor(n);
      cout <<"n:"  << n->getValue() << endl;
      cout << "ios: " << ios->getValue() << endl;
      cout << endl;
    
      //cite en.wikipedia.org/wiki/Red-black_tree for part of deletion algorithm and ideas

      // case 1 deletng head
      if (n == head && ios == n) 
	{
	  cout << "case 0 " << endl;
	  cout << "Deleting the only Node in the tree" << endl;
	      
	  cout << endl;
	  head = NULL; // set head null
	  delete n;
	    
	}   
      else 
	{
	  n->setValue(ios->getValue());
	  // if ios has a right child and ios is red, then just replace ios's right child with ios
	  // deleting a red node doesn't m atter
	  Node* iosc = new Node;
	  if (ios->getRight() != NULL)
	    {
	      iosc = ios->getRight();
	    }
	  else if(ios->getLeft() != NULL) 
	    {
	      iosc = ios->getLeft();
	    }
	  else
	    {
	      
	      iosc->setValue(-1);
	      iosc->setColor(0);
	    }
	  
	      Node* temp = ios->getParent();
	      iosc->setParent(temp);
	  
	      if(ios == ios->getParent()->getLeft())
		{
	      
		  ios->getParent()->setLeft(iosc);
		}
	      else
		{
		  ios->getParent()->setRight(iosc);
		}
	      if (ios->getColor(ios) == 0)
		{
		  if (iosc->getColor(iosc) == 1)
		    {	  
		      iosc->setColor(0);
		    }
		  else
		    {
		      delete_case1(iosc);
		    }
		}
	      if (iosc->getValue() == -1)
		{
		  if (iosc->getParent()->getLeft() == iosc)
		    {
		      iosc->getParent()->setLeft(NULL);
		    }
		  else
		    {
		      iosc->getParent()->setRight(NULL);
		    }
		  delete iosc;
		}
	  
	  delete ios;
	}
     
      return numbersofnumbers - 1;
    }
  else
    {
      cout << "Such node doens't exist" << endl;
      return numbersofnumbers;
    }
}

void delete_case1(Node* n)
{
  cout << "case1" << endl;
  if ( n->getParent() != NULL)
    {
      
      delete_case2(n);
    }
}
void delete_case2(Node* n)
{
  
  cout << "case2" << endl;
  Node* s = sibling (n);

  if (s->getColor(s) == 1)
    {
      n->getParent()->setColor(1);
      s->setColor(0);
      if(n == n->getParent()->getLeft())
	{
      rotate_left(n->getParent());
	}
      else
	{
	  rotate_right(n->getParent());
	}
    }
  Node* temp = n->getParent();
  while(temp->getParent() != NULL)
    {
       temp = temp->getParent();
    }
  detailed_info(temp);
  
 
  delete_case3(n);
}
void delete_case3(Node* n)
{
  
  cout << "case3" << endl;
  Node* s = sibling(n);
  if (s == NULL)
    {
      s = new Node;
      s->setValue(-1);
      s->setColor(0);
      s->setLeft(NULL);
      s->setRight(NULL);
    }
  if ((n->getParent()->getColor(n->getParent()) == 0) && (s->getColor(s) == 0) && (s->getLeft()->getColor(s->getLeft()) == 0) && (s->getRight()->getColor(s->getRight()) == 0 ))
    {
      s->setColor(1);
      delete_case1(n->getParent());
      
      Node* temp = n->getParent();
      while(temp->getParent() != NULL)
	{
	  temp = temp->getParent();
	}
      detailed_info(temp);
    }
  else
    {
      
      Node* temp = n->getParent();
      while(temp->getParent() != NULL)
	{
	  temp = temp->getParent();
	}
      detailed_info(temp);
      delete_case4(n);
    }
  
  if (s->getValue() == -1)
    {
      if(s->getParent()->getLeft() == s)
	{
	  s->getParent()->setLeft(NULL); 
	}
      else
	{
	  s->getParent()->setRight(NULL);
	}
      delete s;
    }
}
void delete_case4(Node* n)
{
  
  cout << "case4" << endl;
  Node* s = sibling(n);
 
  if (s == NULL)
    {
      
      s->setValue(-2);
      s->setColor(0);
      s->setLeft(NULL);
      s->setRight(NULL);
    }
  if ((n->getParent()->getColor(n->getParent()) == 1) && (s->getColor(s) == 0) && (s->getLeft()->getColor(s->getLeft()) == 0) && (s->getRight()->getColor(s->getRight()) == 0 ))
    {
      
      s->setColor(1);
      n->getParent()->setColor(0);
     
      Node* temp = n->getParent();
      while(temp->getParent() != NULL)
	{
	  temp = temp->getParent();
	}
      detailed_info(temp);
    }
  else
    {
      Node* temp = n->getParent();
      while(temp->getParent() != NULL)
	{
	  temp = temp->getParent();
	}
      detailed_info(temp);
 
      delete_case5(n);
    }
  
  if (s->getValue() == -2)
    {
      
      if(s->getParent()->getLeft() == s)
	{
	  s->getParent()->setLeft(NULL); 
	}
      else
	{
	  s->getParent()->setRight(NULL);
	}
      delete s;
    }
  
}
void delete_case5(Node* n)
{
  
  cout << "case5" << endl;
  Node* s = sibling(n);
  
  
  if (s == NULL)
    {
      s = new Node;
      s->setValue(-3);
      s->setColor(0);
      s->setLeft(NULL);
      s->setRight(NULL);
    }
  if (s->getColor(s) == 0)
    {
      if ((n == n->getParent()->getLeft()) &&(s->getRight()->getColor(s->getRight()) == 0) && (s->getLeft()->getColor(s->getLeft()) == 1))
	{
	  s->setColor(1);
	  if (s->getLeft() != NULL)
	    {
	  s->getLeft()->setColor(0);
	    }
	  rotate_right(s);
	}
      else if ((n == n->getParent()->getRight()) &&(s->getRight()->getColor(s->getRight()) == 0) && (s->getLeft()->getColor(s->getLeft()) == 1))
	  {
	    s->setColor(1);
	    if (s->getRight() != NULL)
	      {
	    s->getRight()->setColor(0);
	      }
	    rotate_left(s);
	  }
	
    }
  if (s->getValue() == -3)
    {
      if(s->getParent()->getLeft() == s)
	{
	  s->getParent()->setLeft(NULL); 
	}
      else
	{
	  s->getParent()->setRight(NULL);
	}
      delete s;
    }
  Node* temp = n->getParent();
  while(temp->getParent() != NULL)
    {
       temp = temp->getParent();
    }
  detailed_info(temp);
  
  delete_case6(n);
}
void delete_case6(Node* n)
{
  
  cout << "case6" << endl;
  
  Node* s = sibling(n);
  
  if (n == n->getParent()->getLeft())
    {
      if(s->getRight() != NULL)
	{
	  s->getRight()->setColor(0);
	}
      rotate_left(n->getParent());
      
    }
  else
    {
      if (s->getLeft() != NULL)
	{
	 s->getLeft()->setColor(0);
	}
      rotate_right(n->getParent());
 
    }
  Node* temp = n->getParent();
  while(temp->getParent() != NULL)
    {
       temp = temp->getParent();
    }
  detailed_info(temp);
  
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
  else if (n->getParent()->getColor(n->getParent()) == 0) // if n's parent is black, and n is red
    {
      insert_case2(n); // everything is fine
    }
  else if (uncle(n) != NULL && uncle(n)->getColor(uncle(n)) == 1) // if n's parent and uncle are red, (it wouldn't get to this level if n's parent
    // is black, from case 2, so 
    {
      insert_case3(n); // call case 3
    }
  else
    {
      insert_case4(n); // case 4, uncle is black, parent is red. only case left since it already passed all the other ifs	  
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
void insert_case3(Node* n) // we change parent and uncle to black, grandparent to red, and since the grandparent maybe
// a subtree of something else, so we recursively call to repair on the grandparent and everything above.
{
  n->getParent()->setColor(0);
  uncle(n)->setColor(0);
  grandparent(n)->setColor(1);
  insert_repair_tree(grandparent(n));
}
void insert_case4(Node* n) //uncle is black, parent is red, now we need to look at the nodes position in relation to parent
// to determine whether we are doing a left rotation or right rotation
{
  Node* p = n->getParent(); // define parents and grandparents
  Node* g = grandparent(n);
  if (n==p->getRight() && p==g->getLeft()) //if node is parent's right and parent is grandparent's left
    {
      // I can visualize rotation, but it's really hard to explain here
      rotate_left(p); // rotate left
      n = n->getLeft();
    }
  else if ( n==p->getLeft() && p == g->getRight()) //if node is parent's left and parent is grandparent's right
    { 
      rotate_right(p); //rotate right
      n = n->getRight();
    }
  insert_case4step2(n); // case 5
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
Node* search(Node* n, int number)
{  
  if (n == NULL )
    {
      return NULL;
    }
  else if (n->getValue() > number)
    { 
      search((n->getLeft()), number );
    }
  else if (n->getValue() < number )
    {
      search((n->getRight()), number);
    }
  else 
    {
      return n;
    }
}
//Because of my poor print function, I copied this from https://stackoverflow.com/questions/4965335/how-to-print-binary-tree-diagram?noredirect=1&lq=1
//Original idea from VasiliNovikov, saw this from Zareef
void printTree(char prefix[], Node* head, bool isLeft){
  char* Prefix = NULL;
  if (head!=NULL)
    {	    
      if(head->getColor(head) == 0)
	{
		
	  cout << prefix;
	  if(isLeft == true)
	    {
	      cout << (char)124 << "--- " ;
	    }
	  else
	    {
	      cout << (char)124 << "___ ";
	    }
	  cout << head->getValue() << endl;
	}
      else
	{
		
	  cout << prefix;
	  if(isLeft == true)
	    {
	      cout <<"\033[1;31m" << (char)124 << "--- "<< " \033[0m";

	    }
	  else
	    {
	      cout << "\033[1;31m" <<(char)124 << "___ " << " \033[0m";
	      
	    }
	  cout << head->getValue() << endl;
		
	}
      if (Prefix != NULL){
	delete []Prefix;
      }
      Prefix = new char[100];
      Prefix = strcpy(Prefix,prefix);
      if (isLeft == true)
	{
	  printTree(strcat(prefix,  "|   " ), head->getLeft(), true);
	  printTree(strcat(Prefix,  "|   "), head->getRight(), false);
	}
      else
	{
	  printTree(strcat(prefix, "    "), head->getLeft(), true);
	  printTree(strcat(Prefix, "    "), head->getRight(), false);
	}
    }
}

void detailed_info(Node* head)
{
  
  
  if(head != NULL)
    {
      cout << endl;
      if (head->getColor(head) == 1)
	{
 cout << "\033[1;31m" << "Value: " << head->getValue()  << " \033[0m" << endl;
	}
      else
	{
	  cout << "Value: " << head->getValue() << endl;
	}
      if(head->getLeft() != NULL)
    {
      cout << "Left: " << head->getLeft()->getValue() << endl;
    }
  else
    {
      cout << "Left: NULL" << endl;
    }
    if(head->getRight() != NULL)
    {
      cout << "Right: " << head->getRight()->getValue()<<endl;
    }
  else
    {
      cout << "Right: NULL" << endl;
    }
  
  detailed_info(head->getLeft());
  detailed_info(head->getRight());
    }
  
}
