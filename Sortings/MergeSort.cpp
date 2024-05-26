#include<bits/stdc++.h>
using namespace std;

// Merge Sort -> Breaking arrays into half until they become single entity and then sorting them recursively

void MergeEntire(vector<int>& vec,int start,int end)
{
    int mid=start+((end-start)/2);
    int size1=mid-start+1;
    int size2=end-mid;
    int *arr1=new int(size1);
    int *arr2=new int(size2);

    int index=0;
    for(int i=start; i<start+size1; i++)
        arr1[index++]=vec[i];

    index=0;
    for(int i=mid+1; i<mid+1+size2; i++)
        arr2[index++]=vec[i];

    int sindex=start;
    int index1=0;
    int index2=0;
    while(index1<size1 && index2<size2)
    {
        if(arr1[index1]<arr2[index2])
            vec[sindex++]=arr1[index1++];
        else if(arr1[index1]>arr2[index2])
            vec[sindex++]=arr2[index2++];
        else
        {
            vec[sindex++]=arr1[index1++];
            vec[sindex++]=arr2[index2++];
        }
    }

    while(index1<size1)
        vec[sindex++]=arr1[index1++];
    
    while(index2<size2)
        vec[sindex++]=arr2[index2++];

    delete []arr1;
    delete []arr2;

    return;
}

void Merge(vector<int> &vec,int start,int end)
{
    if(start>=end)
        return;

    int mid=start+((end-start)/2);

    Merge(vec,start,mid);
    Merge(vec,mid+1,end);
    MergeEntire(vec,start,end);

    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    Merge(vec,0,n-1);

    for(int i=0; i<n; i++)
        cout<<vec[i]<<" ";

    return 0;
}