#include<iostream>
int main()
{
    int rows1,cols1,rows2,cols2,i,j,k;
    std::cout<<"enter the dimensions of the 1st matrix";
    std::cin>>rows1;
    std::cin>>cols1;
    std::cout<<"enter the dimensions of the 2nd matrix";
    std::cin>>rows2;
    std::cin>>cols2;
    int a[rows1][cols1];
    int b[rows2][cols2];
    int matrix[rows1][cols2];
    if(cols1==rows2)
    {
    std::cout<<"enter the elements of 1st matrix";
    for(i=0;i<rows1;i++)
    {
        for(j=0;j<cols1;j++)
        {
            std::cin>>a[i][j];
        }
    }
    std::cout<<"enter the elements of 2nd matrix";
    for(i=0;i<rows1;i++)
    {
        for(j=0;j<cols1;j++)
        {
            std::cin>>b[i][j];
        }
    }
for(i=0;i<rows1;i++)
{
    for(j=0;j<cols2;j++)
    {
        for(k=0;k<cols1;k++)
        {
            matrix[i][j]= a[i][k]+b[k][j];
        }
    }
}
std::cout<<"resulatant matrix after multiplication"<<'\n';
for(i=0;i<rows1;i++)
    {
        for(j=0;j<cols1;j++)
        {
            std::cout<<matrix[i][j]<<"  ";
        }
        std::cout<<'\n';
    }

    }
    else
    {
        std::cout<<"multiplication not possible";
    }
}
