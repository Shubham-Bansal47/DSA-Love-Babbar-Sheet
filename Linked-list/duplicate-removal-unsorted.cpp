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


struct List * removeDuplicates(struct List *head) 
{
    struct List *ptr,*ptr1,*ptr2;
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    map<int,int> m;
    ptr=head;
    ptr1=head->next;
    m[ptr->val]++;
    while(ptr1!=NULL)
    {
        m[ptr1->val]++;
        if(m[ptr1->val]>1)
        {
            m[ptr1->val]--;
            ptr->next=ptr1->next;
            ptr1=ptr->next;
        }
        else
        {
            ptr=ptr->next;
            ptr1=ptr->next;
        }
    }
    return head;
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
    int i,j,n,x;
    cin>>n;
    struct List *start, *ptr,*ptr1;
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
    start=removeDuplicates(start);
    display(start);
}
