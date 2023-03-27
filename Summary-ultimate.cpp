#include<bits/stdc++.h> //god directory
using namespace std;
//header file
/* 
#include<iostream>
#include<queue>
#include<stack>
#include<map> 
#include<unordered_map>
#include<set>
*/

//macros
/*
#define pi 3.14
*/

//data types
/* 
int 4 byte = 32 bit
char 1 byte = 8 bit
bool 1 bit
float 8 byte
double 8 byte
*/

//typecasting
/*
int x='a';
cout<<x; gives 97 as output (ascii table output)

char ch=97;
cout<<ch; gives a as output
*/

//division game
/*
int/int = int
double/int = double
float/int = float
*/

// Loops
/*
for(int a=0, b=1; a<n && b<=n; a++,b++) syntax for double parameters
*/

//Patterns
//ternary operator 
/*
bool check=true;
int name;
name=check ? 5 : 0; (syntax)
*/

//bitwise operators
/*
not operator = ~
xor = ^
and = &
or = |
left shift 5<<1  ->before 000101 after 001010 
right shift 5>>1  ->before 000101 after 000010 
*/
int factorial(int n)
{
    if(n==1 || n==0)
        return 1;

    return factorial(n-1)*n;
}

int power(int n)
{
    if(n==0)
        return 1;

    return power(n-1)*2;
}

int fibonacci(int n)
{
    if(n<0)
        return 0;
    if(n==1 || n==0)
        return n;

    return fibonacci(n-1)+fibonacci(n-2);
}

bool sorted(int arr[],int size)
{
    if(size==0)
        return true;

    if(arr[size]<arr[size-1])
        return false;
    
    return sorted(arr,size-1);
}

bool linearsearch(int arr[],int size,int target)
{
    if(size<0)
        return false;

    if(target==arr[size])
        return true;

    return linearsearch(arr,size-1,target);
}

bool binarysearch(int arr[],int s,int e,int target)
{
    if(s>e)
        return false;
    
    int mid=s+(e-s)/2;
    if(target==arr[mid])
        return true;
    int left=binarysearch(arr,s,mid-1,target);
    int right=binarysearch(arr,mid+1,e,target);

    return left||right;
}

void reverseusingrec(string& str,int s,int e)
{
    if(s>e)
        return;
    swap(str[s],str[e]);
    reverseusingrec(str,s+1,e-1);
    return;
}

bool CheckPalindromeUsingrecursion(string& str,int s,int e)
{
    if(s>e)
        return true;
    if(str[s]!=str[e])
        return false;
    
    return CheckPalindromeUsingrecursion(str,s+1,e-1);
}

int getpower(int a,int b)
{
    if(b==0)
        return 1;

    return a*getpower(a,b-1);
}

void merge(int arr[],int s,int e)
{
    int mid=s+(e-s)/2;
    int leftlength=mid-s+1;
    int rightlength=e-mid;
    int *leftarr=new int[leftlength];
    int *rightarr=new int[rightlength];
    int startindex=s;
    for(int i=0; i<leftlength; i++)
        leftarr[i]=arr[startindex++];

    for(int i=leftlength; i<leftlength+rightlength; i++)
        rightarr[i-leftlength]=arr[startindex++];

    startindex=s;
    int ls,rs;
    ls=0;
    rs=0;
    while(ls<leftlength && rs<rightlength)
    {
        if(leftarr[ls]<rightarr[rs])
            arr[startindex++]=leftarr[ls++];
        else if(leftarr[ls]>rightarr[rs])
            arr[startindex++]=rightarr[rs++];
        else
        {
            arr[startindex++]=leftarr[ls++];
            arr[startindex++]=rightarr[rs++];
        }
    }
    while(ls<leftlength)
        arr[startindex++]=leftarr[ls++];
    while(rs<rightlength)
        arr[startindex++]=rightarr[rs++];

    delete []leftarr;
    delete []rightarr;
    
    return;
}

void mergesort(int arr[],int s,int e)
{
    if(s>=e)
        return;
    int mid=s+(e-s)/2;
    mergesort(arr,s,mid);
    mergesort(arr,mid+1,e);
    merge(arr,s,e);

    return;
}

void powerset(int arr[],int s,int n,vector<vector<int>>& ans,vector<int> vec)
{
    if(s==n)
    {
        ans.push_back(vec);
        return;
    }
    powerset(arr,s+1,n,ans,vec);
    vec.push_back(arr[s]);
    powerset(arr,s+1,n,ans,vec);
    return;
}  

void subsequenceofstring(string& str,string temp,vector<string>& ans,int i)
{
    if(i==str.size())
    {
        ans.push_back(temp);
        return;
    }

    subsequenceofstring(str,temp,ans,i+1);
    subsequenceofstring(str,temp+str[i],ans,i+1);

    return;
}

void permutationsofstring(string& str,vector<string>& ans,int i)
{
    if(i==str.size())
    {
        ans.push_back(str);
        return;
    }

    for(int j=i; j<str.size(); j++)
    {
        swap(str[j],str[i]);
        permutationsofstring(str,ans,i+1);
        swap(str[j],str[i]);
    }

    return;
}

void ratinamaze(vector<vector<int>>& vec,vector<vector<int>>& vis,vector<string>& ans,string temp,int i,int j)
{
    if(i==vec.size()-1 && j==vec.size()-1 && vec[i][j]==1)
    {
        ans.push_back(temp);
        return;
    }
    if(i<0 || i>=vec.size() || j<0 || j>=vec.size())
        return;
    if(vec[i][j]==0)
        return;
    if(vis[i][j]==1)
        return;

    vis[i][j]=1;

    ratinamaze(vec,vis,ans,temp+'R',i,j+1);
    ratinamaze(vec,vis,ans,temp+'D',i+1,j);
    ratinamaze(vec,vis,ans,temp+'L',i,j-1);
    ratinamaze(vec,vis,ans,temp+'U',i-1,j);

    vis[i][j]=0;
    return;
}

bool checking(int count1[],int count2[])
{
    for(int i=0; i<26; i++)
    {
        if(count1[i]!=count2[i])
            return false;
    }
    return true;
}

void Printarray(int arr[],int n) //if(you put n=1 then default value will start from 1 if not initialised)
{
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    return;
}

void Printvector(vector<int> &temp)
{
    for(int i=0; i<temp.size(); i++)
        cout<<temp[i]<<" ";

    return;
}

void Print2Dvector(vector<vector<int>>& ans)
{
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        
        cout<<endl;
    }

    return;
}

void Printstrings(vector<string>& ans)
{
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
        cout<<endl;
    }
    return;
}

class Hero {
    //properties 
    private:
    int health;
    public:

    Hero()
    {
        cout<<"Default constructor"<<endl; //constructor made 
    }
    int age;
    void gethealth()
    {
        cout<<this->health<<endl;
    }
    void sethealth(int health)
    {
        this->health=health;
    }
};

class Male: public Hero { //inherited hero class in Male class public 
    public:
    string str;
    
    void sleep()
    {
        cout<<"Male sleeping"<<endl;
    }
};

class A {
    int image;
    float respect;
};

class multiple: public Hero,A{ // example of multiple inheritance
    public: 
    float weight;

    void bark()
    {
        cout<<"Barking"<<endl;
    }
};

struct Node{
    int data;
    struct Node *next;

    Node(int val)
    {
        this->data=val;
        this->next=NULL;
    }
};

struct NodeDLL{
    struct NodeDLL *prev;
    int data;
    struct NodeDLL *next;

    NodeDLL(int val)
    {
        this->prev=NULL;
        this->next=NULL;
        this->data=val;
    }
};

struct NodeBT{
    NodeBT *left;
    int data;
    NodeBT *right;

    NodeBT(int val)
    {
        this->data=val;
        left=NULL;
        right=NULL;
    }
};

void creationLL(Node* &start,Node* &last)
{
    int x=1;
    while(x)
    {
        cout<<"Enter value in Node"<<endl;
        int val;
        cin>>val;
        Node* newNode=new Node(val);
        if(start==NULL)
        {
            start=newNode;
            last=newNode;
        }
        else
        {
            last->next=newNode;
            last=last->next;
        }
        cout<<"Do you want to add more Nodes"<<endl;
        cin>>x;
    }
    return;
}

void creationCLL(Node* &start,Node* &last)
{
    int x=1;
    while(x)
    {
        cout<<"Enter data in Node"<<endl;
        int val;
        cin>>val;
        Node* newNode=new Node(val);
        if(start==NULL)
        {
            start=newNode;
            last=newNode;
            last->next=start;
        }
        else
        {
            last->next=newNode;
            last=last->next;
            last->next=start;
        }
        cout<<"Do you want to add more Nodes"<<endl;
        cin>>x;
    }
    return;
}

void creationDLL(NodeDLL* &start,NodeDLL* &last)
{
    int x=1;
    while(x)
    {
        int val;
        cout<<"Enter data in the Node"<<endl;
        cin>>val;
        NodeDLL* newNode=new NodeDLL(val);
        if(start==NULL)
        {
            start=newNode;
            last=newNode;
        }
        else
        {
            last->next=newNode;
            newNode->prev=last;
            last=last->next;
        }
        cout<<"Do you want to add more Nodes"<<endl;
        cin>>x;
    }
    return;
}

void creationDCLL(NodeDLL* &start,NodeDLL* &last)
{
    int x=1;
    while(x)
    {
        int val;
        cout<<"Enter data in the Node"<<endl;
        cin>>val;
        NodeDLL* newNode=new NodeDLL(val);
        if(start==NULL)
        {
            start=newNode;
            last=newNode;
            newNode->next=start;
            newNode->prev=last;
        }
        else
        {
            last->next=newNode;
            newNode->prev=last;
            last=last->next;
            last->next=start;
            start->prev=last;
        }
        cout<<"Do you want to enter more Nodes"<<endl;
        cin>>x;
    }
    return;
}

Node* reverseLL(Node* start)
{
    if(start==NULL || start->next==NULL)
        return start;

    Node *temp,*temp1;
    temp=NULL;
    temp1=start;
    while(temp1!=NULL)
    {
        Node *extra;
        extra=temp1->next;
        temp1->next=temp;
        temp=temp1;
        temp1=extra;
    }
    return temp;
}

void middleofLL(Node* temp)
{
    if(temp==NULL)
    {
        cout<<"list incomplete"<<endl;
        return;
    }     
    Node *slow,*fast;
    slow=temp;
    fast=temp;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=(fast->next)->next;
    }
    cout<<"middle element is: "<<slow->data<<endl;
    return;
}

Node* reverseingroups(Node* start,int k)
{
    int t=k;
    if(start==NULL || start->next==NULL)
        return start;

    Node *temp,*temp1;
    temp=NULL;
    temp1=start;
    while(temp1!=NULL && k!=0)
    {
        Node *extra=temp1->next;
        temp1->next=temp;
        temp=temp1;
        temp1=extra;
        k--;
    }
    if(temp1!=NULL)
        start->next=reverseingroups(temp1,t);

    return temp;
}

void circularLLcheck(Node* start)
{
    Node *slow,*fast;
    slow=start;
    fast=start;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=(fast->next)->next;
        if(slow==fast)
        {
            cout<<"Linked list is circular"<<endl;
            return;
        }
    }
    cout<<"Linked list is not circular"<<endl;
    return;
}

void removeloop(Node* &head)
{
    if(head==NULL)
    return;
    int check=0;
    Node *slow,*fast;
    slow=head;
    fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=(fast->next)->next;
        if(slow==fast)
        {
            check=1;
            break;
        }
    }
    if(check==0)
        return;
    if(slow==head)
    {
        do
        {
            slow=slow->next;
        }while(slow->next!=head);
        slow->next=NULL;
        return;
    }
    slow=head;
    while(slow->next!=fast->next)
    {
        slow=slow->next;
        fast=fast->next;
    }
    fast->next=NULL;
        return;
}

void removeduplicatessorted(Node* head)
{
    if(head==NULL || head->next==NULL)
        return;

    Node *temp,*temp1;
    temp=head;
    temp1=head->next;
    while(temp1!=NULL)
    {
        if(temp1->data==temp->data)
        {
            temp->next=temp1->next;
            delete(temp1);
            temp1=temp->next;
        }
        else
        {
            temp=temp->next;
            temp1=temp1->next;
        }
    }
    return;
}

void removeduplicateunsorted(Node* head,unordered_map<int,int>& m)
{
    if(head==NULL || head->next==NULL)
        return;

    Node *temp,*temp1;
    temp=head;
    m[temp->data]++;
    temp1=head->next;
    while(temp1!=NULL)
    {
        if(m[temp1->data]>=1)
        {
            temp->next=temp1->next;
            delete(temp1);
            temp1=temp->next;
        }
        else
        {
            m[temp1->data]++;
            temp=temp->next;
            temp1=temp1->next;
        }
    }
    return;
}

void sortLL(Node* &start)
{
    if(start==NULL || start->next==NULL)
        return;

    map<int,int> m;
    Node *temp;
    temp=start;
    while(temp!=NULL)
    {
        m[temp->data]++;
        temp=temp->next;
    }
    temp=start;
    for(auto i:m)
    {
        int count=0;
        count=i.second;
        while(count--)
        {
            temp->data=i.first;
            temp=temp->next;
        }
    }

    return;
}

void merge2LL(Node* start1,Node* start2,Node* &ans,Node* &merger)
{
    if(start1==NULL)
    {
        ans=start2;
        return;
    }
    if(start2==NULL)
    {
        ans=start1;
        return;
    }
    Node *temp1,*temp2;
    temp1=start1;
    temp2=start2;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data<temp2->data)
        {
            Node *newNode=new Node(temp1->data);
            if(ans==NULL)
            {
                ans=newNode;
                merger=newNode;
            }
            else
            {
                merger->next=newNode;
                merger=merger->next;
            }
            temp1=temp1->next;
        }
        else if(temp1->data>temp2->data)
        {
            Node* newNode=new Node(temp2->data);
            if(ans==NULL)
            {
                ans=newNode;
                merger=newNode;
            }
            else
            {
                merger->next=newNode;
                merger=merger->next;
            }
            temp2=temp2->next;
        }
        else 
        {
            Node* newNode=new Node(temp1->data);
            Node* newNode1=new Node(temp2->data);
            if(ans==NULL)
            {
                ans=newNode;
                merger=newNode;
                merger->next=newNode1;
                merger=merger->next;
            }
            else
            {
                merger->next=newNode;
                merger=merger->next;
                merger->next=newNode1;
                merger=merger->next;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL)
    {
        Node* newNode=new Node(temp1->data);
        merger->next=newNode;
        merger=merger->next;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        Node* newNode=new Node(temp2->data);
        merger->next=newNode;
        merger=merger->next;
        temp2=temp2->next;
    }
    return;
}
// 1 2 3 4 5 
void CheckLLPalindrome(Node* head)
{
    if(head==NULL || head->next==NULL)
        return;

    Node *slow,*fast;
    slow=head;
    fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=(fast->next)->next;
    } 
    Node *reversed=reverseLL(slow->next);
    slow->next=NULL;
    slow=head;
    while(reversed!=NULL)
    {
        if(slow->data!=reversed->data)
        {
            cout<<"Not a palindrome"<<endl;
            return;
        }
        reversed=reversed->next;
        slow=slow->next;
    }
    cout<<"It is a palindrome"<<endl;

    return;
}

void Add2LL(Node *start1,Node *start2,Node* &ans)
{
    Node *temp1,*temp2,*merge;
    temp1=start1;
    temp2=start2;
    merge=NULL;
    temp1=reverseLL(start1);
    temp2=reverseLL(start2);
    int carry=0;
    while(temp1!=NULL || temp2!=NULL || carry!=0)
    {
        int sum=0;
        if(temp1!=NULL)
        {
            sum+=temp1->data;
            temp1=temp1->next;
        }
        if(temp2!=NULL)
        {
            sum+=temp2->data;
            temp2=temp2->next;
        }
        sum+=carry;
        if(ans==NULL)
        {
            Node *newNode=new Node(sum%10);
            ans=newNode;
            merge=newNode;
        }
        else
        {
            Node *newNode=new Node(sum%10);
            merge->next=newNode;
            merge=merge->next;
        }
        carry=sum/10;
    }
    return;
}

class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        this->size=size;
        arr=new int[size];
        this->top=-1;
    }

    void push(int element)
    {
        if(size-top>1)
        {
            top++;
            arr[top]=element;
        }
        else
            cout<<"Stack is full"<<endl;
    }

    void pop()
    {
        if(top>=0)
            top--;
        else
            cout<<"Stack is empty"<<endl;
    }

    int peek()
    {
        if(top>=0 && top<size)
            return arr[top];
        else
            cout<<"Stack is empty"<<endl;

        return -1;
    }

    bool isempty()
    {
        if(top==-1)
            return true;
        else
            return false;
    }
};

string ReverseStringUsingStack(string &str)
{
    stack<char> st;
    for(int i=0; i<str.size(); i++)
        st.push(str[i]);
    
    int i=0;
    while(!st.empty())
    {
        str[i]=st.top();
        st.pop();
        i++;
    }
    return str;
}
// ({()})
bool ValidParenthesis(string &str)
{
    stack<char> st;
    for(int i=0; i<str.size(); i++)
    {
        if(st.empty() || str[i]=='(' || str[i]=='{' || str[i]=='[')
        {
            st.push(str[i]);
            continue;
        }     
        else
        {
            if((str[i]==')' && st.top()!='(') || (str[i]=='}' && st.top()!='{') || (str[i]==']' && st.top()!='['))
            {
                return false;
            }
            else
                st.pop();   
        }
    }
    
    return st.empty();
}

void InsertAtBottomStack(stack<int> &st,int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }

    int num=st.top();
    st.pop();
    InsertAtBottomStack(st,x);
    st.push(num);

    return;
}

void ReverseStackUsingRecursion(stack<int> &st)
{
    if(st.size()==1)
        return;

    int num=st.top();
    st.pop();
    ReverseStackUsingRecursion(st);
    InsertAtBottomStack(st,num);

    return;
}

//aise stack questions ka ek hi concept h 
//pehle sare elements pop karo fir last se sort krna chalu karo jab stack khali ho ya sirf 1 element ho
void SortStack(stack<int> &st,int x)
{
    if(st.empty())
    {
        st.push(x);
        return;
    }

    int num=st.top();
    st.pop();
    if(x>=num)
    {
        st.push(num);
        st.push(x);
        return;
    }
    SortStack(st,x);
    st.push(num);
    
    return;
}

void SortAStackUsingRecursion(stack<int> &st) 
{
    if(st.empty() || st.size()==1)
        return;

    int num=st.top();
    st.pop();
    SortAStackUsingRecursion(st);
    SortStack(st,num);

    return;
}

void NextSmallerElement(stack<int> &st,vector<int> &ans,int n,int arr[])
{
    for(int i=n-1; i>=0; i--)
    {
        while(st.top()!=-1 && st.top()>=arr[i])
            st.pop();
        
        ans[i]=st.top();
        st.push(arr[i]);
    }
    return;
}

int LargestRectangularHistogram(int n,int arr[],stack<pair<int,int>>& st)
{
    vector<int> prev(n);
    vector<int> next(n);
    st.push({-1,n});
    for(int i=n-1; i>=0; i--)
    {
        while(st.top().first!=-1 && st.top().first>=arr[i])
            st.pop();
        next[i]=st.top().second;
        st.push({arr[i],i});
    }
    while(st.top().first!=-1)
        st.pop();
    st.top().second=-1;
    for(int i=0; i<n; i++)
    {
        while(st.top().first!=-1 && st.top().first>=arr[i])
            st.pop();
        prev[i]=st.top().second;
        st.push({arr[i],i});
    }
    int ans=-10;
    for(int i=0; i<n; i++)
        ans=max(ans,arr[i]*(next[i]-prev[i]-1));
    
    return ans;
}

void QueueReversalUsingStack()
{
    queue<int> q;
    stack<int> st;
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    cout<<"Enter elements in queue"<<endl;
    while(n--)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return;
}

void QueueReversalUsingRecursion(queue<int> &q)
{
    
    if(q.empty())
        return;

    int num=q.front();
    q.pop();
    QueueReversalUsingRecursion(q);
    q.push(num);

    return;
}

void FirstNegativeNumberInKSizeWindow(int arr[],int n,int k)
{
    vector<int> ans(n-k+1); // -8 2 3 -6 10  k=3 n=5  -8 -6 -6
    queue<pair<int,int>> q;
    for(int i=0; i<k; i++)
    {
        if(arr[i]<0)
            q.push({arr[i],i});
    }
    int x=0;
    if(q.empty())
        ans[x++]=0;
    else
        ans[x++]=q.front().first;
    for(int i=k; i<n; i++)
    {
        if(arr[i]<0)
            q.push({arr[i],i});
        if(q.empty())
        {
            ans[x++]=0;
            continue;
        }
        else if(q.front().second<i-k+1)
            q.pop();
        if(q.empty())
            ans[x++]=0;
        else 
            ans[x++]=q.front().first;
    }
    Printvector(ans);

    return;
}

void ReverseFirstKElements(queue<int> &q,int k)
{
    int qsize=q.size();
    stack<int> st;
    int t=k;
    while(t--)
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    int rem=qsize-k;
    while(rem--)
    {
        int x=q.front();
        q.pop();
        q.push(x);
    }

    return;
}

void FirstNonRepeatingCharacter(queue<char> &q)
{
    cout<<"Enter the character Stream"<<endl;
    string A;
    cin>>A;
    string ans="";
    unordered_map<char,int> m;
    for(int i=0; i<A.size(); i++) 
    {
        m[A[i]]++;
        q.push(A[i]);
        while(!q.empty())
        {
            if(m[q.front()]>1)
                q.pop();
            else
            {    
                ans+=q.front();
                break;
            }
        }
        if(q.empty())
            ans+='#';
    }
    cout<<ans<<endl;

    return;
}

void CircularPetrolTour()
{
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    pair<int,int> arr[n];
    cout<<"Enter petrol and distance"<<endl;
    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        arr[i]={a,b};
    }
    int start=0;
    int deficit=0;
    int balance=0;
    for(int i=0; i<n; i++)
    {
        balance+=arr[i].first-arr[i].second;
        if(balance<0)
        {
            deficit+=balance;
            start=i+1;
            balance=0;
        }
    }
    if(deficit+balance>=0)
        cout<<"circular tour index is "<<start<<endl;
    else
        cout<<-1;

    return;
}

void CreateBinaryTree(NodeBT* &root)
{
    int val;
    cout<<"Enter data in the Node"<<endl;
    cin>>val;
    if(val==-1)
        return;

    root=new NodeBT(val);
    
    cout<<"Enter data in the left subtree of "<<val<<endl;
    CreateBinaryTree(root->left);
    cout<<"Enter data in the right subtree "<<val<<endl;
    CreateBinaryTree(root->right);

    return;
}

void BTPreorderTraversal(NodeBT *root)
{
    if(root==NULL)
        return;
    
    cout<<root->data<<" ";
    BTPreorderTraversal(root->left);
    BTPreorderTraversal(root->right);

    return;
}

void BTInorderTraversal(NodeBT *root)
{
    if(root==NULL)
        return;

    BTInorderTraversal(root->left);
    cout<<root->data<<" ";
    BTInorderTraversal(root->right);

    return;
}

void BTInorderTraversalUsingStack(NodeBT* root)
{
    stack<NodeBT*> st;
    vector<int> ans;
    st.push(root);
    while(!st.empty())
    {
        if(root->left!=NULL)
        {
            root=root->left;
            st.push(root);
        }
        else
        {
            if(root==NULL)
                root=st.top();
            
            ans.push_back(root->data);
            st.pop();
            root=root->right;
        }
    }

    Printvector(ans);
}

void BTPostOrderTraversal(NodeBT *root)
{
    if(root==NULL)
        return;

    BTPostOrderTraversal(root->left);
    BTPostOrderTraversal(root->right);
    cout<<root->data<<" ";

    return;
}

vector<vector<int>> LevelOrderTraversal(NodeBT *root)
{
    queue<NodeBT*> q;
    q.push(root);
    vector<vector<int>> ans;
    while(!q.empty())
    {
        int size=q.size();
        vector<int> vec;
        for(int i=0; i<size; i++)
        {
            NodeBT *temp=q.front();
            vec.push_back(temp->data);
            q.pop();
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
        ans.push_back(vec);
    }
    return ans;
}

void NoOfLeafNodes(NodeBT *root,int& count)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        count++;
        return;
    }
    NoOfLeafNodes(root->left,count);
    NoOfLeafNodes(root->right,count);

    return;
}

int HeightOfBT(NodeBT *root)
{
    if(root==NULL)
        return 0;

    int left=HeightOfBT(root->left);
    int right=HeightOfBT(root->right);

    return max(left,right)+1;
}

int DiameterOfBTNaive(NodeBT* root)
{
    if(root==NULL)
        return 0;

    int left=DiameterOfBTNaive(root->left);
    int right=DiameterOfBTNaive(root->right);
    int common=HeightOfBT(root->left)+HeightOfBT(root->right)+1;

    return max(common,max(left,right));
}

pair<int,int> DiameterOfBTBest(NodeBT* root) 
{
    pair<int,int> ans; // ans.first m diameter store hoga har node ka and ans.second m height
    if(root==NULL)
    {
        ans.first=0;
        ans.second=0;
        return ans;
    }

    pair<int,int> left=DiameterOfBTBest(root->left);
    pair<int,int> right=DiameterOfBTBest(root->right);
    int common=left.second+right.second+1;

    ans.first=max(common,max(left.first,right.first));
    ans.second=max(left.second,right.second)+1;

    return ans;
}

bool CheckBalancedBTNaive(NodeBT *root)
{
    if(root==NULL)
        return true;

    bool left=CheckBalancedBTNaive(root->left);
    bool right=CheckBalancedBTNaive(root->right);
    bool check=abs(HeightOfBT(root->left)-HeightOfBT(root->right))<=1;

    if(left && right && check)
        return true;
    else
        return false;
}

pair<int,bool> CheckBalancedBTBest(NodeBT *root)
{
    pair<int,bool> ans;
    if(root==NULL)
    {
        ans.first=0;
        ans.second=true;
        return ans;
    }

    pair<int,bool> left=CheckBalancedBTBest(root->left);
    pair<int,bool> right=CheckBalancedBTBest(root->right);
    bool check=abs(left.first-right.first)<=1;

    if(check && left.second && right.second)
    {
        ans.first=max(left.first,right.first)+1;
        ans.second=true;
    }
    else
    {
        ans.first=0;
        ans.second=false;
    }

    return ans;
}

bool CheckIdenticalTrees(NodeBT *root1,NodeBT* root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    else if(root1==NULL && root2!=NULL)
        return false;
    else if(root1!=NULL && root2==NULL)
        return false;

    bool left=CheckIdenticalTrees(root1->left,root2->left);
    bool right=CheckIdenticalTrees(root1->right,root2->right);
    bool check=root1->data==root2->data;

    if(left && right && check)
        return true;
    else
        return false;
}

pair<int,bool> BTSumTree(NodeBT* root)
{
    pair<int,bool> ans;
    if(root==NULL)
    {
        ans.first=0;
        ans.second=true;
        return ans;
    }
    if(root->left==NULL && root->right==NULL)
    {
        ans.first=root->data;
        ans.second=true;
        return ans;
    }

    pair<int,bool> left=BTSumTree(root->left);
    pair<int,bool> right=BTSumTree(root->right);
    bool check=left.first+right.first==root->data;

    if(left.second && right.second && check)
    {
        ans.first=2*root->data;
        ans.second=true;
    }
    else
    {
        ans.first=0;
        ans.second=false;
    }

    return ans;
}

vector<int> BTZigZagTraversal(NodeBT *root)
{
    vector<int> ans;
    if(root==NULL)
        return ans;
    queue<NodeBT*> q;
    q.push(root);
    vector<vector<int>> vec;
    while(!q.empty())
    {
        int size=q.size();
        vector<int> temp1;
        for(int i=0; i<size; i++)
        {
            NodeBT *temp=q.front();
            q.pop();
            temp1.push_back(temp->data);
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
        vec.push_back(temp1);
    }
    int x=0;
    for(int i=0; i<vec.size(); i++)
    {
        if(x%2==0)
        {
            for(int j=0; j<vec[i].size(); j++)
                ans.push_back(vec[i][j]);
        }
        else
        {
            for(int j=vec[i].size()-1; j>=0; j--)
                ans.push_back(vec[i][j]);
        }
        x++;
    }

    return ans;
}

void BTBoundaryTraversalLeft(NodeBT *root,vector<int>& ans)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        return;

    ans.push_back(root->data);
    if(root->left!=NULL)
        BTBoundaryTraversalLeft(root->left,ans);
    else
        BTBoundaryTraversalLeft(root->right,ans);

    return;
}

void BTBoundaryTraversalLeaf(NodeBT* root,vector<int>& ans)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }

    BTBoundaryTraversalLeaf(root->left,ans);
    BTBoundaryTraversalLeaf(root->right,ans);

    return;
}

void BTBoundaryTraversalRight(NodeBT* root,vector<int>& ans)
{
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL)
        return;

    if(root->right!=NULL)
        BTBoundaryTraversalRight(root->right,ans);
    else
        BTBoundaryTraversalRight(root->left,ans);
    ans.push_back(root->data);

    return;
}

void VerticalOrderTraversal(NodeBT* root)
{
    if(root==NULL)
        return;

    map<int,map<int,vector<int>>> m;
    queue<pair<NodeBT*,pair<int,int>>> q;
    q.push({root,{0,0}});

    while(!q.empty())
    {
        pair<NodeBT*,pair<int,int>> temp=q.front();
        q.pop();
        int hd=temp.second.first;
        int lvl=temp.second.second;
        m[hd][lvl].push_back(temp.first->data);
        if(temp.first->left!=NULL)
            q.push({temp.first->left,{hd-1,lvl+1}});
        if(temp.first->right!=NULL)
            q.push({temp.first->right,{hd+1,lvl+1}});
    }

    vector<int> ans;
    for(auto i:m)
    {
        for(auto j:i.second)
        {
            for(auto k:j.second)
                ans.push_back(k);
        }
    }

    Printvector(ans);

    return;
}

void TopViewOfBT(NodeBT* root)
{
    if(root==NULL)
        return;

    map<int,vector<int>> m;
    queue<pair<NodeBT*,int>> q;
    q.push({root,0});

    while(!q.empty())
    {
        pair<NodeBT*,int> temp=q.front();
        q.pop();
        int hd=temp.second;
        m[hd].push_back(temp.first->data);
        if(temp.first->left!=NULL)
            q.push({temp.first->left,hd-1});
        if(temp.first->right!=NULL)
            q.push({temp.first->right,hd+1});
    }

    vector<int> ans;
    for(auto i:m)
    {
        ans.push_back(i.second[0]);
    }

    Printvector(ans);

    return;
}

void BottomViewOfBT(NodeBT* root)
{
    if(root==NULL)
        return;

    map<int,vector<int>> m;
    queue<pair<NodeBT*,int>> q;
    q.push({root,0});

    while(!q.empty())
    {
        pair<NodeBT*,int> temp=q.front();
        q.pop();
        int hd=temp.second;
        m[hd].push_back(temp.first->data);
        if(temp.first->left!=NULL)
            q.push({temp.first->left,hd-1});
        if(temp.first->right!=NULL)
            q.push({temp.first->right,hd+1});
    }

    vector<int> ans;
    for(auto i:m)
    {
        ans.push_back(i.second[i.second.size()-1]);
    }

    Printvector(ans);

    return;
}

void BTLongestBloodline(NodeBT* &root,int &ansheight,int& anssum,int tempheight,int tempsum)
{
    if(root==NULL)
        return;
    
    tempsum+=root->data;
    tempheight++;
    if(root->left==NULL && root->right==NULL)
    {
        if(tempheight>ansheight)
            anssum=tempsum;
        else if(tempheight==ansheight)
            anssum=max(anssum,tempsum);
        
        return;
    }

    BTLongestBloodline(root->left,ansheight,anssum,tempheight,tempsum);
    BTLongestBloodline(root->right,ansheight,anssum,tempheight,tempsum);

    return;
}

NodeBT* LCAOfBT(NodeBT* root,int val1,int val2)
{
    if(root==NULL)
        return NULL;

    if(root->data==val1 || root->data==val2)
        return root;

    NodeBT *left=LCAOfBT(root->left,val1,val2);
    NodeBT *right=LCAOfBT(root->right,val1,val2);
    
    if(left==NULL && right==NULL)
        return NULL;
    else if(left!=NULL && right==NULL)
        return left;
    else if(left==NULL && right!=NULL)
        return right;
    else
        return root;
}

void KSumPath(NodeBT* root,vector<int> vec,int k,int &ans)
{
    if(root==NULL)
        return;

    vec.push_back(root->data);
    
    KSumPath(root->left,vec,k,ans);
    KSumPath(root->right,vec,k,ans);

    int sum=0;
    for(int i=vec.size()-1; i>=0; i--)
    {
        sum+=vec[i];
        if(k==sum)
            ans++;
    }

    vec.pop_back();

    return;
}

NodeBT* KthAncestor(NodeBT* root,int val1,int& k)
{
    if(root==NULL)
        return NULL;
    if(root->data==val1)
        return root;
    
    NodeBT* left=KthAncestor(root->left,val1,k);
    NodeBT* right=KthAncestor(root->right,val1,k);

    if(left==NULL && right!=NULL)
    {
        k--;
        if(k<=0)
        {   
            k=INT_MAX; 
            return root;
        }
        else
            return left;
    }
    if(left!=NULL && right==NULL)
    {
        k--;
        if(k==0)
        {
            k=INT_MAX;
            return root;
        }
        else
            return right;
    }

    return NULL;
}

NodeBT* BTFromInorderAndPreorder(int start,int end,int& preorderindex,
map<int,int>& m,vector<int>& in,vector<int>& pre)
{
    if(preorderindex>=pre.size() || start>end)
        return NULL;

    NodeBT* root=new NodeBT(pre[preorderindex]);
    int currentval=pre[preorderindex++];
    int pos=m[currentval];

    root->left=BTFromInorderAndPreorder(start,pos-1,preorderindex,m,in,pre);
    root->right=BTFromInorderAndPreorder(pos+1,end,preorderindex,m,in,pre);

    return root;
} 

NodeBT* BTFromInorderAndPostorder(int start,int end,int& postorderindex,
map<int,int>& m,vector<int>& in,vector<int>& post)
{
    if(postorderindex<0 || start>end)
        return NULL;

    NodeBT* root=new NodeBT(post[postorderindex]);
    int currentval=post[postorderindex--];
    int pos=m[currentval];

    root->right=BTFromInorderAndPostorder(pos+1,end,postorderindex,m,in,post);
    root->left=BTFromInorderAndPostorder(start,pos-1,postorderindex,m,in,post);

    return root;
}

NodeBT* InsertingInBST(NodeBT* root,int x)
{
    if(root==NULL)
    {
        NodeBT* newnode=new NodeBT(x);
        root=newnode;
        return root;
    }

    if(x<root->data)
        root->left=InsertingInBST(root->left,x);
    else if(x>root->data)
        root->right=InsertingInBST(root->right,x);

    return root;
}

void CreateBinarySearchTree(NodeBT* &root)
{
    cout<<"Enter values in BST"<<"\n";
    cout<<"Enter -1 to stop entering values"<<"\n";
     int x;
     cin>>x;
     while(x!=-1)
     {
        root=InsertingInBST(root,x); 
        cin>>x;
     }
     
    return;
}

void SearchInBST(NodeBT* root,int val)
{
    while(root!=NULL)
    {
        if(val>root->data)
            root=root->right;
        else if(val<root->data)
            root=root->left;
        else
        {
            cout<<"Value found"<<"\n";
            return;
        }
    }
    cout<<"Value not found"<<"\n";

    return;
}

NodeBT* DeletionInBST(NodeBT* root,int x)
{
    if(root==NULL)
    {
        cout<<"Value not found";
        return NULL;
    }

    if(root->data==x)
    {
        //for 0 child
        if(root->left==NULL && root->right==NULL)
            return NULL;
        //for 1 child
        else if(root->left==NULL && root->right!=NULL)
            return root->right;
        else if(root->left!=NULL && root->right==NULL)
            return root->left;
        //for 2 child
        else 
        {
            int maxval;
            NodeBT* leftnode=root->left;
            while(leftnode->right!=NULL)
                leftnode=leftnode->right;
            maxval=leftnode->data;
            root->data=maxval;
            root->left=DeletionInBST(root->left,maxval);
            return root;
        }
    }
    else if(x>root->data)
        root->right=DeletionInBST(root->right,x);
    else
        root->left=DeletionInBST(root->left,x);

    return root;
}

bool ValidateBST(NodeBT* root,int min,int max)
{
    if(root==NULL)
        return true;

    bool left=ValidateBST(root->left,min,(root->data)-1);
    bool right=ValidateBST(root->right,root->data+1,max);
    bool check=(root->data>=min && root->data<=max);

    if(left && right && check)
        return true;
    else 
        return false;
}

void KthSmallestElementInBST(NodeBT* root,int& k,int& ans)
{
    if(root==NULL)
        return;
 
    KthSmallestElementInBST(root->left,k,ans);
    k--;
    if(k==0)
    {
        ans=root->data;
        return;
    }
    KthSmallestElementInBST(root->right,k,ans);

    return;
}

void PredecessorAndSuccessorOfNodeInBST(NodeBT* root,int& pre,int& suc,int key)
{
    if(root==NULL)
    {
        pre=-1;
        suc=-1;
        return;
    }

    NodeBT* temp=root;
    while(temp!=NULL)
    {
        if(key>temp->data)
            temp=temp->right;
        else if(key<temp->data)
            temp=temp->left;
        else
        {
            NodeBT *predecessor,*successor;
            predecessor=temp->left;
            successor=temp->right;
            while(predecessor->right!=NULL)
                predecessor=predecessor->right;
            
            pre=predecessor->data;

            while(successor->left!=NULL)
                successor=successor->left;

            suc=successor->data;
            return;
        }
    }
    
    return;
}

NodeBT* LCAInBST(NodeBT* root,int val1,int val2)
{
    if(root==NULL)
        return NULL;

    if(root->data<val1 && root->data<val2) 
        return LCAInBST(root->right,val1,val2);
    
    else if(root->data>val1 && root->data>val2)
        return LCAInBST(root->left,val1,val2);
    else
        return root;    
}

void TwoSumBST(NodeBT* root,vector<int>& vec)
{
    if(root==NULL)
        return;

    TwoSumBST(root->left,vec);
    vec.push_back(root->data);
    TwoSumBST(root->right,vec);

    return;
}

NodeBT* InorderToBST(vector<int>& in,int s,int e)
{
    if(s>e)  
        return NULL;

    int mid=s+(e-s)/2;
    NodeBT *root=new NodeBT(in[mid]);
    root->left=InorderToBST(in,s,mid-1);
    root->right=InorderToBST(in,mid+1,e);

    return root;
}

NodeBT* Merge2BST(vector<int> &inans,int s,int e)
{
    if(s>e)
        return NULL;

    int mid=s+(e-s)/2;
    NodeBT* root=new NodeBT(inans[mid]);
    
    root->left=Merge2BST(inans,s,mid-1);
    root->right=Merge2BST(inans,mid+1,e);

    return root;
}

void PrintLL(Node* temp)
{
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return;
}



void PrintCLL(Node* temp)
{
    Node* start;
    start=temp;
    do
    {

        cout<<temp->data<<" ";
        temp=temp->next;
    
    }while(temp!=start);
    cout<<temp->data<<" ";

    return;
}

void PrintDLL(NodeDLL *temp,string check)
{
    if(check=="front")
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    else
    {
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->prev;
        }
    }
    return;
}

void PrintDCLL(NodeDLL* temp,string check)
{
    NodeDLL *stopper;
    stopper=temp;
    if(check=="front")
    {
        do
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=stopper);
        cout<<temp->data<<" ";
    }
    else
    {
        do
        {
            cout<<temp->data<<" ";
            temp=temp->prev;
        }while(temp!=stopper);
        cout<<temp->data<<" ";
    }
    return;
}

void PushElementsInStack(stack<int> &st)
{
    cout<<"Enter number of elements to insert"<<endl;
    int y;
    cin>>y;
    while(y--)
    {
        int x;
        cin>>x;
        st.push(x);
    }
    return;
}

void PrintStack(stack<int> st)
{
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    return;
}

void PrintQueue(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return;
}

int main()
{
//Binary to decimal conversion and vice versa
//Reverse integer
/*
int x=456;
int sum=0;
while(x>0)
{
    int t=x%10;
    sum=sum*10+t;
    x/=10;
}
cout<<sum;
*/

//switch condition syntax
/*
int exp=5;
switch(exp)
{
    case 1: ......;
        break;
    case 2: ......;
        break;
    default: .....;
}
*/

// array intitialise
//int arr[5]={1,3,5,6,7};
//reverse array
// time complexity   O -> Upper bound    theta -> avg case    omega -> lower bound

// binary search 
/*
int arr[5]={1,3,5,7,9};
int s,e,mid;
s=0;
e=4;
int key=9;
int ans=0;
mid=s+(e-s)/2;
while(s<=e)
{
    mid=s+(e-s)/2;
    if(arr[mid]<key)
        s=mid+1;
    else if(arr[mid]>key)
        e=mid-1;
    else
    {
        ans=1;
        break;
    }    
}
cout<<ans;
*/

//first and last position of a number
//find peak in a mountain 
/*
int arr[5]={1,3,4,5,2};
int s,e,mid;
s=0;
e=4;
mid=s+(e-s)/2;
while(s<e)
{
    mid=s+(e-s)/2;
    if(arr[mid]<arr[mid+1])
        s=mid+1;
    else 
        e=mid;
}
cout<<s;
*/

//pivot in an array
/*
int arr[7]={4,5,6,0,1,2,3};
int s,e,mid;
s=0;
e=6;
mid=s+(e-s)/2;
while(s<e)
{
    mid=s+(e-s)/2;
    if(arr[0]<=arr[mid])
        s=mid+1;
    else
        e=mid;
}
cout<<s;
*/

//search in rotated sorted array
//first find pivot
/*
int arr[7]={4,5,6,0,1,2,3};
int key=3;
int s,e,mid;
s=0;
e=6;
mid=s+(e-s)/2;
while(s<e)
{
    mid=s+(e-s)/2;
    if(arr[0]<=arr[mid])
        s=mid+1;
    else
        e=mid;
}
int pivot=s;
if(arr[0]<=key)
{
    s=0;
    e=pivot-1;
}
else
{
    s=pivot;
    e=6;
}
mid=s+(e-s)/2;
int check=0;
while(s<=e)
{
    mid=s+(e-s)/2;
    if(arr[mid]<key)
        s=mid+1;
    else if(arr[mid]>key)
        e=mid-1;
    else
    {
        cout<<"found at index "<<mid;
        check=1;
        break;
    }   
}
if(!check) cout<<"Not found";
*/

//sortings
//selection sort -> finding the minimum and placing it then decreasing the size of array 
/*
int arr[7]={5,3,2,1,6,4,9};
int n=7;
for(int i=0; i<n-1; i++)
{
    int mini=arr[i];
    int index=i;
    for(int j=i; j<n; j++)
    {
        if(mini>arr[j])
        { 
            mini=arr[j];
            index=j;
        }
    }
    swap(arr[i],arr[index]);
}
Printarray(arr,n);
*/

//bubble sort -> swap adjacent values
/*
int arr[7]={5,3,2,1,6,4,9};
int n=7;
for(int i=0; i<n-1; i++)
{
    for(int j=0; j<n-1-i; j++)
        if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
    
}
Printarray(arr,n);
*/

//insertion sort -> take values and place it at right position by shifting prior values right side
/*
int arr[7]={5,3,2,1,6,4,9};
int n=7;
for(int i=1; i<n; i++)
{
    int index=i;
    int value=arr[i];
    for(int j=i-1; j>=0; j--)
    {
        if(arr[i]>=arr[j])
            break;
        else
            index=j;
    }
    for(int j=i-1; j>=index; j--)
        arr[j+1]=arr[j];
    
    arr[index]=value; 
}
Printarray(arr,n);
*/

// Standard template library (STL)
// C++ STL -> Algorithms, Containers
// Algorithms -> binary search, lower bound, upper bound, min, max, reverse, sort, swap
// Containers -> Array, Vector, Deque, List, Stack, Queue, Priority Queue, Set, 
//               Map, Multiset, Unordered Set, Unordered Map 

// Array
/*
array<int,4> a={1,2,3,4};
int size=a.size();
cout<<"Element at index 2 "<<a.at(2)<<endl;
cout<<"Empty or not "<<a.empty()<<endl;
cout<<"First element"<<a.front()<<endl;
cout<<"last element"<<a.back()<<endl;
*/

// Vector
/*
vector<int> vec;
vector<int> vec1(5,0); -> intialises all the 5 values with 0
vector<vector<int>> vec2(5, vector<int>(4,0)); -> intialising 2D array with 5 rows and 4 columns with 0 value
vec.push_back(1);
vec.pop_back();
cout<<"Element at index 2 "<<vec1.at(2);
cout<<"First element "<<vec1.front();
cout<<"last element "<<vec1.back();
*/

//Deque -> can be used from front and back
/*
deque<int> de;
de.push_back(1);
de.push_front(2);
de.pop_back();
de.pop_front();
de.erase(de.begin(), de.begin()+1);
*/

//List -> can be used from front and back
/*
list<int> l(5,10); -> initialises the values with 10
l.push_back(1);
l.push_front(2);
*/

//Stack
/*
stack<string> st;
st.push("Shubham");
st.push("Bhavya");
st.push("Shivansh");
st.top();
st.pop();
st.empty();
st.size();
*/

//Queue
/*
queue<string> qe;
qe.push("shubham");
qe.push("shivansh");
qe.push("bhavya");
qe.front();
qe.pop();
qe.empty();
qe.size();
*/

//Priority_queue
/* 
priority_queue<int> pq_maxi; -> max heap
priority_queue<int, vector<int>, greater<int>> pq_mini; -> min heap
maxi.push(1);
maxi.push(2);
maxi.top();
maxi.pop();
maxi.empty();
*/

//Set
/*
set<int> se;
se.insert(2);
se.insert(3);
set<int>::iterator it=se.begin();
se.erase(it);
*/

//map
/*
map<int,string> m;
m[0]="shubham";
m[1]="bhavya";
m.erase(1); -> removes key and value mapped to key 1
m.insert({2,"shivansh"});
for(auto i:m)
    cout<<i.first<<" "<<i.second<<endl;
*/

//Algorithms
/*
cout<<binary_search(vec.begin(),vec.end(),5); gives 1 if present otherwise 0
cout<<max(a,b);
cout<<min(a,b);
swap(a,b);
sort(vec.begin(),vec.end());
reverse(vec.begin(),vec.end());
*/

//reverse an array
/*
int arr[7]={5,3,2,1,6,4,9};
int n=7;
for(int i=0; i<n/2; i++)
{
    int temp=arr[i];
    arr[i]=arr[n-1-i];
    arr[n-1-i]=temp;
}
Printarray(arr,n);
*/

//merge 2 sorted arrays
/*
int n1,n2;
n1=5;
n2=7;
int arr1[n1]={2,4,6,7,8};
int arr2[n2]={1,3,4,7,8,9,10};
int i1,i2;
i1=0;
i2=0;
vector<int> vec;
while(i1<n1 && i2<n2)
{
    if(arr1[i1]==arr2[i2])
    {
        vec.push_back(arr1[i1++]);
        vec.push_back(arr2[i2++]);
    }
    else if(arr1[i1]<arr2[i2])
        vec.push_back(arr1[i1++]);
    else
        vec.push_back(arr2[i2++]);
}
while(i1<n1)
    vec.push_back(arr1[i1++]);

while(i2<n2)
    vec.push_back(arr2[i2++]);
*/

//move zeros
/*
int n=7;
int arr[n]={2,1,0,3,6,0,0};
int i=0;
for(int j=0; j<n; j++)
{
    if(arr[j]!=0)
    {
        swap(arr[i],arr[j]);
        i++;
    }
}
Printarray(arr,n);
*/

//rotate arrays
/*
vector<int> vec={3,4,5,6,7,8};
vector<int> temp(vec.size());
int k=2; // number of rotations
k=k%vec.size(); // if k is greater than size of vector then k%size brings it in vector range 
//*** temp[(i+k)%vec.size()]=vec[i] -> rotates array elements properly without multiple iterations (Best formula)
for(int i=0; i<vec.size(); i++)
    temp[(i+k)%vec.size()]=vec[i];
Printvector(temp);
*/

//sorted rotated array or not
/*
int n=5;
int arr[n]={3,4,5,1,2};
int cnt=0;
for(int i=0; i<n-1; i++)
{
    if(arr[i]>arr[i+1])
        cnt++;
}
if(cnt==1) cout<<"true";
else cout<<"false";
*/

//add 2 arrays
/*
int n1,n2;
n1=4;
n2=2;
int arr1[n1]={1,2,3,4};
int arr2[n2]={9,9};
int i,j;
i=n1-1;
j=n2-1;
int carry=0;
vector<int> ans;
while(i>=0 || j>=0 || carry!=0)
{
    int sum=0;
    if(i>=0)
        sum+=arr1[i];
    if(j>=0)
        sum+=arr2[j];
    sum+=carry;
    carry=sum/10;
    sum=sum%10;
    ans.push_back(sum);
    i--;
    j--;
}
reverse(ans.begin(),ans.end());
Printvector(ans);
*/

//strings and char arrays
/*
cin>> execution stops when tab '\t', space '_', newline '\n' are given
last element of char array or string is '\0'
*/

//palindrome check
/*
string s1="abcba";
for(int i=0; i<s1.size()/2; i++)
{
    if(s1[i]!=s1[s1.size()-1-i]) 
    {
        cout<<"Not a palindrome";
        return 0;
    } 
}
cout<<"It is a palindrome";
*/

//remove all faltu characters lowercase the string and check palindrome
//getline(cin,str); -> takes a line as input 
/*
string s1;
getline(cin,s1);
string ans="";
for(int i=0; i<s1.size(); i++)
{
    if((s1[i]>='a' && s1[i]<='z') || (s1[i]>='A' && s1[i]<='Z'))
    {
        s1[i]=tolower(s1[i]);
        ans+=s1[i];
    }   
}
for(int i=0; i<ans.size()/2; i++)
{
    if(ans[i]!=ans[ans.size()-1-i])
    {
        cout<<"Not a palindrome";
        return 0;
    }
}
cout<<"It is a palindrome";
*/

//reverse words in a string
/*
string s;
getline(cin,s);
vector<string> vec;
string temp="";
for(int i=0; i<s.size(); i++)
{
    if(i==s.size()-1)
    {
        temp+=s[i];
        vec.push_back(temp);
        break;
    }
    if(s[i]==' ')
    {
        vec.push_back(temp);
        temp="";
        continue;
    }
    temp+=s[i];
}
for(int i=0; i<vec.size(); i++)
{
    for(int j=0; j<vec[i].size()/2; j++)
    {
        char x=vec[i][j];
        vec[i][j]=vec[i][vec[i].size()-1-j];
        vec[i][vec[i].size()-1-j]=x;
    }
}
string ans="";
for(int i=0; i<vec.size(); i++)
    ans+=vec[i]+" ";
ans.pop_back();
cout<<ans;
*/

//remove all occurrences of a substring
/*
string s1="daabcbaabcbc";
string s2="abc";
while(s1.size()!=0 && s1.find(s2)<s1.size()) //if substring not present then s.find points at the position just after the last element
    s1.erase(s1.find(s2),s2.size());

cout<<s1;
*/

//permutation in string
/*
string s1="eidbooo";
string s2="ab";
int count1[26]={0};
int count2[26]={0};
int i=0; 
while(i<s2.size())
{
    int temp=s2[i]-'a';
    count2[temp]++;
    i++;
}
i=0;
while(i<s2.size()) //first window traversed
{
    int temp=s1[i]-'a';
    count1[temp]++;
    i++;
}
if(checking(count1,count2))
{
    cout<<"True";
    return 0;
} 
int j=0;
while(i<s1.size())
{
    int temp=s1[i]-'a';
    int temp1=s1[j]-'a';
    count1[temp]++;
    count1[temp1]--;
    i++;
    j++;
    if(checking(count1,count2))
    { 
        cout<<"True";
        return 0;
    }
}
cout<<"False";
*/

//remove all adjacent from string
// s.erase(s.begin(),s.begin()+1); -> used for erasing elements (removes 1st element here)
/*
string s="aabbccddaaa";
while(s.size()!=0 && s[0]==s[1])
{ 
    s.erase(s.begin(),s.begin()+1);
    s.erase(s.begin(),s.begin()+1);
}

int i=1;
while(i<s.size())
{
    if(s[i]==s[i+1])
    {
        s.erase(s.begin()+i,s.begin()+i+2);
        continue;
    }    
    i++;
}
cout<<s;
*/

//wave Print in 2D array
/*
int n1,n2;
n1=3;
n2=4;
int arr[n1][n2]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
int x=0;
for(int i=0; i<n2; i++)
{
    if(x%2==0)
    {
        for(int j=0; j<n1; j++)
        {
            cout<<arr[j][i]<<" ";
        }
    }
    else
    {
        for(int j=n1-1; j>=0; j--)
        {
            cout<<arr[j][i]<<" ";
        }
    }
    x++;
    cout<<endl;
}
*/

//spiral Printing
/*
int n1,n2;
n1=4;
n2=5;
int arr[n1][n2];
for(int i=0; i<n1; i++)
{
    for(int j=0; j<n2; j++)
        cin>>arr[i][j];
}
int x=1;
int l,r,u,d;
l=0;
u=0;
r=n2-1;
d=n1-1;
while(l<=r && u<=d)
{
    if(x==1)
    {
        for(int i=l; i<=r; i++)
            cout<<arr[u][i]<<" ";

        u++;
        x=2;
    }
    else if(x==2)
    {
        for(int i=u; i<=d; i++)
            cout<<arr[i][r]<<" ";

        r--;
        x=3;
    }
    else if(x==3)
    {
        for(int i=r; i>=l; i--)
            cout<<arr[d][i]<<" ";

        d--;
        x=4;
    }
    else 
    {
        for(int i=d; i>=u; i--)
            cout<<arr[i][l]<<" ";

        l++;
        x=1;
    }
}
*/

//binary search in array
/*
int row,col;
row=3;
col=3;
int arr[row][col];
for(int i=0; i<row; i++)
{
    for(int j=0; j<col; j++)
        cin>>arr[i][j];
}
int target;
cin>>target;
int s,e;
s=0;
e=(row*col)-1;
int mid=s+(e-s)/2;
while(s<=e)
{
    mid=s+(e-s)/2;
    int i=mid/row;
    int j=mid%col;
    if(arr[i][j]<target)
        s=mid+1;
    else if(arr[i][j]>target)
        e=mid-1;
    else
    {
        cout<<"Found at index "<<mid;
        return 0;
    }    
}
cout<<"Not found";
*/

//sieve of eratosthenes -> finding primes between a range
/*
int n=50;
vector<bool> vec(n+1,true);
vec[0]=false;
vec[1]=false;
int cnt=0;
for(int i=0; i<=n; i++)
{
    if(vec[i])
    {
        cnt++;
        for(int j=i*2; j<=n; j=j+i)
            vec[j]=false;
    }
}
cout<<cnt;
*/

//GCD 
/*
int gcd;
int a,b;
a=48;
b=22;
while(a!=b)
{
    if(a>=b)
        a=a-b;
    else
        b=b-a;
}
if(a==0) gcd=b;
else gcd=a;   

//LCM
int lcm=a*b/gcd;
cout<<lcm;
*/

//pointers
/*
int a=5;
int* p=&a;
cout<<p<<endl; //gives address of a
cout<<*p<<endl; //gives value of a (dereferencing value at address of a)
cout<<++p<<endl; //increases address by 4 cuz int takes 4 bytes
p--;
cout<<++(*p)<<endl; //increases value by 1

//array name is the address of the first element of array or starting of array
int arr[3]={2,3,4};
cout<<arr<<endl; //same result as &arr[0]
cout<<&arr[0]<<endl;
cout<<*arr<<endl;
cout<<*(arr+1)<<endl;
cout<<(*arr)+1<<endl;
//int arr[] and int *arr will work same in functions
//arr[i]=*(arr+i) god formula and concept
*/

//dynamic memory allocation
/*
int n=5;
int *arr=new int[n]; //creates dynamic array of size 5
int *i=new int; //creates dynamic integer
delete []arr; //deletes array space from heap
delete i; //deletes integer space from heap

int **brr=new int*[n]; //creates space for 2D array
for(int i=0; i<n; i++)
    brr[i]=new int[n]; //creating cols for 2D array

for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        cin>>brr[i][j];

for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
        cout<<brr[i][j]<<" ";

for(int i=0; i<n; i++)
    delete []brr[i];
delete []brr;
*/

//recursion
/*
int n=5;
int arr[n]={6,5,7,8,8};
int target=5;
cout<<factorial(n)<<endl;
cout<<power(n)<<endl;
cout<<fibonacci(n)<<endl;
cout<<sorted(arr,n-1)<<endl;
cout<<linearsearch(arr,n-1,target)<<endl;
int s,e;
s=0;
e=n-1;
cout<<binarysearch(arr,s,e,target)<<endl;
string str="abcba";
reverseusingrec(str,s,e);
cout<<str<<endl;
reverse(str.begin(),str.end());
cout<<CheckPalindromeUsingrecursion(str,s,e)<<endl;
int a=3,b=3;
cout<<getpower(a,b)<<endl;
*/

//mergesort
/*
int n=7;
int arr[n]={6,3,5,1,2,8,0};
mergesort(arr,0,n-1);
Printarray(arr,n);
*/

//power sets
/*
int n=3;
int arr[n]={1,2,3};
int s=0;
vector<vector<int>> ans;
vector<int> temp;
powerset(arr,s,n,ans,temp);
sort(ans.begin(),ans.end());
Print2Dvector(ans);
*/

//subsequences of a string
/*
string str="abc";
string temp="";
vector<string> ans;
subsequenceofstring(str,temp,ans,0);
sort(ans.begin(),ans.end());
Printstrings(ans);
*/

//permutations of a string
/*
string str="abc";
vector<string> ans;
permutationsofstring(str,ans,0);
sort(ans.begin(),ans.end());
Printstrings(ans);
*/

//rat in a maze
/*
vector<string> ans;
string temp="";
int n=4;
vector<vector<int>> vec(n,vector<int>(n,0));
vector<vector<int>> vis(n,vector<int>(n,0));
for(int i=0; i<n; i++)
{
    for(int j=0; j<n; j++)
        cin>>vec[i][j];
}
ratinamaze(vec,vis,ans,temp,0,0);
Printstrings(ans);
*/

//OOPS
//Access modifiers -> public, private, protected -> by default its private
//creation of object

/*
Hero shubham;
shubham.age=21;
shubham.sethealth(90);
cout<<sizeof(shubham)<<endl;
cout<<shubham.age<<endl;
shubham.gethealth();

//dynamic allocation
Hero *shubhi=new Hero;
(*shubhi).age=20;
(*shubhi).sethealth(70);
cout<<sizeof(shubhi)<<endl;
cout<<shubhi->age<<endl;
(*shubhi).gethealth(); // (*shubhi).age and shubhi->age gives same thing
//constructor -> produced automatically when you create object -> shubham.Hero()
*/

//Pillars of OOPS ->encapsulation, inheritance, polymorphism, abstraction
//encapsulation -> all data members and functions are kept in private access modifier ->security increases, make class read only, code reusability
//inheritance -> single, multi-level, multiple, hybrid, heirarchical
//single -> simple inheritance
//multi-level -> a inherits b and b inherits c
//multiple -> c inherits a and b both
//heirarchical -> making a tree type of inheritance
/*
Male shubham;
shubham.age=21;
shubham.sethealth(100);
shubham.gethealth();
*/
//inheritance ambiguity -> there are 2 classes A and B both have abc function in them now class C inherits A and B both, 
//now C calls abc (which will be called now abc from A class or abc from B class)? this is solved by scope resolution operator
//syntax-> shubham.A::abc(); shubham.B::abc();

//Polymorphism
//compile-time polymorphism -> function overloading -> change input arguments if name of function is same 
//                             operator overloading -> assigns new task to operators
//run-time polymorphism 

//Abstraction -> implementation hiding

//Linked list -> Linear data structure, dynamically implemented, no extra space, no memory wastage 
//singly LL creation
/*
Node *start,*last;
start=last=NULL;
creationLL(start,last);
PrintLL(start);
*/

//Circular LL creation
/*
Node *start,*last;
start=last=NULL;
creationCLL(start,last);
PrintCLL(start);
*/

//Doubly LL creation
/*
NodeDLL *start,*last;
start=last=NULL;
creationDLL(start,last);
PrintDLL(start,"front");
cout<<endl;
PrintDLL(last,"back");
*/

//Doubly circular LL creation
/*
NodeDLL *start,*last;
start=last=NULL;
creationDCLL(start,last);
PrintDCLL(start,"front");
cout<<endl;
PrintDCLL(last,"back");
*/

//reverse LL
/*
start=reverseLL(start);
PrintLL(start);
middleofLL(start);
*/

//reverse in K groups
/*
int k;
cout<<"Enter k value for reverses"<<endl;
cin>>k;
start=reverseingroups(start,k);
PrintLL(start);
*/

//circular LL check
/*
Node *start,*last;
start=last=NULL;
creationCLL(start,last);
circularLLcheck(start);
*/

//detect and remove loop in LL -> floyd's cycle detection Algo ***
/*
Node *start,*last;
start=last=NULL;
creationCLL(start,last);
removeloop(start);
*/

//remove duplicates from sorted LL
/*
Node *start,*last;
start=last=NULL;
creationLL(start,last);
removeduplicatessorted(start);
PrintLL(start);
*/

//remove duplicates from unsorted LL
/*
Node *start,*last;
start=last=NULL;
creationLL(start,last);
unordered_map<int,int> m;
removeduplicateunsorted(start,m);
PrintLL(start);
*/

//sort linked list
/*
Node *start,*last;
start=last=NULL;
creationLL(start,last);
sortLL(start);
PrintLL(start);
*/

//merge 2 sorted LL
/*
Node *start1,*last1,*start2,*last2;
start1=last1=start2=last2=NULL;
creationLL(start1,last1);
cout<<"Now list 2"<<endl;
creationLL(start2,last2);
Node *ans,*merger;
ans=merger=NULL;
merge2LL(start1,start2,ans,merger);
PrintLL(ans);
*/

//check LL palindrome or not 
/*
Node *start,*last;
start=last=NULL;
creationLL(start,last);
CheckLLPalindrome(start);
*/

//Add 2 numbers in LL
/*
Node *start1,*last1,*start2,*last2;
start1=last1=start2=last2=NULL;
creationLL(start1,last1);
cout<<"Now list 2"<<endl;
creationLL(start2,last2);
Node *ans;
ans=NULL;
Add2LL(start1,start2,ans);
PrintLL(ans);
*/

//Stacks

//create stack using array 
/*
Stack St(5);
St.push(1);
cout<<St.peek()<<endl;
St.pop();
*/

//Reverse a string using stack
/*
string str;
cout<<"Enter string"<<endl;
cin>>str;
cout<<ReverseStringUsingStack(str)<<endl;
*/

//valid parenthesis
/*
string str;
cout<<"Enter the expression"<<endl;
cin>>str;
cout<<ValidParenthesis(str);
*/

//insert an element at bottom of stack
/*
stack<int> st;
PushElementsInStack(st);
int x;
cout<<"Enter number to insert"<<endl;
cin>>x;
InsertAtBottomStack(st,x);
PrintStack(st);
*/

//reverse stack using recursion
/*
stack<int> st;
PushElementsInStack(st);
ReverseStackUsingRecursion(st);
PrintStack(st);
*/

//sort a stack
/*
stack<int> st;
PushElementsInStack(st);
SortAStackUsingRecursion(st);
PrintStack(st);
*/

//next smallest element
/*
stack<int> st;
int n;
cout<<"Enter size of array"<<endl;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
    cin>>arr[i];
st.push(-1);
vector<int> ans(n);
NextSmallerElement(st,ans,n,arr);
Printvector(ans);
*/

//largest rectangular histogram
/*
stack<pair<int,int>> st;
int n;
cout<<"Enter size of array"<<endl;
cin>>n;
int arr[n];
for(int i=0; i<n; i++)
    cin>>arr[i];
cout<<LargestRectangularHistogram(n,arr,st);
*/

//Queue

//queue reversal
/*
QueueReversalUsingStack();
*/

/*
queue<int> q;
int n;
cout<<"Enter size of queue"<<endl;
cin>>n;
cout<<"Enter elements in queue"<<endl;
int t=n;
while(n--)
{
    int x;
    cin>>x;
    q.push(x);
}
QueueReversalUsingRecursion(q);
PrintQueue(q);
*/

//First negative number in K size window
/*
int n;
cout<<"Enter size of array"<<endl;
cin>>n;
int k;
cout<<"Enter size of window"<<endl;
cin>>k;
int arr[n];
for(int i=0; i<n; i++)
    cin>>arr[i];
FirstNegativeNumberInKSizeWindow(arr,n,k);
*/

//Reverse first k elements of queue
/*
int n;
cout<<"Enter size of queue"<<endl;
cin>>n;
int k;
cout<<"Enter size of window"<<endl;
cin>>k;
cout<<"Enter the elements of queue"<<endl;
queue<int> q;
while(n--)
{
    int x;
    cin>>x;
    q.push(x);
}
ReverseFirstKElements(q,k);
PrintQueue(q);
*/

//First non repeating character in stream
/*
queue<char> q;
FirstNonRepeatingCharacter(q); //difficult logic
*/

//Circular tour possible or not
/*
CircularPetrolTour(); //difficult logic
*/

//maximum and minimum element in K size window =>question still pending

//Binary Trees ->a non linear data structure

//creation of binary tree
/*
NodeBT *root;
root=NULL;
CreateBinaryTree(root);
*/

// Traversals Using Recursion
/*
BTPreorderTraversal(root);
BTInorderTraversal(root);
BTPostOrderTraversal(root);
*/

//Traversals using Stacks and Queues
NodeBT* root=NULL;
CreateBinaryTree(root);
BTInorderTraversalUsingStack(root);

//Traversals
/*
NodeBT *root=NULL;
CreateBinaryTree(root);
vector<vector<int>> ans=LevelOrderTraversal(root);
Print2Dvector(ans);
*/

// Number of leaf Nodes in BT
/*
NodeBT *root=NULL;
CreateBinaryTree(root);
int count=0;
NoOfLeafNodes(root,count);
cout<<count<<endl;
*/

//Height of BT
/*
NodeBT *root=NULL;
CreateBinaryTree(root);
int height=HeightOfBT(root);
cout<<height<<endl;
*/

//Diameter of a BT
/*
NodeBT* root=NULL;
CreateBinaryTree(root);
int diameternaive=DiameterOfBTNaive(root);
pair<int,int> diameterbest=DiameterOfBTBest(root);
cout<<diameternaive<<endl;
cout<<diameterbest.first<<endl;
*/

//Check for balanced tree
/*
NodeBT *root=NULL;
CreateBinaryTree(root);
bool checknaive=CheckBalancedBTNaive(root);
pair<int,bool> checkbest=CheckBalancedBTBest(root);
cout<<checknaive<<endl;
cout<<checkbest.second<<endl;
*/

//Check Identical trees or not
/*
NodeBT *root1,*root2;
root1=NULL;
root2=NULL;
CreateBinaryTree(root1);
CreateBinaryTree(root2);
bool check=CheckIdenticalTrees(root1,root2);
cout<<check<<endl;
*/

//Sum tree
/*
NodeBT* root=NULL;
CreateBinaryTree(root);
pair<int,bool> sumtree=BTSumTree(root);
cout<<sumtree.second<<endl;
*/

//ZigZag Traversal
/*
NodeBT *root=NULL;
CreateBinaryTree(root);
vector<vector<int>> vec;
vector<int> ans=BTZigZagTraversal(root);
Printvector(ans);
*/

//Boundary Traversal
/*
NodeBT* root=NULL;
CreateBinaryTree(root);
vector<int> ans;
BTBoundaryTraversalLeft(root,ans);
BTBoundaryTraversalLeaf(root->left,ans);
BTBoundaryTraversalLeaf(root->right,ans);
BTBoundaryTraversalRight(root->right,ans);
Printvector(ans);
*/

//Vertical Order Traversal
/*
NodeBT* root=NULL;
CreateBinaryTree(root);
VerticalOrderTraversal(root);
*/

//Top view
/*
NodeBT* root=NULL;
CreateBinaryTree(root);
TopViewOfBT(root);
*/

//Bottom View
/*
NodeBT* root=NULL;
CreateBinaryTree(root);
BottomViewOfBT(root);
*/

//Sum of nodes on the longest path of a tree
/*
NodeBT* root=NULL;
CreateBinaryTree(root);
int ansheight=0;
int anssum=0;
int tempheight=0;
int tempsum=0;
BTLongestBloodline(root,ansheight,anssum,tempheight,tempsum);
cout<<anssum;
*/

//LCA of 2 nodes
/*
NodeBT* root=NULL;
CreateBinaryTree(root);
int val1,val2;
cout<<"Enter Node 1 for LCA"<<"\n";
cin>>val1;
cout<<"Enter Node 2 for LCA"<<"\n";
cin>>val2;
NodeBT* ans=LCAOfBT(root,val1,val2);
cout<<ans->data;
*/

//K Sum path
/*
NodeBT* root=NULL;
CreateBinaryTree(root);
int k;
cout<<"Enter the value of K"<<"\n";
cin>>k;
int ans=0;
vector<int> vec;
KSumPath(root,vec,k,ans);
*/

//Kth Ancestor 
/*
NodeBT* root=NULL;
CreateBinaryTree(root);
int k,val1,val2;
cout<<"Enter the value of k"<<"\n";
cin>>k;
cout<<"Enter node 1 for lca"<<"\n";
cin>>val1;
NodeBT* ans=KthAncestor(root,val1,k);
cout<<ans->data;
*/

//Create BT from preorder and inorder traversal
/*
NodeBT* root=NULL;
int n;
cout<<"Enter number of nodes"<<"\n";
cin>>n;
vector<int> in(n);
vector<int> pre(n);
cout<<"Enter values of inorder traversal"<<"\n";
map<int,int> m;
for(int i=0; i<n; i++)
{
    cin>>in[i];
    m[in[i]]=i;
}
cout<<"Enter values of preorder traversal"<<"\n";
for(int i=0; i<n; i++)
    cin>>pre[i];

int preorderindex=0;
root=BTFromInorderAndPreorder(0,in.size()-1,preorderindex,m,in,pre);
BTPostOrderTraversal(root);
*/

//Create BT from postorder and inorder traversal
/*
NodeBT* root=NULL;
int n;
cout<<"Enter number of nodes"<<"\n";
cin>>n;
vector<int> in(n);
vector<int> post(n);
cout<<"Enter values of inorder traversal"<<"\n";
map<int,int> m;
for(int i=0; i<n; i++)
{
    cin>>in[i];
    m[in[i]]=i;
}
cout<<"Enter values of postorder traversal"<<"\n";
for(int i=0; i<n; i++)
    cin>>post[i];

int postorderindex=post.size()-1;
root=BTFromInorderAndPostorder(0,in.size()-1,postorderindex,m,in,post);
BTPreorderTraversal(root);
*/

//BSTCreation
/*
NodeBT* root=NULL;
CreateBinarySearchTree(root);
BTInorderTraversal(root);
*/

//Search In BST
/*
NodeBT* root=NULL;
CreateBinarySearchTree(root);
cout<<"Enter the value to search in BST"<<"\n";
int val;
cin>>val;
SearchInBST(root,val);
*/

//Deletion In BST
/*
NodeBT* root=NULL;
CreateBinarySearchTree(root);
int x;
cout<<"Enter value to delete"<<"\n";
cin>>x;
root=DeletionInBST(root,x);
BTInorderTraversal(root);
*/

//Validate BST
/*
NodeBT* root=NULL;
CreateBinaryTree(root);
int min,max;
min=INT_MIN;
max=INT_MAX;
bool ans=ValidateBST(root,min,max);
cout<<ans;
*/

//Kth smallest element in BST
/*
NodeBT* root=NULL;
CreateBinarySearchTree(root);
int k;
cout<<"Enter value of K"<<"\n";
cin>>k;
int ans;
KthSmallestElementInBST(root,k,ans);
cout<<ans;
*/

//Find Inorder Predecessor and Successor of BST
/*
NodeBT* root=NULL;
CreateBinarySearchTree(root);
int pre,suc;
pre=root->data;
suc=root->data;
int key;
cout<<"Enter value of key"<<"\n";
cin>>key;
PredecessorAndSuccessorOfNodeInBST(root,pre,suc,key);
cout<<"Predecessor is "<<pre<<endl<<"Successor is "<<suc<<"\n";
*/

//LCA In BST
/*
NodeBT* root=NULL;
CreateBinarySearchTree(root);
int val1,val2;
cout<<"Enter value of val1 and val2"<<"\n";
cin>>val1>>val2;
NodeBT* ans=LCAInBST(root,val1,val2);
cout<<ans->data;
*/

//Two Sum IN BST
/*
NodeBT* root=NULL;
vector<int> vec;
CreateBinarySearchTree(root);
int target;
cout<<"Enter the value of target"<<"\n";
cin>>target;
TwoSumBST(root,vec);
int i,j;
i=0;
j=vec.size()-1;
int check=0;
while(i<j)
{
    if(vec[i]+vec[j]==target)
    {
        check=1;
        cout<<"Target value found"<<"\n";
        break;
    }
    else if(vec[i]+vec[j]>target)
        j--;
    else
        i++;
}
if(check!=1)
    cout<<"Target value not found";
*/

//Inorder to BST
/*
NodeBT* root=NULL;
int n;
cout<<"Enter number of elements"<<"\n";
cin>>n;
vector<int> in(n);
for(int i=0; i<n; i++)
    cin>>in[i];

root=InorderToBST(in,0,n-1);
BTInorderTraversal(root);
*/

//merge 2 BST
/*
NodeBT* root=NULL;
int n1,n2;
cout<<"Enter the no. of elements in n1 and n2"<<endl;
cin>>n1>>n2;
vector<int> in1(n1),in2(n2),inans(n1+n2);
for(int i=0; i<n1; i++)
    cin>>in1[i];
for(int i=0; i<n2; i++)
    cin>>in2[i];

int i=0,j=0;
int k=0;
while(i<n1 && j<n2)
{
    if(in1[i]<in2[j])
        inans[k++]=in1[i++];
    else if(in1[i]>in2[j])
        inans[k++]=in2[j++];
    else
    {
        inans[k++]=in1[i++];
        inans[k++]=in2[j++];
    }
}
while(i<n1)
    inans[k++]=in1[i++];
while(j<n2)
    inans[k++]=in2[j++];

root=Merge2BST(inans,0,n1+n2-1);
BTInorderTraversal(root);
*/



return 0;
}

