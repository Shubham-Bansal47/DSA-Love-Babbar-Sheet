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

struct List* findIntersection(struct List* head1, struct List* head2)
{
    struct List *ptr,*ptr1;
    unordered_map<int,int> m;
    unordered_map<int,int> m1;
    ptr=head1;
    ptr1=head2;
    while(ptr!=NULL)
    {
        m[ptr->val]++;
        ptr=ptr->next;
    }
    while(ptr1!=NULL)
    {
        m1[ptr1->val]++;
        ptr1=ptr1->next;
    }
    struct List *tr,*start;
    start=NULL;
    ptr=head1;
    while(ptr!=NULL)
    {
        int y=min(m[ptr->val],m1[ptr->val]);
        if(y==0)
        {
            ptr=ptr->next;
            continue;
        }
        else
        {
            struct List *newnode;
            newnode=(struct List *)malloc(sizeof(struct List));
            newnode->val=ptr->val;
            newnode->next=NULL;
            if(start==NULL)
            {
                start=newnode;
                tr=newnode;
            }
            else
            {
                tr->next=newnode;
                tr=tr->next;
            }
            m[ptr->val]--;
            m1[ptr->val]--;
        }
        ptr=ptr->next;
    }
    return start;
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
    while(n--)
    {
        struct List *newnode;
        newnode=(struct List*)malloc(sizeof(struct List));
        cin>>newnode->val;
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
            ptr=newnode;
        }
        else
        {
            ptr->next=newnode;
            ptr=ptr->next;
        }
    }
    start1=NULL;
    while(m--)
    {
        struct List *newnode;
        newnode=(struct List*)malloc(sizeof(struct List));
        cin>>newnode->val;
        newnode->next=NULL;
        if(start1==NULL)
        {
            start1=newnode;
            ptr1=newnode;
        }
        else
        {
            ptr1->next=newnode;
            ptr1=ptr1->next;
        }
    }
    start=findIntersection(start,start1);
    display(start);
}

   
    

