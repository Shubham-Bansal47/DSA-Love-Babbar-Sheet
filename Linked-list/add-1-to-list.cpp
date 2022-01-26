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

struct List* reverse(struct List *head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    struct List *tr,*tr1;
    tr=NULL;
    tr1=head;
    while(tr1!=NULL)
    {
        struct List *tr2;
        tr2=tr1->next;
        tr1->next=tr;
        tr=tr1;
        tr1=tr2;
    }
    return tr;
}
    
struct List* addOne(struct List *head) 
{
    struct List *ptr,*ptr1;
    int flag=0;
    ptr=reverse(head);
    ptr1=ptr;
    while(ptr1!=NULL)
    {
        if(ptr1->val==9 && ptr1->next!=NULL)
        {
            ptr1->val=0;
            ptr1=ptr1->next;
        }
        else if(ptr1->val==9 && ptr1->next!=NULL)
        {
            ptr1->val=1;
            struct List *newnode;
            newnode=(struct List *)malloc(sizeof(struct List));
            newnode->val=0;
            newnode->next==ptr;
            ptr=newnode;
            break;
        }
        else
        {
            (ptr1->val)+=1;
            break;
        }
    }
    ptr=reverse(ptr);
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
    start=addOne(start);
    display(start);
}

   
    

