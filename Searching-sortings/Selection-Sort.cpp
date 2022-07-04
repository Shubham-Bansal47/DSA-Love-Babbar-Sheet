#include<bits/stdc++.h>
using namespace std;

void selectionsort(int arr[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        int min1=arr[i];
        int k=i;
        for(int j=i+1; j<n; j++)
        {
            if(min1>=arr[j])
            {
                min1=arr[j];
                k=j;
            }
        }
        swap(arr[i],arr[k]);
    }
    return;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    selectionsort(arr,n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}