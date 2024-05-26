#include<bits/stdc++.h>
using namespace std;

int LargestRectangularHistogram(vector<int> &vec)
{
    vector<int> left(vec.size());
    vector<int> right(vec.size());
    stack<int> st;
    st.push(vec.size());
    for(int i=vec.size()-1; i>=0; i--)
    {
        while(st.top()!=vec.size() && vec[st.top()]>vec[i])
            st.pop();

        right[i]=st.top();
        st.push(i);
    }

    while(!st.empty())
        st.pop();

    st.push(-1);

    for(int i=0; i<vec.size(); i++)
    {
        while(st.top()!=-1 && vec[st.top()]>vec[i])
            st.pop();

        left[i]=st.top();
        st.push(i);
    }
    
    int maxi=-1;
    for(int i=0; i<vec.size(); i++)
    {
        int width=right[i]-left[i]-1;
        int temparea=width*vec[i];
        maxi=max(maxi,temparea);
    }

    return maxi;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    int ans=LargestRectangularHistogram(vec);
    cout<<ans;

    return 0;
}