#include <iostream>
using namespace std;
void bubble(int arr[], int n) 
{
    if(n==1)
    return;
    for (int i = 0;i<n-1;i++) 
    {
        if (arr[i]>arr[i+1]) 
        {
            int temp=arr[i];
            arr[i]=arr[i + 1];
            arr[i + 1]=temp;
        }
    }
    bubble(arr,n-1);
}

int main() {
    int n;
    cout<<"Enter the size of the array ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin>>arr[i];
    }
    bubble(arr,n);
    cout << "Sorted array: ";
    for (int i=0; i<n; i++) 
    {
        cout<< arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}
