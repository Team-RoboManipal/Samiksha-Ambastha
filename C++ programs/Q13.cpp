#include<iostream>
using namespace std;
int sumwithout(int n)
{
 int sum=0,x;
 while(n!=0)
 {
    x=n%10;
    sum+=x;
    n/=10;
 }
 return sum;
}
int sumwith(int n)
{

    if(n==0)
    {
        return 0;

    }
 return (n%10)+sumwith(n/10);
}
int main()
{
int n,sum1,sum2;
cout<<"enter a number";
cin>>n;
cout<<"sum without recursion="<<'\n';
sum1=sumwithout(n);
cout<<sum1<<'\n';
cout<<"sum with recursion= "<<'\n';
 sum2=sumwith(n);
cout<<sum2;
}
