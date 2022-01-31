#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int pivot(vector<int>& nums)
    {
        int l=0,h=nums.size()-1;
        while(l<h)
        {
            int m=(l+h)/2;
            if(nums[0]<=nums[m])
            {
                l=m+1;
            }
            else
            {
                h=m;
            }
        }
        return l;
    }
    int search(vector<int>& nums, int target) {
        int x=-1;
        int l=0,h=nums.size()-1;
        int pi=pivot(nums);
        if(nums[pi]<=target && target<=nums[h])
        {
            l=pi;
            while(l<=h)
            {
                int m=(l+h)/2;
                if(nums[m]>target)
                {
                    h=m-1;
                }
                else if(nums[m]<target)
                {
                    l=m+1;
                }
                else
                {
                    x=m;
                    break;
                }
            }
        }
        else
        {
            h=pi-1;
            while(l<=h)
            {
                int m=(l+h)/2;
                if(nums[m]>target)
                {
                    h=m-1;
                }
                else if(nums[m]<target)
                {
                    l=m+1;
                }
                else
                {
                    x=m;
                    break;
                }
            }
        }
        return x;
        
    }

int main()
{
    
    FastIO;
    int i,j,n,x;
    vector<int> nums;
    cin>>n>>x;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
        nums.push_back(arr[i]);
    }
    j=search(nums,x);
    cout<<j;
}