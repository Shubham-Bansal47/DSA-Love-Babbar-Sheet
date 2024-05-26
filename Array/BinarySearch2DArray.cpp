#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>arr[i][j];
    }
    int key;
    cin>>key;
    int s=0;
    int e=n*m-1;
    bool check=false;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        int row=mid/n;
        int col=mid%m;
        if(arr[mid]<key)
            s=mid+1;
        else if(arr[mid]>key)
            e=mid-1;
        else
        {
            cout<<"Key Found at "<<mid;
            check=true;
            break;
        }
    }
    cout<<check;

    return 0;
}