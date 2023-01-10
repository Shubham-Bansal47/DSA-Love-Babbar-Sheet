//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        priority_queue<int> head,drop; 
        vector<int> ans;
        for(int i=0; i<k; i++)
        {
            head.push(arr[i]);
        }
        ans.push_back(head.top());
        for(int i=k; i<n; i++)
        {
            if(arr[i-k]==head.top())
            {
                head.pop();
            }
            else
            {
                drop.push(arr[i-k]);
            }
            while(!drop.empty() && head.top()==drop.top())
            {
                head.pop();
                drop.pop();
            }
            head.push(arr[i]);
            ans.push_back(head.top());
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends