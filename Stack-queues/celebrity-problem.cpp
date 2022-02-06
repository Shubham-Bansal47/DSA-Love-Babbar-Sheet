#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& M, int n) 
    {
        int i,j,c=0;
        for(i=1; i<n; i++)
        {
            if(M[c][i]==1)
            {
                c=i;
            }
        }
        for(i=0; i<n; i++)
        {
            if(i!=c && (M[c][i]==1 || M[i][c]==0))
            {
                return -1;
            }
        }
        return c;
    }

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> M(n,vector<int> (n,0));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>M[i][j];
        }
    }
    int x=celebrity(M,n);
    cout<<x;
}