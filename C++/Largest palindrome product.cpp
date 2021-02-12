#include <iostream>
#include <math.h>
using namespace std;
// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
//
// Find the largest palindrome made from the product of two 3-digit numbers.
bool ispalindrome ( unsigned long long int n)
{
    string str = to_string (n); //converting to string
  for (int i=0; i<int(str.length()/2)+1;i++) //loop on the digits
    {
        if (str[i]!=str[str.length()-i-1])
            return(0);
    }
    return(1);
}

int main()
{
   unsigned long long int max_palindrome = 10001;
   unsigned long long int min = 100;
   unsigned long long int max = 1000;
   int number1 =1, number2=1;
    for (unsigned long long int i=min;i<max;i++)
    {
        for (unsigned long long int j=min;j<max;j++)
        {
            if (ispalindrome(i*j) && (i*j) >= max_palindrome )
            {
                max_palindrome = i*j;number1 = i; number2 = j;
            }
        }
    }
    cout<<"max_palindrome: "<<max_palindrome<<" num1: "<<number1<<" num2: "<<number2<<endl;
}

// #############
// ##mathematica :
// ##############
//
// Max[Select[Flatten[Table[i*j, {i, 100, 999}, {j, 100, 999}]], PalindromeQ]]
