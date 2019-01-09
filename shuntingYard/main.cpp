#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;
char* input;

int main()
{
  cout << "Welcome to Chengfeng Tang's Shunting Yard Project" << endl << "Please input a valid mathmatical equation iwth infix notations!" << endl << "I will be able to turn them into either infix, prefix or postfix notations" << endl;
  
  input = new char [99];
  cin.get(input,99, '\0');
  cin.get();

  cout << input << endl;

  return 0;
}
