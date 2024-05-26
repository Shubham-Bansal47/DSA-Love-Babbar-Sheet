#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    int key;
    cout<<"Enter the key to find ";
    cin>>key;

    int s=0;
    int e=n-1;
    int posstart=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(vec[mid]<key)
            s=mid+1;
        else if(vec[mid]>key)
            e=mid-1;
        else
        {
            posstart=mid;
            e=mid-1;
        }
    }

    s=0;
    e=n-1;
    int posend=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(vec[mid]<key)
            s=mid+1;
        else if(vec[mid]>key)
            e=mid-1;
        else
        {
            posend=mid;
            s=mid+1;
        }
    }

    cout<<posstart<<" "<<posend;
    
    return 0;
}