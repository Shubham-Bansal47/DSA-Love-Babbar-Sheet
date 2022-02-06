#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

struct node 
{
    int data;
    struct node *next;
};

struct node *create(struct node *start)
{
    struct node *traverse,*newnode;
    int x;
    do
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->next=NULL;
        cout<<"Enter data in the newnode\n";
        cin>>newnode->data;
        if(start==NULL)
        {
            start=newnode;
            traverse=newnode;
        }
        else
        {
            traverse->next=newnode;
            traverse=traverse->next;
        }
        cout<<"Do you want to create more nodes\n";
        cin>>x;
    }while(x!=0);

    return start;
}

struct node *pop(struct node *start)
{
    struct node *traverse;
    traverse=start;
    if(start==NULL)
    {
        cout<<"Queue is empty cannot pop item--!!\n";
        return start;
    }
    start=start->next;
    free(traverse);
    
    return start;
}

struct node *push(struct node *start)
{
    struct node *traverse,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    cout<<"Enter value in the newnode\n";
    cin>>newnode->data;
    traverse=start;
    while(traverse->next!=NULL)
    {
        traverse=traverse->next;
    }
    if(start==NULL)
    {
        start=newnode;
        return start;
    }
    else
    {
        traverse->next=newnode;
        return start;
    }
}

void print(struct node *start)
{
    struct node *traverse;
    traverse=start;
    while(traverse!=NULL)
    {
        cout<<traverse->data<<" ";
        traverse=traverse->next;
    }
}
int main()
{
    struct node *start;
    start=NULL;
    int x;
    do
    {
        cout<<"\nMain--Menu\n";
        cout<<"Press 1 to create the stack\n";
        cout<<"Press 2 for popping item\n";
        cout<<"Press 3 for pushing an item\n";
        cout<<"Press 4 for printing\n";
        cout<<"Press 5 to exit the program\n";
        cin>>x;
        switch(x)
        {
            case 1: start=create(start);
                    break;

            case 2: start=pop(start);
                    break;

            case 3: start=push(start);
                    break;

            case 4: print(start);
                    break;
        }
    }while(x!=5);

    return 0;
}