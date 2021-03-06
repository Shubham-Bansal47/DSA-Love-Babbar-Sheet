// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        vector<int> vec;
        int count=0,up=0,down=r-1,left=0,right=c-1;
        while(up<=down && left<=right)
        {
            if(count==0)
            {
                for(int i=left; i<=right; i++)
                {
                    vec.push_back(matrix[up][i]);
                }
                ++up;
                ++count;
            }
            else if(count==1)
            {
                for(int i=up; i<=down; i++)
                {
                    vec.push_back(matrix[i][right]);
                }
                --right;
                ++count;
            }
            else if(count==2)
            {
                for(int i=right; i>=left; i--)
                {
                    vec.push_back(matrix[down][i]);
                }
                --down;
                ++count;
            }
            else 
            {
                for(int i=down; i>=up; i--)
                {
                    vec.push_back(matrix[i][left]);
                }
                ++left;
                count=0;
            }
        }
        return vec;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends