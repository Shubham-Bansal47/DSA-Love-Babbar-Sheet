#include<bits/stdc++.h>
using namespace std;

void PowerSet(vector<vector<int>> &ans,vector<int> &vec,vector<int> temp,int i)
{
    if(i>=vec.size())
    {
        ans.push_back(temp);
        return;
    }

    PowerSet(ans,vec,temp,i+1);
    temp.push_back(vec[i]);
    PowerSet(ans,vec,temp,i+1);

    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    vector<vector<int>> ans;
    vector<int> temp;
    int i=0;
    PowerSet(ans,vec,temp,i);

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        
        cout<<"\n";
    }

    return 0;
}