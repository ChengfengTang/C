#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include "room.h"
#include "item.h"
using namespace std;


int main ()
{
  char* name;
  char* input;
  
  cout <<"Welcome to Chengfeng Tang's Zuul game! "<< endl;
  cout <<"There will be 5 items that you have to create at the beginning of the game!" << endl;
  cout << "and they will be randomly put into some of the 15 rooms." << endl;
  cout << "You will have to collect all of them at first!" << endl;
  cout << "and correctly put them back to the room where they belong to finish the game" << endl;
  cout << endl;
  

  name = new char[10];
  int roomnumber = 0;
  cout << "What's the name of the first item you want to create?" << endl;
  cin.get(name,10);
  cin.get();
  cout << name << " is created. " << endl;
  cout << endl;
  roomnumber = rand() % 15 + 1;
  cout << roomnumber << endl;
  item* one = new item(name,roomnumber);

  
  name = new char[10];
  roomnumber = 0;
  cout << "What's the name of the second item you want to create?" << endl;
  cin.get(name,10);
  cin.get();
  cout << name << " is created. " << endl;
  cout << endl;
  roomnumber = rand() % 15 + 1;
  cout << roomnumber << endl;
  item* two = new item(name,roomnumber);

  
  name = new char[10];
  roomnumber = 0;
  cout << "What's the name of the third item you want to create?" << endl;
  cin.get(name,10);
  cin.get();
  cout << name << " is created. " << endl;
  cout << endl;
  roomnumber = rand() % 15 + 1;
  cout << roomnumber << endl;
  item* three = new item(name,roomnumber);

  
  name= new char[10];
  roomnumber = 0;
  cout << "What's the name of the fourth item you want to create?" << endl;
  cin.get(name,10);
  cin.get();
  cout << name << " is created. " << endl;
  cout << endl;
  roomnumber = rand() % 15 + 1;
  cout << roomnumber << endl;
  item* four = new item(name,roomnumber);

  
  name = new char[10];
  roomnumber = 0;
  cout << "What's the name of the fifth item you want to create?" << endl;
  cin.get(name,10);
  cin.get();
  cout << name << " is created. " << endl;
  cout << endl;
  roomnumber = rand() % 15 + 1;
  cout << roomnumber << endl;
  item* five = new item(name,roomnumber);

  vector<item*> items;
  items.push_back(one);
  items.push_back(two);
  items.push_back(three);
  items.push_back(four);
  items.push_back(five);

  vector<item*> inventory;
  
  vector <room*> alltherooms;
  
  room* roomone = new room("one", "This is a room");
       
  room* roomtwo = new room("two", "This is a room");
  
  room* roomthree = new room("three", "This is a room");
  
  room* roomfour = new room("four", "This is a room");
  
  room* roomfive = new room("five", "This is a room");
  
  room* roomsix = new room("six", "This is a room");
  
  room* roomseven = new room("seven", "This is a room");
  
  room* roomeight= new room("eight", "This is a room");
  
  room* roomnine = new room("nine", "This is a room");
  
  room* roomten = new room("ten", "This is a room");
  
  room* roomeleven = new room("eleven", "This is a room");
  
  room* roomtwelve = new room("twelve", "This is a room");
  
  room* roomthirteen = new room("thirteen", "This is a room");
  
  room* roomfourteen = new room("fourteen", "This is a room");
  
  room* roomfifteen = new room("fifteen", "This is a room");
  
  alltherooms.push_back(roomone);
 
  alltherooms.push_back(roomtwo);
 
  alltherooms.push_back(roomthree);
 
  alltherooms.push_back(roomfour);
 
  alltherooms.push_back(roomfive);
 
  alltherooms.push_back(roomsix);
 
  alltherooms.push_back(roomseven);
 
  alltherooms.push_back(roomeight);
 
  alltherooms.push_back(roomnine);
 
  alltherooms.push_back(roomten);
 
  alltherooms.push_back(roomeleven);
 
  alltherooms.push_back(roomtwelve);
 
  alltherooms.push_back(roomthirteen);
 
  alltherooms.push_back(roomfourteen);
 
  alltherooms.push_back(roomfifteen);
       
  room* currentroom;
  currentroom = roomone;

  for (vector<item*>::iterator it = items.begin(); it != items.end(); ++it) {
    
    switch ((*it)->getroomnumber())

      {
      case 1:
      roomone->additem(*it);
      break;
    
      case 2:
      roomtwo->additem(*it);
      break;
    case 3:
      roomthree->additem(*it);
      break;
    case 4:
      roomfour->additem(*it);
      break;
    case 5:
      roomfive->additem(*it);
      break;
    case 6:
      roomsix->additem(*it);
      break;
    case 7:
      roomseven->additem(*it);
      break;
    case 8:
      roomeight->additem(*it);
      break;
    case 9:
      roomnine->additem(*it);
      break;
    case 10:
      roomten->additem(*it);
      break;
    case 11:
      roomeleven->additem(*it);
      break;
    case 12:
      roomtwelve->additem(*it);
      break;
    case 13:
      roomthirteen->additem(*it);
      break;
    case 14:
      roomfourteen->additem(*it);
      break;
    case 15:
      roomfifteen->additem(*it);
      break;
      }
  }

	  
  while (true)
    {
      cout << endl;
      cout << endl;
      cout << endl;
      cout << "You are currently in: Room " ;
      cout <<  currentroom->getname()<< endl;
      cout << currentroom->getdescription() << endl;
      currentroom->start();
      cout << endl;
      cout << "What do you want to do?" << endl;
      cout << "Type in a direction to go somewhere Ex. \"WEST\" " << endl;
      cout << "Type in \"PICK\" if there is any items in the currentroom" << endl;
      cout << "Type in \"DROP\" if you want to drop one of your items in the currentroom" << endl;
      cout << "Type in \"INVENTORY\" to see what items you have with you" << endl;
      cout << endl;
      cout << endl;
      cout << endl;

      
      


      input = new char[100];
      memset(input, '\0', sizeof(input));

      cin.getline(input, 100);


      if (strcmp(input, "PICK") == 0)
      {
	if (currentroom->checkitem() == true)
	  {
	    

	    
	    inventory.push_back(currentroom->itemsintheroom());
	    
	    //currentroom->deleteitem();
	    
	  }
	else
	  {
	    cout << "There isn't any items in the room." << endl;
	  }
	      
      }
      else if (strcmp(input, "INVENTORY")==0)
	{
	  if (inventory.empty() == 1)
	    {
	      cout << "You don't have anything!" << endl;
	    }
	  else
	    {
	  cout << "You have: " << endl;
	  for (vector<item*>::iterator it = inventory.begin(); it != inventory.end(); ++it)
	    {
	      cout << (*it) ->getname() << endl;
	  }
	    }
	}
      else if (strcmp(input, "DROP") == 0)
	{
	  if (inventory.empty() == 1)
	    {
	      cout << "You don't have anything in your inventory!" << endl;
	      
	    }
	  else
	    {
	      cout << "Which one would you like to drop?" << endl;
	      cout << "You have: " << endl;
	      for (vector<item*>::iterator it = inventory.begin(); it != inventory.end(); ++it) 
		{
		  cout << (*it)->getname() << " \t ";
		}
	      cout << endl;
	      name = new char[10];
	      cin.get(name,10);
	      cin.get();
	      
	      for (vector<item*>::iterator ita = inventory.begin(); ita != inventory.end(); ++ita) 
		{
		  if( strcmp((*ita)->getname(),name) == 0)
		    {
		      currentroom->additem(*ita);
		      //inventory.erase(ita);
		    }
		}
	      
	    }

	}
	 else if (strcmp(input, "WEST") == 0)
      {
	
      }
	 else if (strcmp(input, "NORTH") == 0)
       {
	 currentroom = roomtwo;

       }
     else
       {
	 cout << "Invalid Command!"  <<endl;
	 cout << endl;
	 cout << endl;
	continue;
      }
      
    }


  return 0;
}
