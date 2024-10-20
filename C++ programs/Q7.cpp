#include<iostream>
#include<string>
using namespace std;
string copystr(string a)
{
    string *p,strp;
    p = &a;
    strp = *p;

    return strp;
}

int main()
{
    string str;
    cout << "enter string: ";
    getline(cin,str);
    
    cout << "copied string= " << copystr(str) <<'\n';
}
