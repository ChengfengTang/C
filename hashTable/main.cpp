//most methods inspired by Aryan G & Conor & Jason
//However, I have thorough understanding on every part of the program.

#include <iostream>
#include <cstring>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
using namespace std;

char* firstName;
char* lastName;
char* fileLastName;
char* fileFirstName;

//new student
struct student
{
  char* firstName;
  char* lastName;
  int id;
  float gpa;
};

//for linked list in each index
struct node
{
  student* student = NULL;
  node* next = NULL;
};

//functions

int getHashValue(int id, int size); // return the index of a student
int  rehash(node* newHashTablle[], node* oldHashTable[], int size);
student* create( char* firstName, char* lastName, int id, float gpa);
void addStudent(node* hashTable[],int index, student* student);
void print(node* hashTable[], int size);
void deleteStudent(node* hashTable[], int id, int size);

//basically, the index of the student is his/her student id % size of the array. If there are over 3 students with the same index level,
//then double the size, students can have same name but not the same id.
int main()
{
  int size = 2;
  vector <char*> firstNames;
  vector <char*> lastNames;
  node** hashTable = new node* [100];
  vector<int> ids;
  for(int i = 0; i< 100; i++)
    {
      hashTable[i] = NULL; // setting everything to NULL
    }
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
	  bool availability = true;
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
	 
	  for(int i = 0 ; i < ids.size(); i++) // check if the new id has already existed in the student list
	    if (ids.at(i) == id)
	      {
		availability = false;
	      }
	    
	  if (availability == true) // if it is available, add the new student
	    {
	      ids.push_back(id);
	      student* news;
	      news = create(firstName, lastName, id, gpa);
	      int index = getHashValue(id, size);
      	      addStudent (hashTable, index, news );	
	      //check if the hash table needs to be rehashed every time a new student is added
	      for(int i = 0; i< size; i++)
		{
		  int xd = 0;
		  node* counter = hashTable[i];
		  if (counter == NULL)
		    {
		      //if there is no student in this row, keep going down
		    }
		  else
		    {
		      while(counter != NULL) // count the number of student in the current row
			{
			  counter = counter->next;
			  xd += 1;
			}
		      if(xd > 3  ) //if there is more than 3 students, rehash the table
			{
			  node** newHashTable = new node*[size * 2 ]; //create a new hashtable
			  size = rehash(newHashTable, hashTable, size); //return the doubled size while adding all the
			  //student in oldhashtable to new hashtable
			  // if there is more than 3 students with the same index, double the size            
			  delete[] hashTable; //don't wanna make too many hashtables, clean up the one and only hashtable, and make it equal to the new hashtable
			  hashTable = newHashTable;
			}
		    }
		  

		}
	     
	      cout << "The new student: " << news->firstName << " " << news->lastName << endl;
	      cout << "With student id: " << news->id << " and gpa: " << news->gpa << endl;
	      cout << "will be placed at index: " << index << endl;
	    }
	  else
	    {
	      cout << "A student with the same student id already exists." << endl;
	    }
	  cout << "----------------------------------------" << endl;
	  
	}
      else if (a == 2)
	{
	  // if the user wants to randomly generate students
	  // the method of putting all students into a vector and randomly choosing one is borrowed from Aryan G
	  char* split;
	  char fileInput[9999];
	  cout << "----------------------------------------" << endl;
	  cout << "Enter the file name for all of the first names." << endl;
	  cout << "----------------------------------------" << endl;
          fileFirstName = new char [99];
	  cin.get(fileFirstName, 99 , '\n');
	  cin.get();
	  ifstream myfile;
	  myfile.open(fileFirstName);
	  cout << "----------------------------------------" << endl;
	
	  if (!myfile)
	    {
	      cout << "----------------------------------------" << endl;
	      cout << "The file could not be opened." << endl;
	      cout << "----------------------------------------" << endl;
	      return 13;
	    }
	  else
	    {
	      myfile.getline(fileInput,9999);
	      split = strtok(fileInput," ");
	      while(split != NULL)
		{
		  firstNames.push_back(split);
		  split = strtok(NULL, " ");
		}
	    }
	  for(int i = 0; i< firstNames.size(); i++)
	    {
	      cout << firstNames.at(i) << " ";
	    }
	  cout << endl;
	  cout << "----------------------------------------" << endl;
	  char* split2;
	  char fileInput2[9999];
	  fileLastName = new char [99];
	  cout << "----------------------------------------" << endl;
	  cout << "Enter the file name for all of the last names." << endl;
	  cout << "----------------------------------------" << endl;
          fileLastName = new char [99];
	  cin.get(fileLastName, 99 , '\n');
	  cin.get();
	  ifstream myfile2;
	  myfile2.open(fileLastName);
	  cout << "----------------------------------------" << endl;
	
	  if (!myfile2)
	    {
	      cout << "----------------------------------------" << endl;
	      cout << "The file could not be opened." << endl;
	      cout << "----------------------------------------" << endl;
	      return 13;
	    }
	  else // if the file successfully open, split each name when there is a space.
	    {
	      myfile2.getline(fileInput2,9999);
	      split = strtok(fileInput2," ");
	      while(split != NULL)
		{
		  lastNames.push_back(split);
		  split = strtok(NULL, " ");
		}
	    }
	  for(int i = 0; i< lastNames.size(); i++)
	    {
	      cout << lastNames.at(i) << " ";
	    }
	  cout << endl;
	  
	  cout << "----------------------------------------" << endl;
	  cout << "How many students would you like to randomly generate" << endl;
	  
	  cout << "----------------------------------------" << endl;
	  
	  int n = 0;
	  cin >> n ;
	  cin.get();
	  
	  cout << "----------------------------------------" << endl;

	  int id = 0;
	  //if there are no ids in the list
	  if (ids.size() == 0)
	    {
	      id = (rand() % 600000) + 100000; // make sure all the ids are 6 digits numbers that are also consecutive numbers
	      // since it's randomly generated, keep them in order is the best way to save space...
	    
	    }
	  else // otherwise just use the largest id and add on to that, therefore no repetitive ids would be created
	    {
	      for(int i = 0; i<ids.size(); i++)
		{
		  if (ids.at(i) > id)
		    {
		      id = ids.at(i);
		    }
		}
	    }
	  for(int i = 0; i <= n; i++)
	    {

	      firstName = new char[99];
	      lastName = new char[99];
	      id += 1; 
	      float gpa;
	      int fn = rand() % firstNames.size() +1;
	      int ln = rand() % lastNames.size() +1;
	      firstName = firstNames.at(fn -1);
	      lastName = lastNames.at(ln -1);
	      gpa = ((float)((rand() % 500 ) + 100 )) / 100 ; // a random gpa between 1.00 and 5.00
	      ids.push_back(id);
	      student* news = create(firstName,lastName,id,gpa);
	      int index = getHashValue(id,size);
	      addStudent(hashTable,index,news);
	       for(int i = 0; i< size; i++)
		{
		  int xd = 0;
		  node* counter = hashTable[i];
		  if (counter == NULL)
		    {

		    }
		  else
		    {
		      while(counter != NULL)
			{
			  counter = counter->next;
			  xd += 1;
			}
		      if(xd > 3  )
			{
			  node** newHashTable = new node*[size * 2 ];
			  size = rehash(newHashTable, hashTable, size);
			  // if there is more than 3 students with the same index, double the size            
			  delete[] hashTable;
			  hashTable = newHashTable;
			  break;
			}
		    }
		  

		}
	
	      cout << "The random new student: " << news->firstName << " " << news->lastName << endl;
	      cout << "With student id: " << news->id << " and gpa: " << news->gpa << endl;
	      cout << "will be placed at index: " << index << endl;
	      cout << "----------------------------------------" << endl;
	    }
	}
      else if (a == 3 )
	{
	  cout << "What's the student id of the student you want to delete?" << endl;
	  
	  cout << "----------------------------------------" << endl;
	  int id;
	  cin>>id;
	  cin.get();
	  cout << "----------------------------------------" << endl;
	  ///make sure the id actually exists instead of deleting a random one with the same index
	  bool exist = false;
	  for(int i = 0; i < ids.size(); i++)
	    {
	      if (id == ids.at(i))
		{
		  exist = true;
		}
	    }
	  if (exist == false)
	    {
	      cout << "Such student does not exist!" << endl;
	    }
	  else
	    {
	      deleteStudent(hashTable,id,size);
	 
	    }
	  cout << "----------------------------------------" << endl;
	}
      else if (a ==4 )
	{
	  // print
	  print(hashTable,size);
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
int rehash(node* newHashTable[], node* oldHashTable[], int size)
{
  for( int i = 0; i< (size *2); i++)
    {
      //set everything in the new hashtable to null
      newHashTable[i] = NULL; 
    }
  for( int i = 0; i< size; i++) // go through the old one
    {
      node* n = oldHashTable[i];
      // go through each index and add each student to the new hashtable
      while(n != NULL)
	{
	  int index = getHashValue(n->student->id, size *2); //get the new index
	  addStudent(newHashTable,  index , n->student); //add
	  n = n->next;//go through each index for the old hashtable
	}
      

    }


  size = size * 2 ; // return the new size
  return size;
}
void deleteStudent(node* hashTable[], int id, int size)
{
  // first determine the location of this student based on its student id
  
  int index = getHashValue(id,size);
  node* head = hashTable[index];
  if (head == NULL) // if there is no student with the index
    {
      cout << "Such student doesn't exist!" << endl;
      return;	 
    }
  else 
    {
      if (head->student->id == id && head->next == NULL)
 	{ //if there is only one student
	  cout << "Student: " << head->student->firstName << " " << head->student->lastName << endl;
	  cout << "With student id: " << head->student->id << " and gpa: " << head->student->gpa << endl;
	  cout << "At index: " << index << " has been deleted." << endl;
	  delete head;
	  hashTable[index] = NULL;
	}
      else if (head->student->id == id && head->next != NULL)
	{//if there is more student and the first one is the one
	  
	  cout << "Student: " << head->student->firstName << " " << head->student->lastName << endl;
	  cout << "With student id: " << head->student->id << " and gpa: " << head->student->gpa << endl;
	  cout << "At index: " << index << " has been deleted." << endl;
	  hashTable[index] = head->next;
	  delete head;
	}
      else
	{//if the first one is not the one, find it, keep track of the previous one, and link the previous one to the next one, so we can delete the curret node
	  node* temp = head;
	  node* previous = temp;
	  while( temp != NULL)
	    {
	      if (temp->student->id == id)
		{
		  
		  break;
		}
	      else
		{
		  previous = temp;
		  temp = temp ->next;
		  
		}
	    }
	  if (temp ->next == NULL)
	    {
	      previous->next = NULL;
	    }
	  else
	    {
	      previous->next = temp ->next;
	    }	  
	  cout << "Student: " << temp->student->firstName << " " << temp->student->lastName << endl;
	  cout << "With student id: " << temp->student->id << " and gpa: " << temp->student->gpa << endl;
	  cout << "At index: " << index << " has been deleted." << endl;
	  delete temp;
	  
	}
      

    }
   
}
void addStudent(node* hashTable[], int index, student* news)
{
  //if there isn't any student at the index level
  if (hashTable[index] == NULL)
    {
      node* temp = new node();
      temp->student = news;
      hashTable[index] = temp;
    }
  else
    {
      //if not add this node to the beginning of the linked list at this level
      node* current = hashTable[index];
      node* temp = new node();
      temp->next = current; // put this one first
      temp->student = news;
    
      hashTable[index] = temp;
      current = temp;
      int length = 1;
    
    }
}

int getHashValue(int id, int size)
{
  // id mod size is my hash function
  return id % size;
  
}

student* create( char* firstName, char* lastName, int id, float gpa)
{
  student * news = new student();
  news->firstName = firstName;
  news->lastName = lastName;
  news->id = id;
  news->gpa = gpa;
  return news;
}
void print(node* hashTable[], int size)
{
  cout << "Student List" << endl;
  cout << "----------------------------------------" << endl;
	  
  node* n; // a pointer that walks through the hashTable
  for(int i= 0; i<size; i++) 
    {
      cout << i << endl;
      cout << "----------------------------------------" << endl;
	  
      if(hashTable[i] != NULL)
	{
	  n = hashTable[i];
    
	  while(n != NULL) // print all the student at this index
	    {
	      if (n->student!=NULL) // as long as a student exist, print them out.
		{
		  cout << "Student: " << n->student->firstName << " " << n->student->lastName << endl;
		  cout << "ID: " << n->student->id << "  GPA: " << n->student->gpa << endl;
		  cout << endl;
       
		}
	      n = n->next;
	    }
	}
      else
	{
	  //don't do anything and skip to next index
	}
      cout << "----------------------------------------" << endl;
	  
    }

}
