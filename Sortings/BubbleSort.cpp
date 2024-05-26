#include<bits/stdc++.h>
using namespace std;

//Bubble sort -> swapping adjacent elements again and again so that maximum element shifts to rightmost position

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(vec[j]>vec[j+1])
                swap(vec[j],vec[j+1]);
        }
    }

    for(int i=0; i<n; i++)
        cout<<vec[i]<<" ";

    return 0;
}