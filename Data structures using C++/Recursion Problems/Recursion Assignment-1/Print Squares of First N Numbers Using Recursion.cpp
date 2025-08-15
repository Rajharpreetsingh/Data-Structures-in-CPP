#include <iostream>
using namespace std;

void fun(int n)
{
    if(n==1)
    {
        cout<<n<<" ";
        return ;
    }
    fun(n-1);
    cout<<n*n<<" ";
}





int main() 
{
    fun(5);
    return 0;
}