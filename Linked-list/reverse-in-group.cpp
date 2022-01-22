#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

struct List
{
    int val;
    struct List* next;
};

int main()
{
    FastIO;
    int i,j,n,k;
    cin>>n>>k;
    struct List *start,*ptr,*ptr1;
    start=NULL;
    while(n--)
    {
        struct List *newnode,*trav;
        newnode=(struct List*)malloc(sizeof(struct List));
        cin>>newnode->val;
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
            trav=newnode;
        }
        else
        {
            trav->next=newnode;
            trav=trav->next;
        }
    }
    vector<struct List*> vec;
    ptr=start;
    while(ptr!=NULL)
    {
        vec.push_back(ptr);
        ptr=ptr->next;
    }
    if(n==1)
    {
        cout<<start->val;
        return 0;
    }
    int x;
    x=n;
    if(n%k==0)
    {
        ptr=start;
        ptr1=ptr->next;
        struct List *x1,*x2;
        i=n/k;
        while(i--)
        {
            for(j=0; j<k-1; j++)
            {
                if(i==1 && j==0)
                {
                    ptr->next=NULL;   
                }
                x1=ptr1;
                x2=ptr1->next;
                ptr1->next=ptr;
                ptr=x1;
                ptr1=x2;
                if(i==n/k && j==k-2)
                {
                    start=ptr;
                }
            }
            ptr=x2;
            ptr1=x2->next;
        }   
    }
    int y;
    j=0;
    y=2*k-1;
    for(i=0; i<(n/k)-1; i++)
    {
        vec[j]->next=vec[y];
        j=j+k;
        y=y+k;
    }
    ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
}