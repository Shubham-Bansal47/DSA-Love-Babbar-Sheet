#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n1,n2;
    cin>>n1>>n2;
    vector<int> vec1(n1),vec2(n2),vec;

    for(int i=0; i<n1; i++)
        cin>>vec1[i];

    for(int i=0; i<n2; i++)
        cin>>vec2[i];

    reverse(vec1.begin(),vec1.end());
    reverse(vec2.begin(),vec2.end());

    int carry=0;
    int index1=0,index2=0;
    int sum=0;

    while(index1<n1 || index2<n2 || carry!=0)
    {
        sum=0;
        if(index1<n1)
            sum+=vec1[index1++];
        if(index2<n2)
            sum+=vec2[index2++];

        sum+=carry;
        vec.push_back(sum%10);
        carry=sum/10;
    }

    reverse(vec.begin(),vec.end());

    for(int i=0; i<vec.size(); i++)
        cout<<vec[i]<<" ";

    return 0;
}