// Las Vegas style dice have 6 sides numbered 1 to 6. When rolling 2 dice, a six is 5 times more likely than a two because a six can be rolled 5 different ways (1 + 5, 5 + 1, 2 + 4, 4 + 2, 3 + 3), while a two can only be rolled 1 way (1 + 1).
//
// Create a function that accepts two arguments:the number of dice rolled, and the outcome of the roll. The function returns the number of possible combinations that could produce that outcome. The number of dice can vary from 1 to 6.
//
// For the example given above:
//
// dice_roll(2, 6) would return 5
// dice_roll(2, 2) would return 1
// Examples
// dice_roll(1, 3) ➞ 1
//
// dice_roll(2, 5) ➞ 4
// # 1 + 4, 4 + 1, 2 + 3, 3 + 2
//
// dice_roll(3, 4) ➞ 3
// # 1 + 1 + 2, 1 + 2 + 1, 2 + 1 + 1
//
// dice_roll(4, 18) ➞ 80
//
// dice_roll(6, 20) ➞ 4221
//https://edabit.com/challenge/wJnPYPoS8TaHQDbM3
#include <iostream>
#include <vector>
using namespace std;

std::vector<int> sample_space(int n, std::vector<int> & numbers)
{
  if (n>0)
	{
     for(int i=1;i<7;i++) // The results of each dice
		 {
        numbers[n-1]=i; // i is assigned to the outer layer
        sample_space(n-1,numbers); // Then for each i we loop over the inner layers until we reach n=0.
     }
  }
return numbers;
}

int main()
{
vector<int> numbers_new;
numbers_new.resize(2);
// sample_space(numbers_new.size(),numbers_new);
// cout<<" "<<sample_space(numbers.size(),numbers)[1]<<endl;
for(int i=0;i<numbers_new.size();i++){
        cout <<sample_space(numbers_new.size(),numbers_new)[0]<<" "<<"\n";
}
// vector<int> num,vec;
// numbers = sample_space(2, numbers.resize(2),1);
// cout<<" "<<sample_space(2, num.resize(2),1)<<endl;
}
