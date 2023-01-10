// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void merge(int *arr,int s,int e)
{
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    
    int before[len1];
    int startindex=s;
    
    //creating new arrays before and after
    for(int i=0; i<len1; i++)
    {
        before[i]=arr[startindex++];
    }
    int after[len2];
    startindex=mid+1;
    for(int i=0; i<len2; i++)
    {
        after[i]=arr[startindex++];
    }
    
    startindex=s;
    //merging both the arrays
    int index1=0;
    int index2=0;
    while(index1<len1 && index2<len2)
    {
        if(before[index1]<after[index2])
        {
            arr[startindex++]=before[index1++];
        }
        else
        {
            arr[startindex++]=after[index2++];
        }
    }
    while(index1<len1)
    {
        arr[startindex++]=before[index1++];
    }
    while(index2<len2)
    {
        arr[startindex++]=after[index2++];
    }
        
    
    return;
}

void mergesort(int *arr,int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);
    
    return;
}

int main() {
    // Write C++ code here
    int arr[6]={5,2,4,1,8,3};
    mergesort(arr,0,5);
    for(int i=0; i<6; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}

//
// #include <bits/stdc++.h>
// using namespace std;

// void merge(vector<int>& vec,int start,int end)
// {
//     int mid=start+(end-start)/2;
//     int l1=mid+1-start;
//     int l2=end-mid;
    
//     vector<int> temp1(l1);
//     vector<int> temp2(l2);
//     int count=0;
    
//     for(int i=start; i<=mid; i++){
//         temp1[count++]=vec[i];
//     }
    
//     count=0;
    
//     for(int i=mid+1; i<=end; i++){
//         temp2[count++]=vec[i];
//     }
    
//     int c1=0;
//     int c2=0;
//     count=start;
    
//     while(c1<l1 && c2<l2){
//         if(temp1[c1]<temp2[c2]){
//             vec[start++]=temp1[c1++];
//         }
//         else if(temp2[c2]<temp1[c1]){
//             vec[start++]=temp2[c2++];
//         }
//         else{
//             vec[start++]=temp1[c1++];
//             vec[start++]=temp2[c2++];
//         }
//     }
//     while(c1<l1){
//         vec[start++]=temp1[c1++];
//     }
//     while(c2<l2){
//         vec[start++]=temp2[c2++];
//     }
    
//     return;
// }

// void solve(vector<int>& vec,int s,int e)
// {
//     if(s>=e){
//         return;
//     }
    
//     int mid=s+(e-s)/2;
//     solve(vec,s,mid);
//     solve(vec,mid+1,e);
//     merge(vec,s,e);
    
//     return;
// }

// int main() {
//     int n;
//     cin>>n;
//     vector<int> vec(n);
//     for(int i=0; i<n; i++){
//         cin>>vec[i];
//     }
//     int s,e;
//     s=0;
//     e=n-1;
//     solve(vec,s,e);
//     for(int i=0; i<n; i++){
//         cout<<vec[i]<<" ";
//     }

//     return 0;
// }