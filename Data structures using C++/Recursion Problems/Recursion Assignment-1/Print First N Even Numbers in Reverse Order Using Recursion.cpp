#include <iostream>
using namespace std;

void fun(int x,int y)
{
    if(x==1)
    {
        cout<<y<<" ";
        return ;
    }
  
    fun(x-1,y+2);
    cout<<y<<" ";
}





int main() 
{
    fun(5,2);
    return 0;
}