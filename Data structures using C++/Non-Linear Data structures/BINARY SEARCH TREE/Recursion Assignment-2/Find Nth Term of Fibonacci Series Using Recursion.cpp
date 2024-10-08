
#include <iostream>
using namespace std;

void fun(int n,int t1,int t2)
{
    int temp;
    temp=t1+t2;
    if(n==1)
    {
        cout<<"Nth Term:"<<temp<<" ";
        return;
    }
    t1=t2;
    t2=temp;
    fun(n-1,t1,t2);
}

int main() 
{
   fun(10,1,0);
   return 0;
}