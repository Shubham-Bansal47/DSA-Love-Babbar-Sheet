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
//arr[i]=*(arr+i) Amazing concept
*/

//reference variables 
/*
Giving different names to same variable
int i=5;
int& j=i;
j++ will also give 6 and i++ will also give 6
Comes the concept of Pass by value and Pass by reference (Must Do)
*/

//dynamic memory allocation
/*
stack memory(Static memory allocation)<Heap memory(Dynamic allocation)
Stack memory gets free after completion of loop but not Heap memory
int n=5;
int* arr=new int[n]; //creates dynamic array of size 5 
int* i=new int; //creates dynamic integer (new int returns address which can be dereferenced with * operator)
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