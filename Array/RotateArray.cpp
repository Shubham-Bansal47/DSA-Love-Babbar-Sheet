#include<bits/stdc++.h>
using namespace std;

//Rotate array by K numbers 

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> vec(n),res(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];
   
    k=k%n;
    for(int i=0; i<n; i++)
        res[(i+k)%n]=vec[i];
    
    for(int i=0; i<n; i++)
        cout<<res[i]<<" ";

    return 0;
}