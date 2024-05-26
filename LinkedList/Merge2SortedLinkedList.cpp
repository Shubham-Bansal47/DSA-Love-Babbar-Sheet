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
    int x=1;
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

Node* MergeLinkedList(Node* &start1,Node* &start2)
{
    Node* temp1=start1;
    Node* temp2=start2;
    Node *newstart,*newend;
    newstart=newend=NULL;
    vector<int> vec;
    while(temp1!=NULL)
    {
        vec.push_back(temp1->val);
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        vec.push_back(temp2->val);
        temp2=temp2->next;
    }
    sort(vec.begin(),vec.end());
    int x=0;
    while(x<vec.size())
    {
        if(newstart==NULL)
        {
            Node* tempnode=new Node(vec[x++]);
            newstart=tempnode;
            newend=tempnode;
        }
        else
        {
            Node* tempnode=new Node(vec[x++]);
            newend->next=tempnode;
            newend=newend->next;
        }
    }

    return newstart;
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
    Node *start1,*last1,*start2,*last2;
    start1=last1=start2=last2=NULL;
    CreateLinkedList(start1,last1);
    CreateLinkedList(start2,last2);
    Node *merged=MergeLinkedList(start1,start2);
    PrintLinkedList(merged);

    return 0;
}