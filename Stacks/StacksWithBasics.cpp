#include<bits/stdc++.h>
using namespace std;

//Sare stack questions ka ek hi concept h 
//pehle sare elements pop karo fir last se sort krna chalu karo jab stack khali ho ya sirf 1 element ho

class Stack{
    public:
        int top;
        int size;
        int *arr;

        Stack(int size)
        {
            this->size=size;
            arr=new int[size];
            this->top=-1;
        }

        void push(int val)
        {
            if((this->top)+1<this->size)
            {
                (this->top)++;
                arr[(this->top)]=val;
            }
            else
                cout<<"Stack is full"<<endl;

            return;
        }

        void pop()
        {
            if(this->top==-1)    
                cout<<"Stack is empty"<<endl;
            else
            {    
                cout<<"Popped "<<arr[this->top]<<"from stack"<<endl;
                this->top--;
            }

            return;
        }

        void peek()
        {
            if(this->top>=0 && (this->top)+1<(this->size))
                cout<<"Peek element is "<<arr[this->top]<<endl;
            else
                cout<<"Out of bounds"<<endl;
        }

        void isempty()
        {
            if((this->top==-1))
                cout<<"It is empty"<<endl;
            else
                cout<<"It is not empty"<<endl;

            return;
        }
};

int main()
{
    cout<<"Enter size of stack?"<<endl;
    int x;
    cin>>x;
    Stack st(x);
    st.push(4);
    st.push(5);
    st.push(3);
    st.push(1);
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.peek();
    st.isempty();

    return 0;
}