#include<bits/stdc++.h>
using namespace std;

//Check rotated sorted array or not

int main()
{
    int n;
    cin>>n; 
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    int cnt=0;
    for(int i=0; i<n-1; i++)
    {
        if(vec[i]>vec[i+1])
            cnt++;
    }

    if(cnt<=1)
        cout<<"Rotated Sorted";
    else
        cout<<"Not Rotated Sorted";

    return 0;
}