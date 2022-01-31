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

    struct List *reverse(struct List *head)
    {
        struct List *ptr2,*ptr1,*ptr;
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        ptr=NULL;
        ptr1=head;
        while(ptr1!=NULL)               // 1 2 3 4 5
        {
            ptr2=ptr1->next;
            ptr1->next=ptr;
            ptr=ptr1;
            ptr1=ptr2;
        }
        return ptr;
    }
    
    bool isPalindrome(struct List *head)
    {
        struct List *ptr,*ptr1;
        int x=0;
        if(head->next==NULL)
        {
            return true;                 
        }
        ptr=head;
        while(ptr!=NULL)
        {
            ++x;
            ptr=ptr->next;
        }
        ptr=NULL;
        ptr1=head;
        if(x%2!=0)
        {
            int y=x/2;
            while(y--)
            {
                ptr1=ptr1->next;
            }
            ptr=reverse(ptr1);
            y=x/2;
            ptr1=head;
            while(y--)
            {
                if(ptr1->val!=ptr->val)
                {
                    return false;
                }
                ptr=ptr->next;
                ptr1=ptr1->next;
            }
        }
        else
        {
            int y=x/2;         // 1 2 3 1
            while(y--)
            {
                ptr1=ptr1->next;
            }
            ptr=reverse(ptr1);
            y=x/2;
            ptr1=head;
            while(y--)
            {
                if(ptr->val!=ptr1->val)
                {
                    return false;
                }
                if(ptr1->next==NULL)
                {
                    break;
                }
                ptr=ptr->next;
                ptr1=ptr1->next;
            }
        }
        return true;
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
    int x=isPalindrome(start);
    cout<<x;
    // display(start);
}

   
    

