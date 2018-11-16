#include <iostream>
#include <cstring>
#include <vector>
#include <stdlib.h>
#include "rooms.h"
using namespace std;


struct item
{
  char name[10];
  int roomnumber;
};



int main ()
{
  cout <<"Welcome to Chengfeng Tang's Zuul game! "<< endl;
  cout <<"There will be 5 items that you have to create at the beginning of the game!" << endl;
  cout << "and they will be randomly put into some of the 15 rooms." << endl;
  cout << "You will have to collect all of them at first!" << endl;
  cout << "and correctly put them back to the room where they belong to finish the game" << endl;
  cout << endl;

  item one;
  cout << "What's the name of the first item you want to create?" << endl;
  cin.get(one.name,10);
  cin.get();
  cout << one.name << " is created. " << endl;
  cout << endl;
  one.roomnumber = rand() % 15 + 1;
  cout << one.roomnumber << endl;
  
  cout << "What's the name of the second item you want to create?" << endl;
  item two;
  cin >> two.name;
  cout << two.name << " is created. " << endl;
  cout << endl;
  two.roomnumber = rand() % 15 + 1;
  cout <<two.roomnumber << endl;

 cout << "What's the name of the third item you want to create?" << endl;
  item three;
  cin >> three.name;
  cout << three.name << " is created. " << endl;
cout << endl;
 three.roomnumber = rand() % 15 + 1;
 cout <<three.roomnumber << endl;
  
  cout << "What's the name of the fouth item you want to create?" << endl;
  item four;
  cin >> four.name;
  cout << four.name << " is created. " << endl;
cout << endl;
 four.roomnumber = rand() % 15 + 1;
 cout <<four.roomnumber << endl;
  
 
  cout << "What's the name of the fifth item you want to create?" << endl;
  item* five = new item;
  cin >> five.name;
  cout << five.name << " is created. " << endl;
  cout << endl;
  five.roomnumber = rand() % 15 + 1;
  cout <<five.roomnumber << endl;


  vector<item> items;
  items.push_back(one);
  items.push_back(two);
  items.push_back(three);
  items.push_back(four);
  items.push_back(five);

  vector<item> inventory;
  
  vector <rooms*> alltherooms;
  
  rooms* roomone = new rooms("one", "This is a room");
       
  rooms* roomtwo = new rooms("two", "This is a room");
  
  rooms* roomthree = new rooms("three", "This is a room");
  
  rooms* roomfour = new rooms("four", "This is a room");
  
  rooms* roomfive = new rooms("five", "This is a room");
  
  rooms* roomsix = new rooms("six", "This is a room");
  
  rooms* roomseven = new rooms("seven", "This is a room");
  
  rooms* roomeight= new rooms("eight", "This is a room");
  
  rooms* roomnine = new rooms("nine", "This is a room");
  
  rooms* roomten = new rooms("ten", "This is a room");
  
  rooms* roomeleven = new rooms("eleven", "This is a room");
  
  rooms* roomtwelve = new rooms("twelve", "This is a room");
  
  rooms* roomthirteen = new rooms("thirteen", "This is a room");
  
  rooms* roomfourteen = new rooms("fourteen", "This is a room");
  
  rooms* roomfifteen = new rooms("fifteen", "This is a room");
  
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
       
  rooms* currentroom;
  currentroom = roomone;
  
  for (vector<item>::iterator it = items.begin(); it != items.end(); ++it) {
    switch ((it)->roomnumber) {
    case 1:
      roomone.additem(*it);
      break;
    case 2:
      roomtwo.additem(*it);
      break;
    case 3:
      roomthree.additem(*it);
      break;
    }
  }

	
  
  cout << currentroom->getdescription() << endl;

  Game state;
  
  while (true) {
    char input[100];
    memset(input, '\0', sizeof(input));

    cin.getline(input, sizeof(input));

    
    if (strcmp(input, "WHERE") == 0) {
      Game.listExits();
    }

    if (strncmp(input, "PICKUP", 6)) {
      char* name = input + 7;
      
    }

    if (strncmp(input, "GO", 2) == 0) {
      char* location = input + 3;
      Direction dir;
      if (strcmp(location, "NORTH") == 0) {
	dir = Direction::North;
      } else if (strcmp(location, "EAST") == 0) {
	dir = Direction::South;
      } else {
	continue;
      }
      
      Game.changeRoom(dir);
    }
  }

  return 0;
}
