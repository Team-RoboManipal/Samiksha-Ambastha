#include<iostream>
#include<cstring>
int main()
{
    int row,cols,i,j,x,p,k=0;
    std::cout<<"enter the dimension of the matrix";
    std::cin>>row;
    std::cin>>cols;
    int m[row][cols];
    int r[row]={0},c[cols]={0};

    std::cout<<"enter the elements of the matrix";
for(i=0;i<row;i++)
    {
       for(j=0;j<cols;j++)
        {
        std::cin>>m[i][j];
        }
    }
for (int i = 0; i < row; i++) 
{
    for (int j = 0; j < cols; j++)
     {
        if (m[i][j] == 0) {
                r[i] = 1;  
                c[j] = 1;  
            }
        }
    }
for (int i = 0; i < row; i++) 
{
    if (r[i] == 1) {
            for (int j = 0; j < cols; j++) 
            {
                m[i][j] = 0;
     }
        }
    }

for (int j = 0; j < cols; j++) 
{
        if (c[j] == 1) {
            for (int i = 0; i < row; i++) 
            {
                m[i][j] = 0;
            }
        }
    }
    
std::cout<<"result="<<'\n';
for (int i = 0; i < row; i++) 
{
        for (int j = 0; j < cols; j++) 
        {
            std::cout << m[i][j] << " ";
        }
        std::cout <<'\n';
    }




}
