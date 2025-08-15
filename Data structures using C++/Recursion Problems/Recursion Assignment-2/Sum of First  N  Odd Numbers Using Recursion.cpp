#include <iostream>
using namespace std;

int fun(int n,int s)
{
    if(n==1)
    {
        return s ;
    }
    return(s+fun(n-1,s+2));
    
}


int main() 
{
    int s;
    s=fun(5,1);
    cout<<s;
    return 0;
}