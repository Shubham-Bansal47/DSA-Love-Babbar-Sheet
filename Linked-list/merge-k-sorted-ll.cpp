#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
 

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int K)
    {
           Node *ptr,*ptr1;
           int i,j,sum=0;
           ptr=arr[0];
           ptr1=arr[0];
           for(i=0; i<K-1; i++)
           {
                while(ptr1->next!=NULL)
                {
                    ptr1=ptr1->next;
                }
                ptr1->next=arr[i+1];
           }
           vector<int> vec;
           ptr=arr[0];
           while(ptr!=NULL)
           {
               vec.push_back(ptr->data);
               ptr=ptr->next;
           }
           sort(vec.begin(),vec.end());
           ptr=arr[0];
           while(ptr!=NULL)
           {
               ptr->data=vec[sum];
                ++sum;
                ptr=ptr->next;
            }
           return arr[0];
    }
};

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}