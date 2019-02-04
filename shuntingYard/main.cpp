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
    
      while ((s.top () == '*') || (s.top () == '/') || (s.top() == '+') || (s.top() == '-') )
	{
	  char a = s.top();
	  s.pop();
	  if (!s.empty())
	    {
	      if ((s.top() == '*') || (s.top() == '/'))
		{
		  q.push(s.top());
		  s.pop();
		  s.push(a);
		}
	      else
		{
		  s.push(a);
		}
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
      popstack(s,q);
    }
  printstack(s);
  printqueue(q);
  poptherest(s,q);
  printqueue(q);

  
  //turn them into a tree

  //if output infix

  //if ouotput prefix

  //if output postfix
  return 0;
}

