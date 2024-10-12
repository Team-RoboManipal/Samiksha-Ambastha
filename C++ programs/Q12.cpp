#include<iostream>
using namespace std;
int factorial(int n)
{
    if(n==0)
    return 1;
    return n*factorial(n-1);
}
int main()
{
 int n;
 cout<<"enter a number to find";
 cin>>n;
 int result=factorial(n);
 cout<<result
;
}
