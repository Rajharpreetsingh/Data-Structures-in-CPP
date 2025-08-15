#include <iostream>
using namespace std;

int HCF(int a,int b)
{
  int small,big;
  if(a<b)
  {
    small=a;
    big=b;
  }
  else
  {
    small=b;
    big=a;
  }
  if(big%small==0)
  {
      return(small);
  }
  else
  {
    HCF(small,big%small);
    
  }
}

int main() 
{
   int h;
   h=HCF(24,60);
   cout<<"HCF is:"<<h;
   return 0;
}