#include<iostream>
void transpose(int arr[][100],int rows1,int cols2);
void multiplication(int a[][100],int b[][100],int rows1,int rows2,int cols1,int cols2);
void multiplication(int a[][100],int b[][100],int matrix[][100],int rows1,int rows2,int cols1,int cols2)
{
    int i,j,k;
    
    if(cols1==rows2)
    {
    for(i=0;i<rows1;i++)
      {
       for(j=0;j<cols2;j++)
    {
        for(k=0;k<cols1;k++)
        {
            matrix[i][j]+= a[i][k]*b[k][j];
        }
    }
}

}
else
std::cout<<"multiplication not applicable";
}
void transpose(int arr[][100],int transposed[][100],int rows,int cols)
{
    int i,j;
 for(i=0;i<rows;i++)
 {
    for(j=0;j<cols;j++)
    {
        arr[i][j]=arr[j][i];
    }
 }
}
void printmatrix(int arr[][100],int rows,int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            std::cout<<arr[i][j]<<" ";
        }
        std::cout<<'\n';
    }
}
int main()
{
    int rows1,rows2,cols1,cols2,i,j;
    std::cout<<"enter the dimensions of the 1st matrix";
    std::cin>>rows1;
    std::cin>>cols1;
    std::cout<<"enter the dimensions of the 2nd matrix";
    std::cin>>rows2;
    std::cin>>cols2;
    int a[rows1][100];
    int b[rows2][100];
    int matrix[100][100];
    int transposedA[100][100];
    int transposedB[100][100];
    int result[100][100];
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
    multiplication(a,b,matrix,rows1,cols1,rows2,cols2);
    printmatrix(matrix,rows1,cols2);
    transpose(a,transposedA,rows1,cols1);
    transpose(a,transposedB,rows1,cols1);
    printmatrix(transposedA,cols1,rows1);
    printmatrix(transposedB,cols2,rows2);
    transpose(matrix,result,rows1,cols2);
    printmatrix(result,cols2,rows1);
    int transposedmultiplication[100][100];
    multiplication(transposedB,transposedA,transposedmultiplication,cols2,rows2,cols1,rows1);
    printmatrix(transposedmultiplication,cols2,rows1);



}
