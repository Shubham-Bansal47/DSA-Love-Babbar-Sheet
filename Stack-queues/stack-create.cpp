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
    int x=1;
    while(x)
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
        cin>>x; // press 1 to continue otherwise 0
    }

    return start;
}

struct node *pop(struct node *start)
{
    struct node *traverse,*traverse1;
    traverse=start;
    traverse1=start;
    if(start==NULL)
    {
        cout<<"Stack is Empty--!!\n";
        return start;
    }
    if(traverse->next==NULL)
    {
        start=NULL;
        free(traverse);
        return start;
    }
    while((traverse->next)->next!=NULL)
    {
        traverse=traverse->next;
    }
    while(traverse1->next!=NULL)
    {
        traverse1=traverse1->next;
    }
    traverse->next=NULL;
    free(traverse1);

    return start;
}

struct node *push(struct node *start)
{
    struct node *traverse,*newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    cout<<"Enter value in newnode\n";
    cin>>newnode->data;
    if(start==NULL)
    {
        start=newnode;
        return start;
    }
    else
    {
        traverse=start;
        while(traverse->next!=NULL)
        {
            traverse=traverse->next;
        }
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
    return;
}

int main()
{
    struct node *start;
    start=NULL;
    int x;
    do
    {
        cout<<"\nMain--Menu\n";
        cout<<"Press 1 to create a stack\n";
        cout<<"Press 2 to pop data from stack\n";
        cout<<"Press 3 to push data into stack\n";
        cout<<"Press 4 to print the stack\n";
        cout<<"Press 5 to exit the code\n";
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