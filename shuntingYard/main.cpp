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
  Node* head;
  while (q.size() != 1)
    {
     
      if ( isdigit(q.front()) == 0 )
	{
	  Node* newNode;
	  newNode->setSymbol(q.front());
	  q.pop();
	  newNode->setLeft(chars.top());
	  chars.pop();
	  newNode->setRight(chars.top());
	  chars.pop();
	  chars.push(newNode);
	  
	}
      else
	{
	  
	  Node* newNode;
	  newNode->setSymbol(q.front());
	  q.pop();
	  chars.push(newNode);
	  
	}
      
    
    }
  head->setSymbol(q.front());
  q.pop();

  head->setLeft(chars.top());
  chars.pop();
 
  head->setRight(chars.top());
 
  chars.pop();
	  
  return head;
  cout << " done"<< endl;
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

  
  /*
  cout << head->getSymbol() << endl;
  //while (current->getLeft() != NULL)
  //{
      cout << head->getLeft()->getSymbol() << endl;
      current = current->getLeft();
      //}
  current = head;
   while (current->getRight() != NULL)
    {
      cout << head->getLeft()->getSymbol() << endl;
      current = current->getLeft();
    }
  */
  //if output infix

  
  
  //if ouotput prefix

  //if output postfix
  return 0;
}

