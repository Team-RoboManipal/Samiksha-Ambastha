#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool am(int n, int m)
{
int i,j,f=0,g=0;
 for (i=1;i<=n;i++)
 {
    if(n%i==0)
    f=f+i;
 }
 for (j=1;j<=m;j++)
 {
    if(m%j==0)
    g=g+j;
 }
 if(f==g)
 return true;
 
}
string binary(int n)
{
    int x,i,y;
    string s="";
    char temp;
    while(n>0)
    {
        x=n%2;
        s+=to_string(x);
        n/=2;
        
    }
    y=s.length();
for(i=0;i<y/2;i++)
{
    temp=s[i];
    s[i]=s[y-i-1];
    s[y-i-1]=temp;
}
return s;
}
int octal(int n)
{
    int x,r=0,p=0,y;
    while(n>0)
    {
        x=n%8;
        r=r*10+x;
        n=n/8;
    }
    while(r>0)
    {
        y=r%10;
        p=p*10+y;
        r=r/10;
    }
    return p;
}
string hexa(int n)
{
   int x,i,y;
   string s="";
   char temp;
   if(n==0)
{
    return "0";
}
while(n>0)
{
   x=n%16;
   if(x>9)
   {
    switch(x)
    {
        case 10: 
        s+="A";
        break;
        case 11: 
        s+="B";
        break;
        case 12: 
        s+="C";
        break;
        case 13: 
        s+="D";
        break;
        case 14: 
        s+="E";
        break;
        case 15: 
        s+="F";
        break;

    }
    
   } 
   else
    {
        s+=to_string(x);
    }
    n/=16;
}
y=s.length();
for(i=0;i<y/2;i++)
{
    temp=s[i];
    s[i]=s[y-i-1];
    s[y-i-1]=temp;
}

    return s;
}
int main()
{
 int n,octalnumber,p,q;
 string hexadecimal,binaryform;
 bool amicable;
 cout<<"enter an number";
 cin>>n;
 hexadecimal=hexa(n);
 cout<<"hexadecimal= "<<hexadecimal<<'\n';
 octalnumber=octal(n);
 cout<<"octal= "<<octalnumber<<'\n';
 binaryform=binary(n);
 cout<<"binary= "<<binaryform<<'\n';
 cout<<"enter two number to check for amicable number";
 cin>>p;
 cin>>q;
 amicable=am(p,q);
 if(amicable)
 cout<<"the numbers are amicabe";
 else
 cout<<"the numbers are not amicable";


} 
