// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void merge(int *arr,int s,int e)
{
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    
    int before[len1];
    int startindex=s;
    
    //creating new arrays before and after
    for(int i=0; i<len1; i++)
    {
        before[i]=arr[startindex++];
    }
    int after[len2];
    startindex=mid+1;
    for(int i=0; i<len2; i++)
    {
        after[i]=arr[startindex++];
    }
    
    startindex=s;
    //merging both the arrays
    int index1=0;
    int index2=0;
    while(index1<len1 && index2<len2)
    {
        if(before[index1]<after[index2])
        {
            arr[startindex++]=before[index1++];
        }
        else
        {
            arr[startindex++]=after[index2++];
        }
    }
    while(index1<len1)
    {
        arr[startindex++]=before[index1++];
    }
    while(index2<len2)
    {
        arr[startindex++]=after[index2++];
    }
        
    
    return;
}

void mergesort(int *arr,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
    
    return;
}

int main() {
    // Write C++ code here
    int arr[6]={5,2,4,1,8,3};
    mergesort(arr,0,5);
    for(int i=0; i<6; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}