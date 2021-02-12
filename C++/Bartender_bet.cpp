#include <iostream>
#include <string>
using namespace std;
int main()
// Finding the guessed number between high and low nums and winning 10'000 $, after log (n) , one certanly would guess! The logarithmic algorithm like Newton's method!
{

int num;
cout<<"Inter your num: "<<endl;
cin>> num;
cout<<"Your num is: "<<num<<endl;
int low, high, mean;
high=1000000;
low=1;
int counter = 0;
while (true)
{

 counter ++;
  mean = (high + low)/2;
 // cout<<"mean: "<<mean<<" High " <<high << " low "<<low<<endl;
  if ( mean == num)
  {
    cout<<"Succees after "<<counter<<" attempt" << "You num is: "<< mean <<endl;
    break;
  }

  if (mean > num)     high = mean-1;
  if (mean < num) low = mean+1;
  cout<<"counter " << counter<< "  number: "<<mean<<endl;;

}
}
