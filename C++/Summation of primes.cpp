#include <iostream>
#include <cmath>
using namespace std;
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
// Find the sum of all the primes below two million.
bool isprime (long n)
{
  if (n==1)
      return(0);
  for (long i =2; i<sqrt(n)+1; i++)
  {
    if (n%i == 0 && n!=2 )
      return(0);
  }
  return(1);
}

int main()
{
long result = 0;
long i =2;
long last_num = 2000000;
while (i < last_num )
  {
    if (isprime (i))
    {
        // cout<<i<<endl;
        result = result + i;
    }
    i++;
  }
  cout<<"Num_prime is: "<<result<<endl;

}
