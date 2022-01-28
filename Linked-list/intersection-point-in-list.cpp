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

int intersectPoint(struct List* head1, struct List* head2)
{
    int y=-1;
    struct List *ptr,*ptr1;
    unordered_map<struct List*,int> m;
    ptr=head1;
    while(ptr!=NULL)
    {
        m[ptr]++;
        ptr=ptr->next;
    }
    ptr1=head2;
    while(ptr1!=NULL)
    {
        if(m[ptr1])
        {
            y=ptr1->val;
            break;
        }
        else
        {
            ptr1=ptr1->next;
        }
    }
    return y;
}

void display(struct List* head)
{
    struct List *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
}

int main()
{
    FastIO;
    int i,j,n,m;
    cin>>n>>m;
    struct List *start,*start1,*ptr,*ptr1;
    start=NULL;
    start1=NULL;
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
    while(m--)
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
    int x=intersectPoint(start,start1);
    // display(start);
    cout<<x;
    return 0;
}

   
    

