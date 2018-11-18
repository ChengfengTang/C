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
  
  /*
    This is a game where I won't tell you what the exists are, and you have to figure it out by urself
    You have to name 5 items, and they will be randomly put into 5 different rooms, and your goal is to find all of them
    without directions and after u collected all of them, you would have to put all of them back into the room where they started 
    from. It's better if you don't name your items with the same name and I am running out of time so please don't name the same, otherwise
    you might get errors I will give u a map but I won't know which rooms have items.


   */

  
  name = new char[10];
  int roomnumber = 0;
  cout << "What's the name of the first item you want to create?" << endl;
  cin.get(name,10);
  cin.get();
  cout << name << " is created. " << endl;
  cout << endl;
  roomnumber =  rand() % 15 + 1;
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

  // add all the items to a vector so I can put them into the room with a for loop, otherwise this vector has no use
  vector<item*> items;
  items.push_back(one);
  items.push_back(two);
  items.push_back(three);
  items.push_back(four);
  items.push_back(five);

  vector<item*> inventory;
  // inventory
  
  vector <room*> alltherooms;
  //a vector with all the rooms.

  // all the rooms have the same description since it's a maze, so  I don't know what the point of having a description but I just do
  // anyway
  room* roomone = new room((char*)"one", (char*)"This is a room");
       
  room* roomtwo = new room((char*)"two", (char*)"This is a room");
  
  room* roomthree = new room((char*)"three", (char*)"This is a room");
  
  room* roomfour = new room((char*)"four", (char*)"This is a room");
  
  room* roomfive = new room((char*)"five",(char*) "This is a room");
  
  room* roomsix = new room((char*)"six", (char*)"This is a room");
  
  room* roomseven = new room((char*)"seven", (char*)"This is a room");
  
  room* roomeight= new room((char*)"eight",(char*) "This is a room");
  
  room* roomnine = new room((char*)"nine",(char*) "This is a room");
  
  room* roomten = new room((char*)"ten", (char*)"This is a room");
  
  room* roomeleven = new room((char*)"eleven", (char*)"This is a room");
  
  room* roomtwelve = new room((char*)"twelve",(char*) "This is a room");
  
  room* roomthirteen = new room((char*)"thirteen",(char*) "This is a room");
  
  room* roomfourteen = new room((char*)"fourteen", (char*)"This is a room");
  
  room* roomfifteen = new room((char*)"fifteen", (char*)"This is a room");
  
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

  // set all the exit and itself( when the user is going in a direction where there isn't a room, it ends up going to itself instead of
  // null
  roomone->setitself(roomone);
  roomtwo->setitself(roomtwo);
  roomthree->setitself(roomthree);
  roomfour->setitself(roomfour);
  roomfive->setitself(roomfive);
  roomsix->setitself(roomsix);
  roomseven->setitself(roomseven);
  roomeight->setitself(roomeight);
  roomnine->setitself(roomnine);
  roomten->setitself(roomten);
  roomeleven->setitself(roomeleven);
  roomtwelve->setitself(roomtwelve);
  roomthirteen->setitself(roomthirteen);
  roomfourteen->setitself(roomfourteen);
  roomfifteen->setitself(roomfifteen);

  
    
  roomone->setnorthexit(roomthree);
  roomone->setwestexit(roomtwo);

  roomtwo->seteastexit(roomone);

  roomthree->setnorthexit(roomsix);
  roomthree->setwestexit(roomfive);
  roomthree->setsouthexit(roomone);
  roomthree->seteastexit(roomfour);

  roomfour->setwestexit(roomthree);

  roomfive->setwestexit(roomfourteen);
  roomfive->seteastexit(roomthree);
  
  roomsix->setwestexit(roomthirteen);
  roomsix->setsouthexit(roomthree);
  roomsix->seteastexit(roomseven);

  roomseven->setnorthexit(roomten);
  roomseven->setwestexit(roomsix);
  roomseven->seteastexit(roomeight);

  roomeight->setwestexit(roomseven);
  roomeight->setsouthexit(roomnine);

  roomnine->setnorthexit(roomeight);

  roomten->setsouthexit(roomseven);
  roomten->setwestexit(roomeleven);

  roomeleven->setwestexit(roomtwelve);
  roomeleven->seteastexit(roomten);

  roomtwelve->seteastexit(roomeleven);
  roomtwelve->setsouthexit(roomthirteen);

  roomthirteen->setnorthexit(roomtwelve);
  roomthirteen->seteastexit(roomsix);

  roomfourteen->setnorthexit(roomfifteen);
  roomfourteen->seteastexit(roomfive);

  roomfifteen->setsouthexit(roomfourteen);
  
  // start at room 1
  room* currentroom;
  currentroom = roomone;
  // basically add all the items to their corresponding rooms.
  // Liam taught me how to do case and switch, I would have done it with if
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
  int gamemode =1;
	  
  while (true)
    {
      //game mode 1 is to pick up items
      // once u have collected all of them, you will start game mode 2 which is to put them back
      
      if ( gamemode == 1)
	{
	  if (inventory.size() == 5)
	    {
	      cout << "You have succesfully collected all the items, now put them back to where they belong." << endl;
	      gamemode = 2;
	      
		
	     }
	  
	}
      /*
      if (gamemode == 2)
	{
	  if ( one.getroomnumber == 

	}
      */
      cout << endl;
      cout << endl;
      cout << endl;
      cout << "You are currently in: Room " ;
      cout <<  currentroom->getname()<< endl;
      cout << currentroom->getdescription() << endl;
      currentroom->start(); // this tells you if there is anything in the room or not 
      cout << endl;
      cout << "What do you want to do?" << endl;
      cout << "Type in a direction to go somewhere Ex. \"WEST\" \"EAST\" \"NORTH\" \"SOUTH\" " << endl;
      cout << "Type in \"PICK\" if there is any items in the currentroom" << endl;
      cout << "Type in \"DROP\" if you want to drop one of your items in the currentroom" << endl;
      cout << "Type in \"INVENTORY\" to see what items you have with you" << endl;
      cout << endl;
      cout << endl;
      cout << endl;

      
      


      input = new char[100];
      memset(input, '\0', sizeof(input));

      cin.getline(input, 100);

      // if you say pick and there is anything in the room, you will just pick it up
      // u would have to say pick twice if there is more than 1 items.
      if (strcmp(input, "PICK") == 0)
      {
	if (currentroom->checkitem() == true)
	  {
	    inventory.push_back(currentroom->itemsintheroom());
     
	     currentroom->deleteitem((currentroom->itemsintheroom())->getname());
	    
	  }
	else
	  {
	    cout << "There isn't any items in the room." << endl;
	  }
	      
      }
      // check ur inventory
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

      // if you want to drop something
      // you would have to tell me what's the name of it
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
		      inventory.erase(ita);
		      break;
		    }
		}
	      
	    }

	}
	 else if (strcmp(input, "WEST") == 0)
      {
       
	 currentroom = currentroom->gowest();

      }
	 else if (strcmp(input, "NORTH") == 0)
       {
	  currentroom = currentroom->gonorth();
	    
       }
       else if (strcmp(input, "SOUTH") == 0)
       {
       
	 currentroom = currentroom->gosouth();
	   

       }
       else if (strcmp(input, "EAST") == 0)
       {
	 
	 currentroom = currentroom->goeast();
  
	   }
	 else if (strcmp(input, "QUIT") == 0)
       {
	     return 0;
	}
     else
       {
	 cout << "Invalid Command!"  <<endl;
	 cout << endl;
	 cout << endl;
	 continue;
      }
      
    }
}
