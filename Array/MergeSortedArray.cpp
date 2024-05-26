#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1,n2;
    cin>>n1>>n2;

    vector<int> vec1(n1),vec2(n2),result(n1+n2);

    for(int i=0; i<n1; i++)
        cin>>vec1[i];
    
    for(int i=0; i<n2; i++)
        cin>>vec2[i];

    int index1=0,index2=0;
    int sindex=0;
    while(index1<n1 && index2<n2)
    {
        if(vec1[index1]<vec2[index2])
            result[sindex++]=vec1[index1++];
        else if(vec1[index1]>vec2[index2])
            result[sindex++]=vec2[index2++];
        else
        {
            result[sindex++]=vec1[index1++];
            result[sindex++]=vec2[index2++];
        }
    }

    while(index1<n1)
        result[sindex++]=vec1[index1++];
    
    while(index2<n2)
        result[sindex++]=vec2[index2++];

    for(int i=0; i<n1+n2; i++)
        cout<<result[i]<<" ";

    return 0;
}