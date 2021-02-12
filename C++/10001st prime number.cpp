#include <iostream>
#include <cmath>
using namespace std;
//By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
// What is the 10 001st prime number?
bool isprime (int n)
{
  for (int i =2; i<sqrt(n)+1; i++)
  {
    if (n%i == 0)
      return(0);
  }
  return(1);
}

int main()
{
int num_prime = 0;
int i =1;
int last_prime = 10001;
while (num_prime < last_prime )
  {
    if (isprime (i))
    {
        num_prime++;
    }
    i++;
  }
  cout<<"Num_prime is: "<<i-1<<endl;
}
