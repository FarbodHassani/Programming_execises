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

int f(){
    return 5 ;
}

void inner(int depth,vector<int> & numbers,vector<int> & maxes){
  if (depth>0){
     for(int i=1;i<maxes[depth-1]+1;i++){
        numbers[depth-1]=i;
        inner(depth-1, numbers,maxes) ;
     }
  }else{
     // calculate sum of x,y,z:
    //  cout << "values are ";
    //  for(int i=0;i<numbers.size();i++){
        cout <<numbers[0]<<"\t"<<numbers[1]<<"\t"<<numbers[2]<<" ";
    //  }
     int thesum(0);
     for(int i=0;i<numbers.size();i++){
        thesum+=numbers[i];
     }
     if (thesum==f()){
        // cout << "True! ";
     }
     cout<<endl;
   }
}

void donest(){
   vector<int>  numbers;
   numbers.resize(3);
   vector<int>  maxes;
   maxes.push_back(6);
   maxes.push_back(6);
   maxes.push_back(6);
   inner(numbers.size(),numbers,maxes);
}

int main(){
   donest();
}





// #include <iostream>
// #include <vector>
// using namespace std;
// using namespace std;
// // We use the following void function to loop over n dice and make the sample space correspondingly
// // My solution is not the best, as I've used a vector to make the sample space!
// int sample_space(int n, vector<int> & numbers,int outcome){
//   if (n>0)
// 	{
//      for(int i=1;i<7;i++) // The results of each dice
// 		 {
//         numbers[n-1]=i; // i is assigned to the outer layer
//         sample_space(n-1,numbers,outcome); // Then for each i we loop over the inner layers until we reach n=0.
//      }
//   }
// 	else
// 	{
//      //for(int i=0;i<numbers.size();i++)
//      //cout <<numbers[i]<<"\t"; // In case you want to see the outcomes
//      int sum=0;
// 		 int counter=0;
//      for(int i=0;i<numbers.size();i++)
//         sum+=numbers[i];
//      if (sum==outcome)
// 			 counter++;
//
//      cout<<endl;
//    }
// }
// int diceRoll(int n, int outcome) {
// 	std::
//
// }
