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
    int i,j,n;
    cin>>n;
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
    if(n==1)
    {
        cout<<start->val;
        return 0;
    }
    ptr=start;
    ptr1=ptr->next;
    while(ptr1!=NULL)
    {
        struct List *x1,*x2;
        x1=ptr1;
        x2=ptr1->next;
        ptr1->next=ptr;
        ptr=x1;
        ptr1=x2;
    }
    start->next=NULL;
    start=ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
}