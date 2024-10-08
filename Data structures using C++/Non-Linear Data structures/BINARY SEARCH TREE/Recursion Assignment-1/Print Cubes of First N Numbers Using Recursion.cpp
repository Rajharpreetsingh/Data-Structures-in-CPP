#include <iostream>
using namespace std;

int fun(int n)
{
    if(n==0)
    {
        return n ;
    }
    return(n+fun(n-1));
    
}


int main() 
{
    int s;
    s=fun(10);
    cout<<s;
    return 0;
}