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

struct List* middleNode(struct List* head) 
{
        int i,j,count=0;
        struct List *ptr;
        ptr=head;
        while(ptr!=NULL)
        {
            ptr=ptr->next;
            ++count;
        }
        if(count%2!=0)
        {
            ptr=head;
            for(i=0; i<count/2; i++)
            {
                ptr=ptr->next;
            }
        }
        else
        {
            ptr=head;
            for(i=0; i<count/2; i++)
            {
                ptr=ptr->next;
            }
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
    int i,j,n;
    cin>>n;
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
            trav=newnode;
        }
        else
        {
            trav->next=newnode;
            trav=trav->next;
        }
    }
    start=middleNode(start);
    display(start);
}

   
    

