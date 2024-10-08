
#include <iostream>
using namespace std;

int fun(int n)
{
    if(n==0)
    {
        return(n);
    }
    return(n%10+fun(n/10));
}
int main()
{
    int s;
    s=fun(999999);
    cout<<s;
    return 0;
}