#include<iostream>

using namespace std;







int main()
{
    int size,tmp;
    char x,y;
    string list;
    cout<<"Enter a String:";
    cin>>list;
    size=list.length(); 
    int Hash[26];
    for(int i=0;i<26;i++)
    {
      Hash[i]=0;
    }


    for(int i=0;i<size;i++)
    {
        tmp=list.at(i);

        cout<<tmp<<" "<<endl;
        Hash[tmp-97]+=1;
    }



    x='a';


    for(int i=0;i<26;i++)
    {
      
      y=(char)x+i;
      cout<<"Occurence of Character  "<<y<<" is "<<Hash[i]<<" times"<<endl;

    }
  


   
          
    return 0;
}
