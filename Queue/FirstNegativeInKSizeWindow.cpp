#include<bits/stdc++.h>
using namespace std;
// 
vector<int> FirstIntegers(vector<int> &vec,int k)
{
    vector<int> ans;
    queue<pair<int,int>> q;
    int i=0;
    int j=0;
    while(j<vec.size())
    {
        if(j-i+1<k)
        {
            if(vec[j]<0)
                q.push({vec[j],j});
            
            ++j;
        }
        else if((j-i+1)==k)
        {
            if(vec[j]<0)
                q.push({vec[j],j});

            if(q.empty())
            {    
                ans.push_back(0);
                ++i;
                ++j;
            }// 3 4 -1 5 -3 -1 7
            else
            {
                while(q.front().second+k<=j)
                    q.pop();
                
                if(q.empty())
                    ans.push_back(0);
                else
                    ans.push_back(q.front().first);

                ++i;
                ++j;
            }
        }
    }

    return ans;
}

void PrintVector(vector<int> ans)
{
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";

    return;
}

int main()
{
    cout<<"Enter value of K"<<endl;
    int k;
    cin>>k;
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    vector<int> ans=FirstIntegers(vec,k);
    PrintVector(ans);

    return 0;
}