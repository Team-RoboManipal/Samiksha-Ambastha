#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
void arrange(char arr[][100],int n)
{
 int i, j ;
 char temp[100];
 for(i=0;i<n-1;i++)
 {
    for(j=0;j<n-i-1;j++)
    {
        if(strlen(arr[j])<strlen(arr[j+1]))
        {
            strcpy(temp,arr[j]);
            strcpy(arr[j],arr[j+1]);
            strcpy(arr[j+1],temp);
        }
    }
 }

}
void sort(char arr[][100],int n)
{
  for (int i = 0; i < n; i++) 
  {
        
        std::sort(arr[i], arr[i] + strlen(arr[i]));
}
}
int main()
{
 int n,i;
 cout<<"enter the number of words";
 cin>>n;
 cout<<"enter the strings";
char a[n][100];
 for(i=0;i<n;i++)
 {
    cin>>a[i]; }

 arrange(a,n);
 cout<<"resultant "<<'\n';
 for(i=0;i<n;i++)
 {
    cout<<a[i]<<'\n';

 }
 sort(a,n);
 std::cout<<"sorted letters words= "<<'\n';
 for(i=0;i<n;i++)
 {
    cout<<a[i]<<'\n';

 }
 

}
