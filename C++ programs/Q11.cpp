#include<iostream>
using namespace std;
int search(int a[],int low,int high,int n)
{
 if(low<=high)
 {
    int mid=(low+high)/2;
    if(a[mid]==n)
    return mid;
    else if(a[mid]>n)
    return search(a,low,mid-1,n);
    else
    return search(a,mid+1,high,n);

 }
 else
 return -1;

 
 
}
int main()
{
 int n,i,num;
 cout<<"enter the number of elements";
 cin>>n;
 int a[n];
 cout<<"enter a sorted array";
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }
 cout<<"enter the number to be searched";
 cin>>num;
 int result=search(a,0,n-1,num);
 if(result!=-1)
  cout<<"number found at "<<result+1;
  else
  cout<<"not found";

}
