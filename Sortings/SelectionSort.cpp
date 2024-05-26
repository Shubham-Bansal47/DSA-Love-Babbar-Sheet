#include<bits/stdc++.h>
using namespace std;

//selection sort -> finding the minimum and placing it then decreasing the size of array 

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    for(int i=0; i<vec.size()-1; i++)
    {
        int index=i;
        int mini=vec[i]; 
        for(int j=i+1; j<vec.size(); j++)
        {
            if(vec[j]<mini)
            {
                mini=vec[j];
                index=j;
            }
        }

        swap(vec[i],vec[index]);
    }

    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";
    
    return 0;
}