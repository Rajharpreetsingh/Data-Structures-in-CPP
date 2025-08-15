#include <iostream>
using namespace std;

void fun(int n)
{
    if(n==1)
    {
        cout<<n<<" ";
        return ;
    }
    cout<<n*n*n<<" ";
    fun(n-1);
    
}





int main() 
{
    fun(5);
    return 0;
}