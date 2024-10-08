#include <iostream>
using namespace std;

void fun(int x,int y)
{
    if(x==0)
    {
        return ;
    }
    fun(x-1,y+2);
    cout<<y<<" ";
}





int main() 
{
    fun(5,1);
    return 0;
}