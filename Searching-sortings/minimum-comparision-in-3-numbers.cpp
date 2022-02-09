#include<bits/stdc++.h>
using namespace std;

int middle(int A, int B, int C){
        if((A>B && B>C) || (A<B &&B<C))
        {
            return B;
        }
        else if((B>A && A>C) || (B<A && A<C))
        {
            return A;
        }
        else
        {
            return C;
        }
    }

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<middle(a,b,c);
    
    return 0;
}