#include <iostream>
#include <cstring>
#include <iomanip>
#include <math.h>

using namespace std;

char* firstName;
char* lastName;
char* fileLastName;
char* fileFirstName;

struct student
{
  char* firstName;
  char* lastName;
  int id;
  float gpa;
};

void addStudent();
void generateStudent();
void searchStudent();
void print();
void deleteStudent();


int main()
{
  int a = 0;
  cout << "Welcome to ChengfengTang's Hash Table. " << endl;
  while(a != 5 )
    {
      
      cout << "----------------------------------------" << endl;
      cout << "To add a student, enter \"1\"." << endl;
      cout << "To randomly generate a student, enter \"2\"." << endl;
      cout << "To delete a student, enter \"3\"." << endl;
      cout << "To print out all the students, enter \"4\"." << endl;
      cout << "To quit, enter \"5\"." << endl;
      cout << "----------------------------------------" << endl;
      cin >> a;
      cin.get();
      cout << "----------------------------------------" << endl;
	
      if ( a == 1)
	{
	  firstName = new char[99];
	  lastName = new char[99];
	  int id = 0;
	  float gpa;
	  cout << "What's the first name of the student? "<< endl;
	  cout << "----------------------------------------" << endl;
	  cin.get(firstName,99,'\n');
	  cin.get();
	  cout << "----------------------------------------" << endl;
	  cout << "What's the last name of the student? " << endl;
          cout << "----------------------------------------" << endl;
	  cin.get(lastName,99,'\n');
	  cin.get();	  
	  cout << "----------------------------------------" << endl;
	  cout << "What's the id of the student? " << endl;
	  cout << "----------------------------------------" << endl;
	  cin >> id;
	  cin.get();
	  cout << "----------------------------------------" << endl;
	  cout << "What's the gpa of the student?" << endl;
	  cin >> gpa;
	  cin.get();
	  cout << "----------------------------------------" << endl;
	  cout << "The new student is called: " << firstName << " " << lastName << endl;
	  cout << "With student id: " << id << " and gpa: " << gpa << endl;
	  cout << "----------------------------------------" << endl;
	  
	}
      else if (a == 2)
	{
	  cout << "How many of them do you want?" << endl;
	  cout << "----------------------------------------" << endl;
	  int  n = 0;
	  cin>> n;
	  cin.get();
	  cout << "----------------------------------------" << endl;
	  cout << "Enter the file name for all of the first names." << endl;
	  cout << "----------------------------------------" << endl;
	  fileFistName = new char*[99];
	  cin.get(fileFistName, 99 , '\n');
	  cin.get();
	  inFile.open(fileFistName);
	  cout << "----------------------------------------" << endl;
	
	  if (!inFile)
	    {
	      cout << "----------------------------------------" << endl;
	      cout << "The file could not be opened." << endl;
	      cout << "----------------------------------------" << endl;
	
	    }
	  else
	    {
	      inFile.getLine(allFileFistName, 9999);
	      
	    }
	  cout << "----------------------------------------" << endl;
	  fileLastName = new char* [99];
	  cout << "" << endl;
	  cout << "----------------------------------------" << endl;
	
	 
	  for(int i = 0; i <= n; i++)
	    {
	      firstName = new char[99];
	      lastName = new char[99];
	      int id = 0;
	      float gpa;
	      cout << "A randomly generated student is called: " << firstName << " " << lastName << endl;
	      cout << "With student id: " << id << " and gpa: " << gpa << endl;
	      cout << "----------------------------------------" << endl;
	    }
      }
      else if (a == 3 )
	{

	  cout << "----------------------------------------" << endl;
	}
      else if (a ==4 )
	{

	  cout << "----------------------------------------" << endl;
	}
      else if (a ==5 )
	{
	  cout << "Bye" << endl;
	  return 0;
	  cout << "----------------------------------------" << endl;
	}
      else
	{
	  cout << "Invalid Number! Please reenter." << endl;
	   cout << "----------------------------------------" << endl;
	   
	}
      
      
      
    }
  
}
