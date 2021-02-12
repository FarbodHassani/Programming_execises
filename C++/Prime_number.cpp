#include <iostream>
#include <cmath>
using namespace std;

bool isprime (unsigned long long n)
{
  for (unsigned long long i =2; i<sqrt(n)+1; i++)
  {
    if (n%i == 0)
      return(0);
  }
  return(1);
}

unsigned long long Max_prime (unsigned long long n)
{
    unsigned long long max=0;
    for (unsigned long long i=2;i<sqrt(n)+1 ;i++)
        {
            if (n%i ==0 && isprime(i) == 1 ) // If it was a factor of n and  check if it is prime
                 max = i;  // if it is prime then it's the max
        }
    return max;
}

int main()
// The prime factors of 13195 are 5, 7, 13 and 29.
//What is the largest prime factor of the number 600851475143 ?
{
unsigned long long number = 600851475143;
cout<<"Max prime :" <<Max_prime(number)<<endl;
cout<<"Is prime :" <<isprime(number)<<endl;

}
