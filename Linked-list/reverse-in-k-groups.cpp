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

struct List *reverse(struct List* head,int k)
{
    struct List *ptr,*ptr1,*ptr2;
    ptr=NULL;
    ptr1=head;
    int x=0;
    while(ptr1!=NULL && x<k)
    {
        ptr2=ptr1->next;             // 1 2 3 4 5 6 
        ptr1->next=ptr;              // 2 1 4 3 6 5
        ptr=ptr1;
        ptr1=ptr2;
        ++x;
    }
    if(ptr2!=NULL)
    {
        head->next=reverse(ptr2,k); // recursion
    }
    return ptr;
}

int main()
{
    FastIO;
    int i,j,n,k,x;
    cin>>n>>k;
    struct List *start, *ptr;
    start=NULL;
    x=n;
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
    start=reverse(start,k);
    ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
}