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
    cout<<*i.first<<" "<<*i.second<<endl;
    cout<<i->first<<" "<<i->second<<endl;
*/

//Algorithms
/*
int val=count(vec.begin(),vec.end(),2);
int val=accumulate(vec.begin(),vec.end(),0);
int val=*max_element(vec.begin(),vec.end());
int val=*min_element(vec.begin(),vec.end());
cout<<binary_search(vec.begin(),vec.end(),5); gives 1 if present otherwise 0
cout<<max(a,b);
cout<<min(a,b);
swap(a,b);
sort(vec.begin(),vec.end());
reverse(vec.begin(),vec.end());
*/