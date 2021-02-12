// Example program
#include <iostream>
#include <string>
#include <cmath>
int diceRoll(int n, int outcome)
{
	int i[n+1]; //An array for n loops to make the sample space of rolling n dice
for (int a=0; a<n+1; a++) //
{
  i[a]=0;
}
int sum = 0;
int counter=0;
int m = 0;
while (i[n]==0)
{
    sum=0;
    for (int a=0; a<n; a++)
    {
			sum +=i[a]+1;
// 			std::cout<<i[a]+1<<",";
    	// std::cout<<" a:"<<a<< "   i[a]:"<<i[a]+1<<"\t";// If U want to print the values
    }
    if (sum == outcome)
    {
			counter++;
// 			std::cout<<" sum:"<<sum<<" counter:"<<counter<<"\t";
    }
	i[0]++;
  while(i[m]==6)
	{
    i[m]=0;
    i[++m]++;
    if(i[m]!=6)
      m=0;
	}
}
return counter;
}

int main()
{

std::cout<<" : "<<diceRoll(6, 20) ;

}
