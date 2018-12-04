#include <iostream>
#include "Node.h"
#include <cstring>
#include <iomanip>
#include<math.h>


using namespace std;

void add(Student*);
void print(Node* next, int longeswtfirstname, int longestlastname, int longestid);
char* firstname;
char* lastname;
char* command;
Node* head = NULL;
  int longestfirstname = 9;
  int longestlastname = 8;
  int longestid = 2;
/*
THESE numbers will be used later


 */
int main()
{

  cout << "Welcome to Chengfeng Tang's Linked List " <<  endl;
  cout << "Linked List holds a list of students." << endl;
  cout << "Type in \"ADD\" to add students." << endl;
  cout << "Type in \"PRINT\" to prinnt out the list of students." << endl;
  cout << "Type in \"QUIT\" to exit the program." << endl;
  cout << endl;
  cout << endl;
  
  int i = 0;
  while (i == 0	)
    {
  command = new char[99];
  firstname = new char [99];
  lastname = new char[99];
  int id = 0;
  float gpa;
  cout << "What do you want to do now? " << endl;
  cin.get(command,99,'\n');
  cin.get();
  /*
    first ask what the user wants to do, they can either add or print

   */
  if (strcmp(command, (char*)"ADD") == 0 )
    {
      cout << endl;
      
      cout << "What's the first name of the student that you want to add?"<< endl;
      cin.get(firstname,99,'\n');
      cin.get();

      if (strlen(firstname) > longestfirstname)
	{
	  longestfirstname = strlen(firstname);
	  
	}
      
      cout << endl;
      cout << "What's the last name of the student that you want to add?"<< endl;
      cin.get(lastname,99,'\n');
      cin.get();

      if (strlen(lastname) > longestlastname)
	{
	  longestlastname = strlen(lastname);
	}
      
      cout << endl;
      cout << "What's the id of the student that you want to add?"<< endl;
      cin >> id;
      cin.get();

      int xd = log10(id) + 1;
      if ( xd  >= longestid)
	{
	  longestid = xd;
	}
      
      cout << endl;
      cout << "What's the gpa of the student that you want to add?"<< endl;
      cin >> gpa;
      cin.get();
      /*
	if they said add, record in all the information required to make a student
	and make a student and add students into the student list,
       */
  Student* temp = new Student ( firstname, lastname, id, gpa);
  add(temp);
  cout << endl;
   }
  else if (strcmp(command,(char*)"PRINT") == 0)
    {
      // if the user says print, then print with all the #s that wil be used to make the table look nice 
      print(head, longestfirstname,longestlastname,longestid);
      cout<< endl;
    }
  else if (strcmp(command,(char*)"QUIT") == 0)
    {
      return 0;
    }
  else
    {
      cout <<"Invalid Command!" << endl;
      cout << endl;
      cout << endl;
    }
 
    }
}

void add(Student* newStudent)
{
  // when adding a new student, create a pointer, if this is
  // the first student, make it the head
  Node* current = head;
  if (current == NULL)
    {
      head = new Node();
      head -> setStudent(newStudent);
	
    }
  else // if it's not a head, go to the laststudent on the list, and make its nextstudent the new student
    {      while(current -> getnext() != NULL)
	{
	  current = current->getnext();
	}
      current->setnext(new Node());
      current->getnext()->setStudent(newStudent);
    }
}

void print(Node* next, int longestfirstname, int longestlastname, int longestid)
{
  //when printing just go through the list from the head until the currentstudent's next is null which means that one is
  // the last one.
  if (next == head)
    {
      cout << endl;
      cout << "Student:" <<endl ;
      if (longestfirstname <= 9) // if the longeststudent's firstname is less than firstname, which has 9 characters
	// just print firstname with one space
	{
	  cout << "FirstName " ;
	}
      else // if there is a firstname that's longer than firstname, print firstname and space the amount so lastname can be printed at the same column as that student's lastname
	{
	  cout << "FirstName" << setw(longestfirstname - 8) << " ";
	}
      // same concept here and for id
      if (longestlastname <= 8)
	{
	  cout << "LastName " ;
	}
      else
	{
	  cout << "LastName" << setw(longestlastname - 7) << " ";
	}
      
      if (longestid <= 2)
	{
	  cout << "ID" << " ";
	}
      else
	{
	  cout << "ID" << setw(longestid - 1) << " ";
	}
      cout << "GPA" << endl;
    }

  if (next != NULL)
    {
      // on the other hand, if the student's firstname is  shorter than "firstname" or the longestfirstname,
      // set the amount of space so it will align with the longest firstname or "firstname", that's why we set the longestfirstname
      // equal to 9 which is the length of "firstname" at the beginning
      if (strlen(next->getStudent()->getfirstname()) <= longestfirstname)
	{
	  cout << next->getStudent()->getfirstname() << setw((longestfirstname - strlen(next->getStudent()->getfirstname() +1))) << " ";
	}
      else // if this is the longestfirstname, just space
	{
	  cout << next->getStudent()->getfirstname()  << " ";
	}
      //same thing for name and id
      if (strlen(next->getStudent()->getlastname()) <= longestlastname)
	{
	  cout << next->getStudent()->getlastname() << setw((longestlastname - strlen(next->getStudent()->getlastname() +1)))<< " " ;
	}
	else
	{
	  cout << next->getStudent()->getlastname()  << " ";
	}
      int xd =  log10(next->getStudent()->getid()) + 1;
      
      if ( xd <= longestid)
	{
	  cout << next->getStudent()->getid() << setw((longestid - (xd) + 1)) << " " ;
	}
	else
	{
	  cout << next->getStudent()->getid() << " ";
	}
      cout <<setprecision(3) << next->getStudent()->getgpa() << endl;
      print(next->getnext(), longestfirstname, longestlastname, longestid);
    }
}
