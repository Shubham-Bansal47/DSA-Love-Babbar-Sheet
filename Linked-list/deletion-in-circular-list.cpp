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

struct List *deletion(struct List *head,int y)
{
    struct List *ptr,*ptr1;
    ptr=head;
    ptr1=head;
    if(y==1)                // 1 2 3 4
    {
        struct List *ptr2;
        ptr2=ptr->next;
        while(ptr->next!=head)
        {
            ptr=ptr->next;
        }
        ptr->next=ptr2;
        head=ptr2;
        free(ptr1);
        return head;
    }
    else
    {
        struct List *ptr2;
        y-=2;
        while(y--)
        {
            ptr=ptr->next;
        }
        ptr2=ptr->next;
        ptr->next=ptr2->next;
        free(ptr2);
        return head;
    }
}

void display(struct List* head)
{
    struct List *ptr;
    ptr=head;
    do
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }while(ptr!=head);
    cout<<ptr->val;
}

int main()
{
    FastIO;
    int i,j,n,x;
    cin>>n;
    cout<<"Enter node to be deleted\n";
    cin>>x;
    struct List *start, *ptr,*ptr1;
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
            newnode->next=start;
            trav=newnode;
        }
        else
        {
            trav->next=newnode;
            newnode->next=start;
            trav=trav->next;

        }
    }
    start=deletion(start,x);
    display(start);
}