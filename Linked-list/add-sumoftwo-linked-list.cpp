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

struct List* addTwoLists(struct List* first, struct List* second)
    {
        struct List *ptr,*ptr1;
        ll x=0,y=0;
        ptr=first;
        ptr1=second;
        while(ptr!=NULL)
        {
            x=x*10+(ptr->val);
            ptr=ptr->next;
        }
        while(ptr1!=NULL)
        {
            y=y*10+(ptr1->val);
            ptr1=ptr1->next;
        }
        x=x+y;
        vector<int> vec;
        while(x>0)
        {
            y=x%10;
            vec.push_back(y);
            x=x/10;
        }
        reverse(vec.begin(),vec.end());
        y=vec.size();
        ptr=NULL;
        x=0;
        while(x<vec.size())
        {
            struct List *ptr2;
            ptr2=(struct List *)malloc(sizeof(struct List));
            ptr2->next=NULL;
            ptr2->val=vec[x];
            if(ptr==NULL)
            {
                ptr=ptr2;
                ptr1=ptr2;
            }
            else
            {
                ptr1->next=ptr2;
                ptr1=ptr1->next;
            }
        ++x;    
        }
        return ptr;
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
    int i,j,n,m,x;
    cin>>n>>m;
    struct List *start,*start1,*ptr,*ptr1;
    start=NULL;
    start1=NULL;
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
    while(m--)
    {
        struct List *newnode,*trav;
        newnode=(struct List*)malloc(sizeof(struct List));
        cin>>newnode->val;
        newnode->next=NULL;
        if(start1==NULL)
        {
            start1=newnode;
            trav=newnode;
        }
        else
        {
            trav->next=newnode;
            trav=trav->next;
        }
    }
    start=addTwoLists(start,start1);
    display(start);
}