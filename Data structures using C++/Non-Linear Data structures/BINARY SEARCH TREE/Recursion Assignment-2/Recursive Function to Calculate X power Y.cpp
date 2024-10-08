#include <iostream>
using namespace std;

int fun(int x,int y)
{
    if(y==1)
    {
        return(x);
    }
    return(x*fun(x,y-1));
}
int main() 
{
   int r;
   r=fun(6,10);
   cout<<r;
   return 0;
}