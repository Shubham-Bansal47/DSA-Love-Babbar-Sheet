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
for(int a=0, b=1; a<n && b<=n; a++,b++) syntax for double parameteres
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

bool checkpalindromeusingrec(string& str,int s,int e)
{
    if(s>e)
        return true;
    if(str[s]!=str[e])
        return false;
    
    return checkpalindromeusingrec(str,s+1,e-1);
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

void printarray(int arr[],int n) //if(you put n=1 then default value will start from 1 if not initialised)
{
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    return;
}

void printvector(vector<int> &temp)
{
    for(int i=0; i<temp.size(); i++)
        cout<<temp[i]<<" ";

    return;
}

void print2Dvector(vector<vector<int>>& ans)
{
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        
        cout<<endl;
    }

    return;
}

void printstrings(vector<string>& ans)
{
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
        cout<<endl;
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
// time complexity O -> Upper bound theta -> avg case omega -> lower bound

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
printarray(arr,n);
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
printarray(arr,n);
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
printarray(arr,n);
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
printarray(arr,n);
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
printarray(arr,n);
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
printvector(temp);
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
printvector(ans);
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

//wave print in 2D array
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

//spiral printing
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
int *p=&a;
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
cout<<checkpalindromeusingrec(str,s,e)<<endl;
int a=3,b=3;
cout<<getpower(a,b)<<endl;
*/

//mergesort
/*
int n=7;
int arr[n]={6,3,5,1,2,8,0};
mergesort(arr,0,n-1);
printarray(arr,n);
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
print2Dvector(ans);
*/

//subsequences of a string
/*
string str="abc";
string temp="";
vector<string> ans;
subsequenceofstring(str,temp,ans,0);
sort(ans.begin(),ans.end());
printstrings(ans);
*/

//permutations of a string
/*
string str="abc";
vector<string> ans;
permutationsofstring(str,ans,0);
sort(ans.begin(),ans.end());
printstrings(ans);
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
printstrings(ans);
*/



return 0;
}