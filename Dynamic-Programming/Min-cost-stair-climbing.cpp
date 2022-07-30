#include<bits/stdc++.h>
using namespace std;

int solveNaive(int n,vector<int>& vec)
{
    if(n==1)
        return vec[1];
    
    if(n==0)
        return vec[0];

    return min(solveNaive(n-1,vec),solveNaive(n-2,vec)) + vec[n];
}

int solvegood(int n,vector<int>& vec,vector<int>& dp)
{
    if(n==0)
        return vec[0];
    
    if(n==1)
        return vec[1];

    if(dp[n]!=-1)
        return dp[n];

    dp[n] = min(solvegood(n-1,vec,dp),solvegood(n-2,vec,dp)) + vec[n]; 

    return dp[n];
}

int solvewaygood(int n,vector<int>& vec)
{
    vector<int> dp(n+1,-1);
    
    dp[0]=vec[0];
    dp[1]=vec[1];

    for(int i=2; i<n; i++)
        dp[i] = min(dp[i-1],dp[i-2]) + vec[i];
    
    return min(dp[n-1],dp[n-2]);
}

int solveoptimized(int n,vector<int>& vec)
{
    int prev1=vec[1];
    int prev2=vec[0];
    
    for(int i=2; i<n; i++)
    {
        int curr = min(prev1,prev2) + vec[i];
        prev2=prev1;
        prev1=curr;
    }

    return min(prev1,prev2);
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    // int ans = min(solveNaive(n-1,vec),solveNaive(n-2,vec)); // Naive approach
    // cout<<ans<<endl;

    // vector<int> dp(n+1,-1); // Memoized approach
    // int ans = min(solvegood(n-1,vec,dp),solvegood(n-2,vec,dp));
    // cout<<ans<<endl;

    // int ans = solvewaygood(n,vec); // tabulation
    // cout<<ans<<endl; 

    // int ans=solveoptimized(n,vec); // tabulation best optimized 
    // cout<<ans<<endl;

    return 0;
}