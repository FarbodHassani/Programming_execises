#include <iostream>

int Fib (int n)
{
    if (n ==1)
        return 1;
    if (n==2)
        return 2;
return (Fib (n-1) + Fib (n-2));
}
using namespace std;
int main()
// Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:
//1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
//By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
{
  int n = 1; int sum = 0;
  while (Fib(n)<4000000)
  {
    if (Fib(n)%2 == 0)
      sum = sum + Fib(n);
    cout<<"Fibb: "<<Fib(n)<<" n:"<<n<<endl;
    n++;
  }
cout<<"Fibb last :" <<Fib(33)<<endl;
cout<<"Sum :" <<sum<<endl;
}