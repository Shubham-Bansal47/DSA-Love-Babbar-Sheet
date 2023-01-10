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
    int i,j,n,x;
    cin>>n;
    struct List *start, *ptr;
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
    map<struct List*,int> m;
    ptr=start;
    m[ptr]++;
    while(x--)
    {
        if(m[ptr->next]>0)
        {
            cout<<"Yes"<<"\n";
            return 0; 
        }
        m[ptr->next]++;
        ptr=ptr->next;
    }
    cout<<"No"<<"\n";
}