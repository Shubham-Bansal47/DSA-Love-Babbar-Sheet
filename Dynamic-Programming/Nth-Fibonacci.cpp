#include<bits/stdc++.h>
using namespace std;

int solveNaive(int n) // Tc - O(N) Sc - O(N)+O(N)
{
    if(n<=1)
        return n;

    return solveNaive(n-1)+solveNaive(n-2);    
}

int solvegood(int n,vector<int>& dp) // Tc - O(N) Sc - O(N) Memoized approach
{
    //Base Case
    if(n<=1)
        return n;

    //using vector to check value in it so it becomes fast
    if(dp[n]!=-1)
        return dp[n];

    //recursion call
    dp[n]=solvegood(n-1,dp)+solvegood(n-2,dp);

    return dp[n];
}

void solvewaygood(int n) // Tc - O(N) Sc - O(N) tabulation
{
    vector<int> dp(n+1);
    dp[0]=0;
    dp[1]=1;

    for(int i=2; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    cout<<dp[n];

    return;
}

void solveoptimized(int n) // Tc - O(N) Sc - (1) tabulation
{
    int prev2=0;
    int prev1=1;

    if(n==0)
        cout<<0<<endl;

    for(int i=2; i<=n; i++)
    {
        int curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }

    cout<<prev1<<endl;

    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int> dp(n+1,-1);

    // int ans=solveNaive(n); // solveNaive approach
    // cout<<ans<<endl;
    
    // solvegood(n,dp); // solvegood approach
    // cout<<dp[n];

    // solvewaygood(n); //solvewaygood approach

    // solveoptimized(n); // solveoptimized approach

    return 0;
}