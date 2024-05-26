#include<bits/stdc++.h>
using namespace std;

// array intitialise
//int arr[5]={1,3,5,6,7};
//reverse array
// time complexity  Big(O) -> Upper bound   Big(theta) -> avg case    Big(omega) -> lower bound

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    for(int i=0; i<n/2; i++)
        swap(arr[i],arr[n-1-i]);

    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";

    return 0;
}