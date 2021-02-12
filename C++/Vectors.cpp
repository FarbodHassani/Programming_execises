/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// Example program
#include <iostream>
#include <vector>
using namespace std;

std::vector<int> arrayOfMultiples(int num, int length) {
std::vector<int> result;
	for (int i=0; i<length;i++)
	{
		result[i] = num*(i+1);
	}
	return result;
}

int main()
{
std::vector<int> arr(3);
arr[0] = 2;
std::cout<<" "<<arr[0];
}
