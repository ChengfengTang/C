#include <iostream>
#include <cstring>
#include "Node.h"
#include <stack>
#include <queue>
using namespace std;
void popstack(stack <char>& s, queue<char>& q)
{
  if (!s.empty())
    {
      if (s.top() == ')')
	{
	  s.pop();
	  while(s.top() != '(' )
	    {
	      q.push(s.top());
	      s.pop();
	      
	    }
	  s.pop();
	}
      else if (s.top () == '^')
	{
	      
	    
        }
    
      else if ((s.top () == '*') || (s.top () == '/'))
	{
	  char a = s.top();
	  s.pop();
	  if (!s.empty())
	    {
	      while ((s.top() != '+') && (s.top() != '-') && (s.top()!='('))
		{
		  q.push(s.top());
		  s.pop();
		  if (s.empty())
		    {
		      break;
		    }
		}
		  s.push(a);
		
	    }
	  else
	    {
	      s.push(a);
	    }
	 }
      else if ((s.top () == '+') || (s.top () == '-'))
	{
	  char a = s.top();
	  s.pop();
	  if (!s.empty())
	    {
	      while ((s.top() != '+') && (s.top() != '-') && (s.top()!='('))
		{
		  
		  q.push(s.top());
		  s.pop();
		  if (s.empty())
		    {
		      break;
		    }
		  
		  
      		}
		  s.push(a);
		
	    }
	  else
	    {
	      s.push(a);
	    }

    	 }
    }
  
}
void poptherest(stack <char>& s, queue<char>& q)
{
  while(!s.empty())
    {
      q.push (s.top());
      s.pop();
    }
  
} 
void printstack(stack <char> s)
{
  while(!s.empty())
    {
      cout << s.top() ;
      s.pop();

    }
  cout << endl;
}
void printqueue(queue <char> q)
{
  while(!q.empty())
    {
      cout << q.front();
      q.pop();
    }
  cout << endl;
}
Node* turntree(queue<char>q)
{
  stack<Node*> chars;
  Node* head = new Node();
  while (q.size() != 1)
    {
     
      if ( isdigit(q.front()) == 0 )
	{
	  
	  Node* newNode = new Node();
	  //cout << q.front()<< endl;
	  
	  newNode->setSymbol(q.front());
	  q.pop();
	  newNode->setRight(chars.top());
	  // cout << chars.top()->getSymbol()<< endl;
	  chars.pop();
	  //cout << chars.top()->getSymbol()<< endl;
	  newNode->setLeft(chars.top());
	  chars.pop();
	  
	  chars.push(newNode);
	  
	}
      else
	{
	  
	  Node*  newNode1 = new Node();
	  //cout << q.front()<< endl;
	  
	  newNode1->setSymbol(q.front());
	  q.pop();
	  chars.push(newNode1);
	  
	}
      
    
    }
  //cout << q.front()<< endl; 
  head->setSymbol(q.front());
  q.pop();
 
  

  //cout << chars.top()->getSymbol()<< endl;
	  
  head->setRight(chars.top());
  chars.pop();
 
  //cout << chars.top()->getSymbol()<< endl;
	  
 head->setLeft(chars.top());
 
 chars.pop();
	  
  return head;
  
}
void treeinfix(Node* head)
{
  if (head == NULL)
    {
     
    }
  else
    {
            if (head->getSymbol() == '^')
	{
	  if ((head->getLeft()->getSymbol() != '^') && (isdigit(head->getLeft()->getSymbol()) == 0 ) && (head->getLeft() != NULL)&& (head->getRight() != NULL)) 
	    {
	      cout << "(" ;
	    }

	}
      else if ((head->getSymbol() == '*') || (head->getSymbol() == '/'))
	{
	  if (
	      (head->getLeft()->getSymbol() == '+') ||
	      (head->getLeft()->getSymbol() == '-') ||
	      (head->getLeft()->getSymbol() == '*') ||
	      (head->getLeft()->getSymbol() == '/') 
	      )
	     
	    {
	      cout << "(" ;
	    }
	  
	}

      if (head->getSymbol() == '^')
	{
	  if ((head->getRight()->getSymbol() != '^') && (isdigit(head->getRight()->getSymbol()) == 0 ) && (head->getRight() != NULL ) && (head->getLeft() != NULL))
	    {
	      cout << "(" ;
	    }
	}
      else if ((head->getSymbol() == '*') || (head->getSymbol() == '/'))
	{
	  if (
	      (head->getRight()->getSymbol() == '+') ||
	      (head->getRight()->getSymbol() == '-') ||
	      (head->getRight()->getSymbol() == '*') ||
	      (head->getRight()->getSymbol() == '/'))
	      {
	      cout << "(" ;
	       }
	  
	}
 
      treeinfix (head->getLeft());

             if (head->getSymbol() == '^')
	{
	  if ((head->getLeft()->getSymbol() != '^') && (isdigit(head->getLeft()->getSymbol()) == 0 ) && (head->getLeft() != NULL) && (head->getRight() != NULL)) 
	    {
	      cout << ")" ;
	    }

	}
      else if ((head->getSymbol() == '*') || (head->getSymbol() == '/'))
	{
	  if (
	      (head->getLeft()->getSymbol() == '+') ||
	      (head->getLeft()->getSymbol() == '-') ||
	      (head->getLeft()->getSymbol() == '*') ||
	      (head->getLeft()->getSymbol() == '/') 
	      )
	     
	    {
	      cout << ")" ;
	    }
	  
	}

      if (head->getSymbol() == '^')
	{
	  if ((head->getRight()->getSymbol() != '^') && (isdigit(head->getRight()->getSymbol()) == 0 ) && (head->getRight() != NULL ) && (head->getLeft() != NULL)) 
	    {
	      cout << ")" ;
	    }
	}
      else if ((head->getSymbol() == '*') || (head->getSymbol() == '/'))
	{
	  if (
	      (head->getRight()->getSymbol() == '+') ||
	      (head->getRight()->getSymbol() == '-') ||
	      (head->getRight()->getSymbol() == '*') ||
	      (head->getRight()->getSymbol() == '/'))
	      {
	      cout << ")" ;
	       }
	  
	}

      cout << head->getSymbol();
    if (head->getSymbol() == '^')
	{
	  if ((head->getLeft()->getSymbol() != '^') && (isdigit(head->getLeft()->getSymbol()) == 0 ) && (head->getLeft() != NULL) && (head->getRight() != NULL)) 
	    {
	      cout << "(" ;
	    }

	}
      else if ((head->getSymbol() == '*') || (head->getSymbol() == '/'))
	{
	  if (
	      (head->getLeft()->getSymbol() == '+') ||
	      (head->getLeft()->getSymbol() == '-') ||
	      (head->getLeft()->getSymbol() == '*') ||
	      (head->getLeft()->getSymbol() == '/') 
	      )
	     
	    {
	      cout << "(" ;
	    }
	  
	}

      if (head->getSymbol() == '^')
	{
	  if ((head->getRight()->getSymbol() != '^') && (isdigit(head->getRight()->getSymbol()) == 0 ) && (head->getRight() != NULL ) && (head->getLeft() != NULL)) 
	    {
	      cout << "(" ;
	    }
	}
      else if ((head->getSymbol() == '*') || (head->getSymbol() == '/'))
	{
	  if (
	      (head->getRight()->getSymbol() == '+') ||
	      (head->getRight()->getSymbol() == '-') ||
	      (head->getRight()->getSymbol() == '*') ||
	      (head->getRight()->getSymbol() == '/'))
	      {
	      cout << "(" ;
	       }
	  
	}

	  treeinfix(head->getRight());
            
         
             if (head->getSymbol() == '^')
	{
	  if ((head->getLeft()->getSymbol() != '^') && (isdigit(head->getLeft()->getSymbol()) == 0 ) && (head->getLeft() != NULL) && (head->getRight() != NULL)) 
	    {
	      cout << ")" ;
	    }

	}
      else if ((head->getSymbol() == '*') || (head->getSymbol() == '/'))
	{
	  if (
	      (head->getLeft()->getSymbol() == '+') ||
	      (head->getLeft()->getSymbol() == '-') ||
	      (head->getLeft()->getSymbol() == '*') ||
	      (head->getLeft()->getSymbol() == '/') 
	      )
	     
	    {
	      cout << ")" ;
	    }
	  
	}

      if (head->getSymbol() == '^')
	{
	  if ((head->getRight()->getSymbol() != '^') && (isdigit(head->getRight()->getSymbol()) == 0 ) && (head->getRight() != NULL ) && (head->getLeft() != NULL)) 
	    {
	      cout << ")" ;
	    }
	}
      else if ((head->getSymbol() == '*') || (head->getSymbol() == '/'))
	{
	  if (
	      (head->getRight()->getSymbol() == '+') ||
	      (head->getRight()->getSymbol() == '-') ||
	      (head->getRight()->getSymbol() == '*') ||
	      (head->getRight()->getSymbol() == '/'))
	      {
	      cout << ")" ;
	       }
	  
	}            
    }
  
}
void treeprefix(Node* head)
{
  if (head == NULL)

     {
    }
  else
    {
      cout << head->getSymbol();
      treeprefix(head->getLeft());
      treeprefix(head->getRight());
    }
}
void treepostfix(Node* head)
{
   if (head == NULL)
    {
    }
  else
    {
      if (!(head->getLeft() == NULL && head->getRight() == NULL))
	{
	  cout << "(";
	}
      treepostfix(head->getLeft());
      
      treepostfix(head->getRight());
      cout << head->getSymbol();
      if ((head->getLeft() != NULL) && (head->getRight() != NULL))
	{
	  cout << ")";
	}
    }
}
int main()
{
  cout << "Welcome to Chengfeng Tang's Shunting Yard Project" << endl << "Please input a valid mathmatical equation with infix expressions!" << endl << "I will be able to turn them into either prefix or postfix expressionss" << endl;

  cout << "What's the infix expression of the mathmatical equation." << endl;
  char input[99];
  cin.get(input,99, '\n');
  cin.get();

  //cout << input << endl;

  //turn them into postfix first
  int a = strlen(input);
  stack<char> s;
  queue <char> q;
  for (int i = 0; i < a; i++ )
    {
      if (input[i] == ' ')
	{
       
	}
      if ((input[i] == '+') || (input[i] == '-') || (input[i] == '^')
         || (input[i] == '*') || (input[i] == '/') ||  (input[i] == '(')
	  || (input[i] == ')'))
	{
	  s.push(input[i]);
	}
      if (isdigit(input[i]) != 0)
	{
	  q.push(input[i]);
	}
      //printqueue(q);
      // printstack(s);
      popstack(s,q);
      
    }
  poptherest(s,q);
  printqueue(q);

  
  //turn them into a tree
  
  Node* head = turntree(q);
  
  cout <<"If you would like to create an infix notation, enter number \"1\" . " << endl;
  
  cout <<"If you would like to create a prefix notation, enter number \"2\" . " << endl;
  
  cout <<"If you would like to create a postfix notation, enter number \"3\" . " << endl;

  int answer = 0;

  cin >> answer;
  cin.get();

  if (answer == 1)
    {
      treeinfix(head);
    }
  
  //if output infix
  
  
  else if (answer == 2)
    {
      treeprefix(head);
    }
  //if ouotput prefix
  else if (answer == 3)
    {
      treepostfix(head);

    }

  
  //if output postfix
  return 0;
}

