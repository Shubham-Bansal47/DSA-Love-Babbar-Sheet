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
    int i,j,k,n,t,x;
    cin>>n>>t;
    x=n;
    struct List *start,*trav,*ptr,*ptr1,*ptr2;
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
    trav=ptr;
    ptr=start;
    vector<pair<int,pair<int,int>>> vec;
    for(int y=0; y<x-2; y++)
    {
        i=ptr->val;
        ptr1=ptr->next;
        j=ptr1->val;
        ptr2=trav;
        k=ptr2->val;
        while(j<k)
        {
            if(j+k+i>t)
            {
                ptr2=ptr2->prev;
                k=ptr2->val;
            }
            else if(j+k+i<t)
            {
                ptr1=ptr1->next;
                j=ptr1->val;
            }
            else
            {
                vec.push_back({i,{j,k}});
                ptr1=ptr1->next;
                ptr2=ptr2->prev;
                j=ptr1->val;
                k=ptr2->val;
            }
        }
        ptr=ptr->next;
    }
    for(i=0; i<vec.size(); i++)
    {
        cout<<vec[i].first<<" "<<vec[i].second.first<<" "<<vec[i].second.second<<"  ";
    }

    return 0;
}

   
    

