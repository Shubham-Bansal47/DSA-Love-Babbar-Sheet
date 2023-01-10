#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &question,vector<int> vec,vector<vector<int>> &ans,int index)  //  3 
{
    if(index==question.size())
    {
        ans.push_back(vec);
        return;
    }

    solve(question,vec,ans,index+1);
    vec.push_back(question[index]);
    solve(question,vec,ans,index+1);

    return;
}

int main()
{
    int n=3;
    vector<int> question(n);
    for(int i=0; i<n; i++) cin>>question[i];
    vector<vector<int>> ans;
    vector<int> vec;
    int index=0;
    solve(question,vec,ans,index);
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++) 
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";

        cout<<"   ";
    }

    return 0;
}