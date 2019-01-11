#include <iostream>
#include <string.h>
#include "movie.h"
#include "videogame.h"
#include <vector>
#include "parentmedia.h"
#include "music.h"
using namespace std;
 
int main ()
{
  /*
    All the possible character arrays that will be used 
   */
  char* name;
  char* director;
  char* publisher;
  char* artist;
  char* title;
  char* answer;
  char* answer2;
  char commands[99];
  int one = 1;
  int year = 0; 
  // introduce my code first
  vector<media*> allmedialist;
  cout << "Welcome to Chengfeng Tang's classes project" << endl;
  cout << "You can add in three types of media: music, movies and video games" << endl;
  cout << " Type \"ADD\" to add a type of media" << endl;
  cout << " Type \"PRINT\" to print out all the medias" << endl;
    cout << " Type \"SEARCH\" to look for medias based on the name or the published date." << endl;
    cout << " Type \"DELETE\" to delete medias based on name or the published date." << endl;
            cout << " Type \"QUIT\" to quit the program" << endl;


   while (one  = 1)
    {
      cout << "What would you like to do now?" << endl;

	cin.getline(commands,99, '\n');
	// if the user wants to add
	if (strcmp(commands, "ADD") == 0 )
	  {

	    
  cout << "What is the name of the media?" << endl;
 name = new char[99];
 cin.get(name,99);
 cin.get();
 int length1 = strlen(name);
 name[length1] = '\0';
  cout << "What year was it published?" << endl;
 
  cin >> year;
  cin.get();
  // gather the name & the year of the media, then ask what type of media it is
  
  int mediatype = 0;
  while ((mediatype != 1) &&(mediatype != 2) &&(mediatype != 3))
    {
  cout << "what type of media is it? 1 for movies, 2 for video games, 3 for music" << endl;
   cin >> mediatype;
   cin.get();
    }
  // if it's a movie, then ask the user to fill out the required fields for a movie 
  if (mediatype == 1)
    {
     
      cout << "What's the name of the director?" << endl;
      director = new char[99];  
      cin.get(director,99);
      cin.get();
 
 int length1 = strlen(director);
 director[length1] = '\0';

 cout << "How long is the movie in mins?" << endl;

					     int duration = 0;
					     cin >> duration;
	 cin.get();

	 cout << "What's the rating of the movie out of 10?" << endl;
								float rating = 0.0;
								cin >> rating;
		 cin.get();
		 movie* temp = new movie(name, year, director, duration, rating, mediatype);
		 allmedialist.push_back(temp);
		 // put this media into the media list
    }
  else if (mediatype == 2) // same thing to video games
   {
     cout << "Who published the video game?" << endl;
    publisher = new char [99];  
 cin.get(publisher,99);
 cin.get();
 
 int length1 = strlen(publisher);
 publisher[length1] = '\0';


     cout << "What was the rating of the video game?" << endl;
     float rating = 0;
     cin >> rating;
     cin.get();
     videogame* temp = new videogame(name, year, publisher, rating,mediatype); 
     allmedialist.push_back(temp);

   }
  else if (mediatype == 3) // and musics
   {
     cout << "Who was the artist of the music? " << endl;

  artist = new char [99];  
 cin.get(artist,99);
 cin.get();
 
 int length1 = strlen(artist);
 artist[length1] = '\0';

      cout << "Who published the music?" << endl;
            publisher = new char[99];  
 cin.get(publisher,99);
 cin.get();
 
 int length2 = strlen(publisher);
 publisher[length2] = '\0';

      cout << "How long was the music in seconds?" << endl;
      int duration = 0;  
	    cin >> duration;
	    cin.get();

	    music * temp = new music(name,year,publisher,artist,duration,mediatype);
	    allmedialist.push_back(temp);

	    
   }
  
 
    
  	}
	else if (strcmp(commands, "PRINT") == 0)
	  {
	    //if the user wants to print but has no medias added

	    if (allmedialist.empty() == 1)
	      {
		cout << "Your media list is empty!" << endl;
	      }
	    else
	      {
		//go through the entire media vectors, since media itself keeps track of types of media, print different info based on the type of media
      for (vector<media*>::iterator it = allmedialist.begin(); it!= allmedialist.end(); ++it)
      {
	if ((*it)->gettype() == 1)
	  {
	  cout << "Movie: "<<endl;
	    cout << "Title: \t" << (*it)->getname() << endl;
	cout << "Year Published: \t" <<(*it)->getyear() << endl;
	
	cout <<"Director: \t" << ((movie*)(*it))->getdirector() << endl;
	cout << "Duration: \t" <<((movie*)(*it))->getduration() << endl;
	cout << "Rating: \t" << ((movie*)(*it))->getrating() << endl;
	cout <<endl;
	  }
	else if ((*it)->gettype() == 2)
	  {
	cout << "Video Game: "<<endl;
	    cout << "Title: \t" << (*it)->getname() << endl;
	cout << "Year Published: \t" <<(*it)->getyear() << endl;
	
	cout <<"Publisher: \t" << ((videogame*)(*it))->getpublisher() << endl;
	cout << "Rating: \t" << ((videogame*)(*it))->getrating() << endl;
	  
	
	cout <<endl;
	  }
	else if ((*it)->gettype() == 3)
	  {
	cout << "Music: "<<endl;
	    cout << "Title: \t" << (*it)->getname() << endl;
	cout << "Year Published: \t" <<(*it)->getyear() << endl;
	
	cout <<"Publisher: \t" << ((music*)(*it))->getpublisher() << endl;
	cout << "Artist: \t" <<((music*)(*it))->getartist() << endl;
	cout << "Duration: \t" << ((music*)(*it))->getduration() << endl;
	cout << endl;
	  }

      }

      
      
	      }
	  }
	else if (strcmp(commands, "SEARCH") ==0)

	  {
	    // if the user wants to look for medias but have nothing in the media vector
	    if (allmedialist.empty() == 1)
	      {
		cout << "Your media list is empty" << endl;
	      }
	    else
	      {
	    cout << "Do you know the name of the media that you are looking for ?" << endl;
	    
	    cout << "Type in \"Y\" if you do, and anything else if you don't " << endl;
	    // ask for the name of it, it he has it look for medias based on names
	    
	     answer = new char [99];
	     answer2 = new char[99];
	    int year = 0;
	    title = new char[99];
	    
	    cin.get(answer,99);
	     cin.get();
	    int length = strlen(answer);
	    answer[length] = '\0';
	    	     
	    if (strcmp(answer, "Y") == 0)
	      {
		cout << "What is it? " << endl;
		 
	    cin.get(title,99);
	     cin.get();
	    int length = strlen(title);
	    title[length] = '\0';
	    	     
	    cout << "Looking for media with matching title of: " <<title <<endl;
		
	       for (vector<media*>::iterator it = allmedialist.begin(); it!= allmedialist.end(); ++it)
		 {
		   // go through entire medialist and find the ones with same title
		   if (strcmp(  ((media*)(*it))->getname(), title ) == 0 )
		     {
		       cout << "Found it!" << endl;
		       if ((*it)->gettype() == 1)
			 {
			   cout << "Movie: "<<endl;
			   cout << "Title: \t" << (*it)->getname() << endl;
			   cout << "Year Published: \t" <<(*it)->getyear() << endl;
	
			   cout <<"Director: \t" << ((movie*)(*it))->getdirector() << endl;
			   cout << "Duration: \t" <<((movie*)(*it))->getduration() << endl;
			   cout << "Rating: \t" << ((movie*)(*it))->getrating() << endl;
			   cout <<endl;
			 }
		       else if ((*it)->gettype() == 2)
			 {
			   cout << "Video Game: "<<endl;
			   cout << "Title: \t" << (*it)->getname() << endl;
			   cout << "Year Published: \t" <<(*it)->getyear() << endl;
	
			   cout <<"Publisher: \t" << ((videogame*)(*it))->getpublisher() << endl;
			   cout << "Rating: \t" << ((videogame*)(*it))->getrating() << endl;
	  
	
			   cout <<endl;
			 }
		       else if ((*it)->gettype() == 3)
			 {
			   cout << "Music: "<<endl;
			   cout << "Title: \t" << (*it)->getname() << endl;
			   cout << "Year Published: \t" <<(*it)->getyear() << endl;
	
			   cout <<"Publisher: \t" << ((music*)(*it))->getpublisher() << endl;
			   cout << "Artist: \t" <<((music*)(*it))->getartist() << endl;
			   cout << "Duration: \t" << ((music*)(*it))->getduration() << endl;
			   cout << endl;
			 }
		     }
		   else
		     {
		       cout << "Can't find any" << endl;
		     }     
		 }
	      }
	    else  // if the user doesn't know the name, but knows the year
	      {
		cout << "Do you know the year that the media was pubished?" << endl;
	      
	    cout << "Type in \"Y\" if you do, and anything else if you don't " << endl;
	    	 
	    cin.get(answer2,99);
	      cin.get();
	    int length = strlen(answer2);
	    answer2[length] = '\0';
	     
	    if (strcmp(answer2, "Y") == 0)
	      {
		cout << "What is it? " << endl;
		cin >> year;
		cin.get();
		cout << "Looking for media with matching published year of: " << year << endl;
		 for (vector<media*>::iterator it = allmedialist.begin(); it!= allmedialist.end(); ++it)
		 {
		  
		   if ( ((media*)(*it))->getyear() == year  )
		     {
		       cout << "Found it!" << endl;
		       if ((*it)->gettype() == 1)
			 {
			   cout << "Movie: "<<endl;
			   cout << "Title: \t" << (*it)->getname() << endl;
			   cout << "Year Published: \t" <<(*it)->getyear() << endl;
	
			   cout <<"Director: \t" << ((movie*)(*it))->getdirector() << endl;
			   cout << "Duration: \t" <<((movie*)(*it))->getduration() << endl;
			   cout << "Rating: \t" << ((movie*)(*it))->getrating() << endl;
			   cout <<endl;
			 }
		       else if ((*it)->gettype() == 2)
			 {
			   cout << "Video Game: "<<endl;
			   cout << "Title: \t" << (*it)->getname() << endl;
			   cout << "Year Published: \t" <<(*it)->getyear() << endl;
	
			   cout <<"Publisher: \t" << ((videogame*)(*it))->getpublisher() << endl;
			   cout << "Rating: \t" << ((videogame*)(*it))->getrating() << endl;
	  
	
			   cout <<endl;
			 }
		       else if ((*it)->gettype() == 3)
			 {
			   cout << "Music: "<<endl;
			   cout << "Title: \t" << (*it)->getname() << endl;
			   cout << "Year Published: \t" <<(*it)->getyear() << endl;
	
			   cout <<"Publisher: \t" << ((music*)(*it))->getpublisher() << endl;
			   cout << "Artist: \t" <<((music*)(*it))->getartist() << endl;
			   cout << "Duration: \t" << ((music*)(*it))->getduration() << endl;
			   cout << endl;
			 }
		     }
		   else
		     {
		       cout << "Can't find any" << endl;
		     }     
		 }
	      }
	    else // if the user doesn't have any information then he can't search
	      {
		cout << "You don't have enough information :D " << endl;
	      }
	    
	      }
	      }
	    
	  }
	else if (strcmp (commands, "DELETE") == 0)
	  {
	    // basically the same as search, but instead of printing out just record the location of vector and remove them.
	    if (allmedialist.empty() == 1)
	      {
		cout << "Your media list is empty!" << endl;
		
	      }
	    else
	      {
	    cout << "Do you know the name of the media that you are looking for ?" << endl;
	    
	    cout << "Type in \"Y\" if you do, and anything else if you don't " << endl;

	     answer = new char [99];
	     answer2 = new char[99];
	    int year = 0;
	    title = new char[99];
	    
	    cin.get(answer,99);
	     cin.get();
	    int length = strlen(answer);
	    answer[length] = '\0';
	    	     
	    if (strcmp(answer, "Y") == 0)
	      {
		cout << "What is it? " << endl;
		 
	    cin.get(title,99);
	     cin.get();
	    int length = strlen(title);
	    title[length] = '\0';
	    	     
	    cout << "Deleting media with matching title of: " <<title <<endl;
	    
	    int x = 1;
	    // basically keep deleting until either the media list is empty
	    // or when there isn't any in the medialist that matches the title
	    while (x != 0 && allmedialist.size()!= 0 )
	      {
	    for (vector<media*>::iterator it = allmedialist.begin(); it!= allmedialist.end(); ++it)
		 {
		  
		  if (strcmp(  ((media*)(*it))->getname(), title ) == 0 )
		     {
		       
		       allmedialist.erase(it);
		       break;
		       
		     }
		  else if (it == allmedialist.end() - 1)
		     {
		       x = 0;
		     }
		 }
	      }
	     }
	    else 
	      {
		cout << "Do you know the year that the media was pubished?" << endl;
	      
	    cout << "Type in \"Y\" if you do, and anything else if you don't " << endl;
	    	 
	    cin.get(answer2,99);
	      cin.get();
	    int length = strlen(answer2);
	    answer2[length] = '\0';
	     
	    if (strcmp(answer2, "Y") == 0)
	      {
		cout << "What is it? " << endl;
		cin >> year;
		cin.get();
		cout << "Deleting media with matching published year of: " << year << endl;
		
		       
	    int x = 1;
	    // basically keep deleting until either the media list is empty
	    // or when there isn't any in the medialist that matches the title
	    while (x != 0 && allmedialist.size()!= 0 )
	      {
	    for (vector<media*>::iterator it = allmedialist.begin(); it!= allmedialist.end(); ++it)
		 {
		  
		  
		   if ( ((media*)(*it))->getyear() == year  )
		     {      
		       allmedialist.erase(it);
		       break;
     
		     }
		   else if (it == allmedialist.end() - 1)
		     {
		       x = 0;
		       
		     }
		 }
	      }
	    
		    
	      }
	    else
	      {
		cout << "You don't have enough information :D " << endl;
	      }
	    
	      }
	      }
	  }
	else if (strcmp (commands, "QUIT") == 0)
	  {
	    cout << "Glad to help you." << endl;
	    return 0 ;
	  }
	else
	  {
	    cout << "I don't understand your command, please remmeber to captitalize!" << endl;
	  }
    }
}
