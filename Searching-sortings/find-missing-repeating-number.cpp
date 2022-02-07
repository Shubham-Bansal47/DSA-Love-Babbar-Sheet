#include<bits/stdc++.h>
using namespace std;

int *findTwoElement(int *arr, int n) 
{
        int i=0,j,x,y;
        for(i=0; i<n; i++)
        {
            if(arr[abs(arr[i])-1]<0)
            {
                x=abs(arr[i]);
            }
            else
            {
                arr[abs(arr[i])-1]*=-1;
                
            }
        }
        for(i=0; i<n; i++)
        {
            if(arr[i]>0)
            {
                y=i+1;
            }
        }
        int *arr1=new int[2];
        arr1[0]=x;
        arr1[1]=y;
        return arr1;
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
    int *v=findTwoElement(arr,n);
    cout<<v[0]<<" "<<v[1];
}