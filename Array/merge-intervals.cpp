#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int main()
{
    
    FastIO;
    int i,j,n;
    cin>>n;
    int arr[n][2];
    vector<vector<int>> vec;
    for(i=0; i<n; i++)
    {
        cin>>arr[i][0]>>arr[i][1];
        vector<int> v;
        v.push_back(arr[i][0]);
        v.push_back(arr[i][1]);
        vec.push_back(v);
    }
    if(n==1)
    {
        cout<<vec[0][0]<<" "<<vec[0][1];
        return 0;
    }
    sort(vec.begin(),vec.end());
    vector<vector<int>> vec1;
    vector<int> ve=vec[0];
    for(i=1; i<vec.size(); i++)
    {
        if(ve[1]>=vec[i][0] && ve[1]<vec[i][1])
        {
            ve[1]=vec[i][1];
        }
        else if(ve[1]>=vec[i][1])
        {
            continue;
        }
        else
        {
            vec1.push_back(ve);
            ve=vec[i];
        }
    }
    vec1.push_back(ve);
    for(i=0; i<vec1.size(); i++)
    {
        cout<<vec1[i][0]<<" "<<vec1[i][1]<<"\n";
    }
}