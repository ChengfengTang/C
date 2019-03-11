/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    int intarray[100] =  { 108,39,48,17,16,5,4,3,2,1,-1,-1,-1,-1 };
    int longestnumber = 3;
    int numbersize[10] = {3,2,2,2,2,1,1,1,1,1};
    int numbers = 0;
    for ( int i = 0; i <= sizeof(intarray); i++)
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
    cout << endl;
   int rows =  log2(numbers) + 1; 
   cout << rows << endl;
   int lastrow = (2 ^ rows) ;
   cout << lastrow << endl;
   int spacing[] = new [100];
   int spacingindex = 0;
   int spaces = 0;
   for (int a = lastrow; a<= 100; a++)
   {
       if (intarray[a] != -1)
        { 
            if (numbersize[a] <= longestnumber)
            {
               
                for (int x = 1; x<= longestnumber-numbersize[a]; x++)
                {
                    cout << "0"; // 1 -> 001 if the longest digit is 3
                }
            }
            cout << intarray[a] << " ";
            spaces += longestnumber + 1;
            if (a%2 == 0)
            {
            spacing[spacingindex++] = spaces; 
            cout << spaces << endl;
            }
            //   002      
            // 001 004 008 007
        }
        else
        {
            break;
        }
            
    }
    
    


    return 0;
}
