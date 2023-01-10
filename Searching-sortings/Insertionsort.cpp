#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=7;
    int arr[n]={10,1,7,4,8,2,11};       
    int element=arr[0];
    for(int i=1; i<n; i++)
    {
        int index=i;
        for(int j=i-1; j>=0; j--)
        {
            if(arr[i]<arr[j]) index--;
            else break;
        }
        int temp=arr[i];
        for(int j=i; j>index; j--)
        {
            arr[j]=arr[j-1];
        }
        arr[index]=temp;
    }
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";

    return 0;
}