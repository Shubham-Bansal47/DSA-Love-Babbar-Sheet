#include<bits/stdc++.h>
using namespace std;

int binarySearch(int start,int end,int key,vector<int>& vec)
{
    int s=start;
    int e=end;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(vec[mid]<key)
            s=mid+1;
        else if(vec[mid]>key)
            e=mid-1;
        else
            return mid;
    }

    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    int key;
    cout<<"Enter key you want to find ";
    cin>>key;

    int s=0;
    int e=n-1;
    while(s<e)
    {
        int mid=s+(e-s)/2;
        if(vec[0]<=vec[mid])
            s=mid+1;
        else
            e=mid;
    }

    int pivot=s;

    if(key>=vec[0])
        cout<<binarySearch(0,pivot-1,key,vec); 
    else
        cout<<binarySearch(pivot,n-1,key,vec);

    return 0;
}