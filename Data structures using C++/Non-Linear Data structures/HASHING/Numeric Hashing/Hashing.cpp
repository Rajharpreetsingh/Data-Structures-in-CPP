#include<iostream>
using namespace std;







int main()
{
    int size;
    cout<<"Enter Array Size:";
    cin>>size;
    int Array[size];
    int Hash[size];
    for(int i=0;i<size;i++)
    {
      cout<<"Enter Array Element of Index:"<<i<<" :";
      cin>>Array[i];
      Hash[i]=0;
    }
    for(int i=0;i<size;i++)
    {
      //cout<<"Enter Array Element of Index:"<<i<<" :";
      cout<<Array[i]<<endl;
      Hash[Array[i]]+=1;
    }
    
    for(int i=0;i<size;i++)
    {
      cout<<"Occurence of Element:"<<i<<" is "<<Hash[i]<<"Times"<<endl4;
    }
    
          
    return 0;
}
