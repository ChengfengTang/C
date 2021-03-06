#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
// I apologize for the wordiness, it's really hard to explain the method, basically calculate the position of the bottom tree then work your way up
int main()
{
  int intarray[999] =  {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,-1,'\0'};
  // people don't really print a tree from int array, but since different trees have different ways of sorting, it's hard to print from node. But feel free to just alter it, the essence of printing shouldn't chagne
  // enter the number in the intarray above to test.
  int longestnumber = 0; // keep track of the longest number in the entire tree
  for (int i = 0; i<= 998; i++)
    {
      if (intarray[i] != -1) // go through the entire list. -2 by default means null in a tree, and -1 means the end of the list
	{
	  if (log10(intarray[i]) +1 > longestnumber) //log10 of a numb + 1 gives the digits of numbers 
	    {
	      longestnumber = log10(intarray[i])+1; //keep track of the longest number til the end of list
	    }
	}
      else
	{
	  break;
	}
    }
  // the longestnumber will be used to determine the length of every single number
  if (longestnumber %2 == 0) // make sure every number has a odd length, since there isn't a "center" for even digits
    {
      longestnumber ++;
    }
  //cout << "The longestnumber in the array list has a digit of: " << longestnumber << endl;
  
  int numbers = 0;
  for ( int i = 0; i <= 998; i++)
    {
      if (intarray[i] != -1)
        {
	  cout << intarray[i] << " ";
        }
      else
        {
	  numbers = i;
	  break;
        }     
    }
  // print out all the valid numbers, which are non -1s and keep track of the numbers of elements in the tree
  cout << "There are " << numbers << " numbers in the tree." <<endl;
  cout << endl;
  
  //calculate # of rows
  int rows =  log2(numbers) + 1; // 1 row has 1 number which is 2 to the 0 power+1. 2 rowshave 3 number which is 2 to the 1 power +1
   
  int indexbegin = pow(2,rows-1) -1;  // if there are 3rows, the bottom row should start at index 3 which is the 4th element
  int indexend = pow(2,rows) -2; // and ends at 6, which is the 7th element
  //if there are 4 rows, the bottom row should start at index 7, which is the 8th element
  //and end at 14, the 15th element
  
  int arrayindex = 0; // keep track of the elements' positions in the elementsindex
  int numberofpositions = indexend+1; // this is the number of positions the tree should contain, including spaces, basically
  // if a tree has 3 rows, it should have 7 numbers despite empty / null
  int elementsindex [numberofpositions] = {}; //basically where all the elements should be

  for (int i = 1; i<= (indexend - indexbegin +1); i++ ) // this calculate all of the bottom row's position
  {
  int position = ((i-1) * longestnumber) + (i-1)* 1 ; // 1 here is spacing between each element
  elementsindex[arrayindex] = position;    
  //cout << elementsindex[arrayindex] << endl;
  arrayindex++;
      
  }
  //calculate everything above this level now
  //basically, if the bottom row has 4 numbers, add up 1 and 2 to get 5, 3 and 4 to get 6, and add up 5 and 6 to get 1
  // when there is only 1 being added, that's the head and the last row since we are going backward.
  int initialindex = 0; 
  int maxindex = pow(2,rows-1)-1; // since we are starting from the last row, the max index should start from the number of elements of the bottom row
  for(int r = rows; r > 1; r--) //let's imagine there is 3 rows, which therefore 7 elements and a max index of 3, init of 0
    {
      for ( int i = initialindex;  i<= maxindex ; i++) // go from 0 to 3
	{
	  if (i%2 == 0 ) //if the number is even add this number and the previous one to calculate the position of the element in the next row
	    {     
	      int newnum =  (elementsindex[i] + elementsindex[i+1])/2;
	      elementsindex[arrayindex] = newnum; // add it to the elementsindex
	      arrayindex++;
	    }
	}
      initialindex = maxindex +1; // now initial index becomes max index + 1, so 4 in this case
      maxindex += pow(2,r-2); // and max index becomes 5, add by number of elements in the upcoming row, which is 2 for the second row
    }
  elementsindex[arrayindex] == '\0';
  
  // now we have the position for each number, we just need to print it!
  //but since we worked our way from the bottom, to print the tree would be backward, now let's flip it
  int newelementsindex [arrayindex] = {}; //printing in the right order
  int newarrayindex = 0; // keep track of the new array
  
  initialindex = arrayindex-1; // again let's imagine it's a perfect 3 rows binary tree
  maxindex = arrayindex-1; // the intial would then be 6, since there is 7 elements, and the max would also be 6 since the head always has one number.
  for (int r = 1; r<= rows; r++) //starting from row 1, which is the head
	{
	  for( int i = initialindex; i <= maxindex; i++)
	    {
	      newelementsindex[newarrayindex++] = elementsindex[i]; //add that to the new elementsindex 
	      //cout << elementsindex[i] << endl;
	    }
	  initialindex -= pow(2,r);
	  //cout << "init" << initialindex << endl;//go backward more, for example the intial should start at 4
	  maxindex -= pow(2,r-1);
	  //cout << "max: " << maxindex << endl;// and max should start at 5
	}
  newelementsindex[newarrayindex] == '\0';
  
  for (int i = 0; i<= newarrayindex -1; i++)
    {
      cout << newelementsindex[i] << endl;
    }
  //actual time to print
  int length = longestnumber*pow(2,rows-1) + (pow(2,rows-1) * 1 -1) - 1; // calculate the length of each row
  //imagine a 3 rows binary search tree with 3 digits numbers. that would just be 3 * 4 + 3 spaces = 15units, however since we are gonna be dealing with indexes, I am just gonna put an extra -1, so that the max index is actually 14
  cout << "Every row should have a index length of: " << length << endl;

  
  int a = 0;//basically a index indicator that helps me run through the program
  for (int j = 1; j <= rows; j++) // starting from the first row
    {
      int x = pow(2,j-1) -1; // x is basically the int array index indicator
      if (x == 0) // if this is the head
	{
	  for (int i = 0; i < newelementsindex[a]; i++)//keep the spacing
	    {
	      cout <<" ";
	    }
	  int l = log10(intarray[x])+1; // this is to make sure everything has the same length
	  for(int b= 0; b<longestnumber-l; b++)
	    {
	      cout << "0" ; // add a 0 if it has even nums of digits
	    }
	  cout << intarray[x] << endl;
	  a++;
	}
      else // if it's not a head
	{
	  for (int i = 0; i <= length;) //since every row has a set amount of index, we use this to determine the end of a row
	    {
	      if (i == newelementsindex[a]) //all the elementsindex are the position of a num, aka the numbers of spaces
		{ 
		  if (intarray[x] == -2) //-2 means null, if null just print the amount of space equal to the longest num
		    {
		      for (int b =0; b< longestnumber; b++)
			{
			  cout << " ";
			}
		      i+= longestnumber; // keep counting index for each row
		      a++; //next position
		      x++; //next number
		    }
		  else if (intarray[x] != -1)
		    {
		      int p = log10(intarray[x])+1; // p is the length of the current number
		      if (p <= longestnumber) // if it's shorter
			{
			  for (int b = 0; b< longestnumber-p; b++) // add 0s
			    {
			      cout << "0"; // 1 -> 001 if the longest digit is 3
			    }
			  cout << intarray[x];
			  i += longestnumber;
		  
			  a++;
			  x++;
			}
		    }
	      	  else //if it's -1 it's at the end of the int array
		    {
		      break;
		    }
		}
	      else //if there isn't a number at the current i position, just print space and keep going
		{
		  cout <<" ";
		  i ++;
		}
	    }
	  cout << endl; //move on to next row if current row is full
	}
    }
}

