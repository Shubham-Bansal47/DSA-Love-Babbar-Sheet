#include<bits/stdc++.h>
using namespace std;

/* Insertion Sort -> taking elements one by one and placing them at their correct 
position by shifting previous elements right */

int main()
{
    int n;
    cin>>n; 
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    for(int i=1; i<n; i++)
    {
        int value=vec[i];
        int index=i;
        for(int j=i-1; j>=0; j--)
        {
            if(vec[i]<vec[j])
                index=j;
        }

        for(int j=i-1; j>=index; j--)
            vec[j+1]=vec[j];

        vec[index]=value;
    }

    for(int i=0; i<n; i++)
        cout<<vec[i]<<" ";

    return 0;
}
