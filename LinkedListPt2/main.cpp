#include <iostream>
#include "Node.h"
#include "Student.h"
#include <cstring>
#include <iomanip>
#include <math.h>


using namespace std;
void Average(Node* next, float total, int number);
void Deletebyid(Node* &head, int id);
void add(Student*, Node* &head);
void print(Node* next, int longeswtfirstname, int longestlastname, int longestid, Node* head);
char* firstname;
int checkvalidid(int id, Node* head);
char* yesno;
char* lastname;
char* command;
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
  cout << "Type in \"PRINT\" to print out the list of students." << endl;
  cout << "Type in \"DELETE\" to delete a student." << endl;
  cout << "Type in \"AVERAGE\" to find out the average gpa of all the stuents." << endl;

  cout << "Type in \"QUIT\" to exit the program." << endl;
  cout << endl;
  cout << endl;
  Node* head = NULL;
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
	  id = checkvalidid(id, head);
	  
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
	  add(temp, head);
	}
      else if (strcmp(command,(char*)"PRINT") == 0)
	{
	  // if the user says print, then print with all the #s that wil be used to make the table look nice 
	  print(head, longestfirstname,longestlastname,longestid, head);
	  cout<< endl;
	}
      else if (strcmp(command,(char*)"DELETE") == 0)
	{
	  cout << endl;
      	  yesno = new char[99];
 
	  id = 0;
	  
	  cout << "Do you know the ID of the student?" << endl;
	  yesno = new char[99];
	  cin.get(yesno, 99, '\n');
	  cin.get();
	  cout << endl;
      
	  if (strcmp(yesno, (char*)("Y")) == 0)
	    {
	      cout << "What's the ID of the student that you want to delete?" << endl;
	      cin >> id;
	      cin.get();
	      cout << endl;
	      // delete based on ID starts here

	      Deletebyid(head,id);
	    }
	  else
	    {
	      cout << "You don't have enough information!" << endl;
	      cout << endl;
	  
	    }
      
	}
       
     
      else if (strcmp(command, (char*)"AVERAGE") == 0)
	{
	  Average (head, 0, 0);
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

void add(Student* newStudent, Node* &head)
{
  // when adding a new student, create a pointer, if this is
  // the first student, make it the head
  Node* current = head;
  if (head == NULL)
    {
      head = new Node(newStudent);
     
    }
  else // if it's not a head, go to the laststudent on the list, and make its nextstudent the new student
    {
      while(current -> getNext() != NULL)
	{
	  current  = current->getNext();
	}
      current->setNext(new Node(newStudent));
     
    }
  cout << endl;
}
int checkvalidid(int id, Node* head)
{ // self explainatory, return the final id when there isn't any repetitive
  Node* current = head;
  if (head == NULL)
    {
      return id; // if the head is null which means this is the first node
    }
  if (current->getValue()->getid() == id)
    {
      cout << endl; // if the current node's number is the same as the number, retype the number and recheck from the beginning
      cout << "Someone with the same id already exists in the student list!" << endl;
      cout << "Please retype!"<<endl;
      cout << endl;
	  
      cin >> id;
      cin.get();
      checkvalidid(id,head);
	 
    }
  else
    {
      if (current->getNext() != NULL)
	{ // if the current's number is not the same, check current's next
	  if (current->getNext()->getValue()->getid() == id)
	    {
	      cout << "Someone with the same id already exists in the student list!" << endl;
	      cout << "Please retype!"<<endl;
	      // if current's next is the same, retype and start from the beginning
	      cout << endl;
	      cin >> id;
	      cin.get();
	      checkvalidid(id,head);
	      
	    }
	  else
	    { // if both aren't go to next node keep doing until the end of the list
	  current = current->getNext();
	  checkvalidid(id, current);
	    }
	}
      else
	{ // if it's at the end of list, return the id ffinally.
	  return id;
	}
    }
	
  
  


}
void print(Node* next, int longestfirstname, int longestlastname, int longestid, Node* head)
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
      if (strlen(next->getValue()->getfirstname()) <= longestfirstname)
	{
	  cout << next->getValue()->getfirstname() << setw((longestfirstname - strlen(next->getValue()->getfirstname() +1))) << " ";
	}
      else // if this is the longestfirstname, just space
	{
	  cout << next->getValue()->getfirstname()  << " ";
	}
      //same thing for name and id
      if (strlen(next->getValue()->getlastname()) <= longestlastname)
	{
	  cout << next->getValue()->getlastname() << setw((longestlastname - strlen(next->getValue()->getlastname() +1)))<< " " ;
	}
      else
	{
	  cout << next->getValue()->getlastname()  << " ";
	}
      int xd =  log10(next->getValue()->getid()) + 1;
      
      if ( xd <= longestid)
	{
	  cout << next->getValue()->getid() << setw((longestid - (xd) + 1)) << " " ;
	}
      else
	{
	  cout << next->getValue()->getid() << " ";
	}
      cout <<setprecision(3) << next->getValue()->getgpa() << endl;
      print(next->getNext(), longestfirstname, longestlastname, longestid, head);
    }

}
void Deletebyid(Node* &head, int id)
{
  yesno = new char[99];
  Node* current;
  current = head;
	    
  if (current != NULL)
    {

      if (current ->getValue()->getid() == id) // when the first node in the list matches the id
	{
	  cout << "Is this the one?" << endl;
	  cout << current->getValue()->getfirstname()<<" "<< current->getValue()->getlastname() << " " << current->getValue()->getid() << " " << current->getValue()->getgpa() << endl;
	  cout  << endl;
	  yesno = new char[99];
	  cin.get(yesno, 99, '\n');
	  cin.get();
	  cout << endl;
		       
	  if (strcmp(yesno, (char*)("Y")) == 0)
	    {
		        
	      if (current->getNext() != NULL)
		{
		  
		  head = current->getNext();

		  
		  current->~Node();
		  
		  current = head;

		 
	      	     
		}
	      else // if this is the first and the only node and it matches, delete it and set the head to null
		{
		  current->~Node();
		  head = NULL;
			       
		}
			   
	    }
		
	}
	    
	
	
      while (current->getNext() != NULL) //keep going through the list until the last one in the list
	{
		  
	  if (current ->getNext() ->getValue()->getid() == id) // if the next node matches
	    {
	      cout << "Is this the one?" << endl;
		      
	      cout << current->getNext()->getValue()->getfirstname()<<" "<< current->getNext()->getValue()->getlastname() << " " << current->getNext()->getValue()->getid() << " " << current->getNext()->getValue()->getgpa() << endl;
	      cout << endl;
	      yesno = new char[99];
	      cin.get(yesno, 99, '\n');
	      cin.get();
	      cout << endl;

	      if (strcmp(yesno, (char*)("Y")) == 0)

		{
		  if (current->getNext()->getNext() != NULL)
		    {
		      Node* thenextnext = current->getNext()->getNext(); // set the current's next to the next next
		      current->getNext()->~Node();
		      current->setNext(thenextnext);	      
		     
		     
		    }
		  else // if the next node matches and is the last node, just delete it
		    {
		      current->getNext()->~Node();
		      current->setNext(NULL); // delete it and set the current node as the last node
		      break; // Since this is the last node, get out of the while loop
		    }
		}
		 
		    
	      current = current->getNext(); // keep going until it's the node before the last node.
			   
	    }
	}
	    
    }
  else if (current == NULL)
    {
      cout << "You don't have any Students in the list!" << endl;
      cout << endl;
    }
		 
	    
  // ends here
}




void Average(Node* next, float total, int number)
{
  
  if (next != NULL) // keep adding the gpa up until there isn't anymore students, and keep track of the number of students. totalamount / numbers  = average
    {
      total += next->getValue()->getgpa();
      number += 1;
      Average(next->getNext(), total, number);
    }
  else
    {
      cout << endl;
      cout << "The average GPA of all the students is : " << setprecision(3) << ( total / number) << endl;
      cout << endl;
    }
}
