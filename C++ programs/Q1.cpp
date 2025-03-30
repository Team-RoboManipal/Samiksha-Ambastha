#include<iostream>
#include<cstring>
int main()
{
  int n,i,j,temp;
  std::cout<<"enter the string";
 char a[100];
std::cin>>a; 
  n=strlen(a);
   
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
        if(a[j]>a[j+1])
        {
            char temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
        }
    }
  }
  
  std::cout << a;

