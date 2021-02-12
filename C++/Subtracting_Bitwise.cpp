/******************************************************************************

// C program to Subtract two numbers
// without using arithmetic operators

*******************************************************************************/

// Example program
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

// Example program
#include <iostream>
#include <vector>
using namespace std;



int main()
{
  int x = 3;
  int y= 3;
  int borrow;
  while (y != 0)
     {
         // borrow contains common
         // set bits of y and unset
         // bits of x
         borrow = (~x) & y;
         cout<<"1: X :"<<x <<" y:"<<y<<" borrow:"<<borrow<<endl;
         // Subtraction of bits of x
         // and y where at least one
         // of the bits is not set
         x = x ^ y;
         cout<<"2: X :"<<x <<" y:"<<y<<" borrow:"<<borrow<<endl;
         // Borrow is shifted by one
         // so that subtracting it from
         // x gives the required sum
         y = borrow << 1;
         cout<<"3: X :"<<x <<" y:"<<y<<" borrow:"<<borrow<<endl<<"\n";
     }
     cout<<"Final result:"<<x<<endl;
}
