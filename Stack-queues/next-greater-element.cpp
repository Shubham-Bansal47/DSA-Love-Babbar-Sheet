#include<bits/stdc++.h>
#include<stdlib.h>
#define ll long long int
using namespace std;

vector<long long> nextLargerElement(vector<long long>& arr, int n)
{
        stack<long long> se;
        unordered_map<long long,int> m;
        int i,j;
        for(i=0; i<n; i++)
        {
            m[arr[i]]=i;
        }
        for(i=0; i<n; i++)
        {
            if(se.empty())
            {
                se.push(arr[i]);
                continue;
            }
            if(se.top()>arr[i])
            {
                se.push(arr[i]);
                continue;
            }
            else if(se.top()<arr[i])
            {
                while(!se.empty() && se.top()<arr[i])
                {
                    arr[m[se.top()]]=arr[i];
                    se.pop();
                }
                se.push(arr[i]);
            }
        }
        while(!se.empty())
        {
            arr[m[se.top()]]=-1;
            se.pop();
        }
        
        return arr;
}

int main()
{
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    nextLargerElement(arr,n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}    