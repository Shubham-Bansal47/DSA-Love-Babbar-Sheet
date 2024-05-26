#include<bits/stdc++.h>
using namespace std;

vector<int> NextSmallerElement(vector<int> &vec)
{
    stack<int> st;
    st.push(-1);
    vector<int> ans(vec.size());
    for(int i=vec.size()-1; i>=0; i--)
    {
        while(!st.empty() && st.top()>=vec[i])
            st.pop();

        ans[i]=st.top();
        st.push(vec[i]);
    }

    return ans;
}

int main()
{
    int n;
    cout<<"Enter size of vector"<<endl;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    vector<int> ans=NextSmallerElement(vec);
    for(int i=0; i<n; i++)
        cout<<ans[i]<<" ";

    return 0;
}