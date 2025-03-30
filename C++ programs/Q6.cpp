#include<iostream>
using namespace std;
void bubble(int arr[],int n)
{
    int temp,i,j;
 for(i=0;i<n-1;i++)
 {
    for(j=0;j<n-i-1;j++)
    {
        if(arr[j]>arr[j+1])
        {
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
    }
    }
 }
 for(i=0;i<n;i++)
 {
    cout<<arr[i]<<" ";
 }

}
void selection(int arr[],int n)
{
    int pos,temp,i;
 for (int i = 0; i < n - 1; i++)
  {
      pos= i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[pos]) 
            {
                pos= j;
            }
        }
        temp = arr[pos];
        arr[pos] = arr[i];
        arr[i] = temp;
 }
    for(i=0;i<n;i++)
      {
       cout<<arr[i]<<" ";
      }

  }
int search(int arr[],int key,int n)
{
    int mid,high,low,i;
    low=0;
    high=n-1;
 do
   {
    mid=(low+high)/2;
    if(key<arr[mid])
    high=mid-1;
    else if(key>arr[mid])
    low=mid+1;

   }while(key!=arr[mid]&&low<=high);
    if(key==arr[mid])
      {
       cout<<"number found at "<<mid+1<<'\n';
      }
    for(int i=0;i<n;i++)
      {
       cout<<arr[i]<<" ";
      }

}
int main()
{
 int n,i,key;
 cout<<"enter the number of elements of arrays";
 cin>>n;
 int a[n];
 char x;
 cout<<"enter b for bubble sort,s for selection sort";
 cin>>x;
 cout<<"enter the elements";
 for(i=0;i<n;i++)
 {
   cin>>a[i];
 }
 
 switch(x)
 {
    case 's':
    selection(a,n);
    break;
    case 'b':
    bubble(a,n);
    break;

 }
 cout<<"enter the number to be searched";
 cin>>key;
 search(a,key,n);
 return 0;
 }
