#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=40;
    vector<bool> vec(n+3,true);
    vec[0]=false;
    vec[1]=false;
    for(int i=2; i<=n; i++){
        if(vec[i]){
            for(int j=2*i; j<=n; j=j+i)
                vec[j]=false;
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++)
    {
        if(vec[i]) cnt++;
    }
    cout<<cnt;

    return 0;
}