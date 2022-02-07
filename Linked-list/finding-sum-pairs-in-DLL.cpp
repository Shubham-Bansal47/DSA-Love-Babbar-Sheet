#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

struct List
{
    struct List* prev;
    int val;
    struct List* next;
};

void displayfront(struct List *head)
{
    struct List *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    return;
}

void displayback(struct List *head)
{
    struct List *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->prev;
    }
    return;
}

int main()
{
    FastIO;
    int i,j,n,k;
    cin>>n>>k;
    struct List *start,*trav,*ptr,*ptr1;
    start=NULL;
    trav=NULL;
    while(n--)
    {
        struct List *newnode;
        newnode=(struct List*)malloc(sizeof(struct List));
        cin>>newnode->val;
        newnode->prev=NULL;
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
            trav=newnode;
        }
        else
        {
            trav->next=newnode;
            newnode->prev=trav;
            trav=trav->next;
        }
    }
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr1=ptr;
    ptr=start;
    i=ptr->val;
    j=ptr1->val;
    vector<pair<int,int>> vec;
    while(i!=j)
    {
        if(i+j>k)
        {
            ptr1=ptr1->prev;
            j=ptr1->val;
        }
        else if(i+j<k)
        {
            ptr=ptr->next;
            i=ptr->val;
        }
        else
        {
            vec.push_back({i,j});
            ptr1=ptr1->prev;
            ptr=ptr->next;
            i=ptr->val;
            j=ptr1->val;
        }
    }
    for(i=0; i<vec.size(); i++)
    {
        cout<<vec[i].first<<" "<<vec[i].second<<"  ";
    }
}

   
    

