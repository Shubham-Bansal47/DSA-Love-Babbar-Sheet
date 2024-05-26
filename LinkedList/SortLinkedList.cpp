#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *next;

        Node(int value)
        {
            this->val=value;
            this->next=NULL;
        }
};

void CreateLinkedList(Node* &start,Node* &last)
{
    int x;
    x=1;
    while(x)
    {
        int val;
        cin>>val;
        Node *tempnode=new Node(val);
        if(start==NULL)
        {
            start=tempnode;
            last=tempnode;
        }
        else
        {
            last->next=tempnode;
            last=last->next;
        }
        cout<<"Do you want to enter more nodes?"<<endl;
        cin>>x;
    }

    return;
}

void SortLinkedList(Node* &start)
{
    vector<int> vec;
    Node *temp=start;
    while(temp!=NULL)
    {
        vec.push_back(temp->val);
        temp=temp->next;
    }
    sort(vec.begin(),vec.end());
    temp=start;
    int x=0;
    while(temp!=NULL)
    {
        temp->val=vec[x++];
        temp=temp->next;
    }

    return;
}

void PrintLinkedList(Node* start)
{
    while(start!=NULL)
    {
        cout<<start->val<<" ";
        start=start->next;
    }

    return;
}

int main()
{
    Node *start,*last;
    start=last=NULL;
    CreateLinkedList(start,last);
    SortLinkedList(start);
    PrintLinkedList(start);

    return 0;
}