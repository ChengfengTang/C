#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;
char* input;

int main()
{
  cout << "Welcome to Chengfeng Tang's Shunting Yard Project" << endl << "Please input a valid mathmatical equation with infix expressions!" << endl << "I will be able to turn them into either prefix or postfix expressionss" << endl;

  cout << "What's the infix expression of the mathmatical equation." << endl;
  input = new char [99];
  cin.get(input,99, '\n');
  cin.get();

  cout << input << endl;

  //turn them into postfix first
  for (int i = 0; i < strlen(input); i++ )
    {
      
    }
  //turn them into a tree

  //if output infix

  //if ouotput prefix

  //if output postfix
  return 0;
}
