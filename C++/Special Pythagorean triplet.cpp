#include <iostream>
#include <cmath>
using namespace std;

int main()
{
double c=1;
int result=1;
    for (int i=1;i<500;i++)
    {
        for (int j=i;j<500;j++)
        {
            c = sqrt(i*i+j*j);
             if((trunc(c) == c) && i+j+c==1000)
             {
                cout<<"Reesult: "<<i<<","<<j<<","<<c<<endl;
                result = i*j*c;
             }
        }
    }
cout<<"result: "<<result;

}
