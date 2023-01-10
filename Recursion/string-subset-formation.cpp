// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void subset(int i,string s,string str,vector<string>& vec)
{
    if(i>=s.size())
    {
        vec.push_back(str);
        return;
    }
    subset(i+1,s,str,vec);
    subset(i+1,s,str+s[i],vec);
    
    return;
}

int main() {
    // Write C++ code here
    string s;
    cin>>s;
    vector<string> vec;
    string str="";
    int index=0;
    subset(index,s,str,vec);
    for(int i=0; i<vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    
    return 0;
}