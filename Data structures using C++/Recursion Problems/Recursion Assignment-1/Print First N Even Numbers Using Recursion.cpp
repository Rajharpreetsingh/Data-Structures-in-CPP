#include <iostream>
using namespace std;

void fun(int x,int y)
{
    if(x==1)
    {
        cout<<y<<" ";
        return ;
    }
    cout<<y<<" ";
    fun(x-1,y+2);
}


int main() 
{
    fun(5,2);
    return 0;
}