#include<iostream>
#include<vector>

using namespace std;


int main()
{
   vector<int> v;

   vector<int> a(5,1);
   vector<int> last=a;
   for(int i:last)
   {
    cout<<i<<" ";
   }
   cout<<"size:"<<v.capacity()<<endl;
   v.push_back(1);
   cout<<"size:"<<v.capacity()<<endl;
   v.push_back(2);
   cout<<"size:"<<v.capacity()<<endl;
   v.push_back(3);
   cout<<"size:"<<v.capacity()<<endl;
   cout<<"Front:"<<v.front()<<endl;
   cout<<"Back:"<<v.back()<<endl;


   cout<<"Before Pop:"<<endl;
   for(int i=0;i<v.size();i++)
   { 
         cout<<i<<" ";
   }
   cout<<endl;

   v.pop_back();

    cout<<"Before Pop:"<<endl;
     for(int i=0;i<v.size();i++)
   { 
         cout<<i<<" ";
   }
   cout<<endl;

   cout<<"Before Clear size:"<<v.size()<<endl;
   v.clear();
   cout<<"After Clear size:"<<v.size()<<endl;
}