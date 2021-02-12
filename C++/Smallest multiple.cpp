#include <iostream>
#include <math.h>
using namespace std;
// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

bool divisble_till (int n, int m) //Function that tells us if a number is evenly divisble by all numbers till m
{
  for (int i=1; i<m+1;i++)
    {
      if (n % i != 0)
        return(0);
    }
  return(1);
}

int main()
{
  int n = 1;
    while (true)
    {
      if (divisble_till (n,20) == 1) break;
      n++;
    }
    cout<<"A number "<<n<<endl;
}

// #############
// ##mathematica :
// ##############
//
