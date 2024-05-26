#include<bits/stdc++.h>
using namespace std;

// Works only on sorted array
// Time Complexity O(Log(n))

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
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(vec[mid]<key)
            s=mid+1;
        else if(vec[mid]>key)
            e=mid-1;
        else
        {
            cout<<"key found ";
            cout<<"At index -> "<<mid;
            return 0;
        }
    }

    return 0;
}