#include<iostream>
using namespace std;


// This Heap is Max Heap

class Heap
{
  public:
  int index;
  int *Array;
  int size;

  Heap(int s)
  {
	index=-1;
	Array=new int[s];
	size=s;
  }
  

  void insert(int val)
  {
      int parent,i;
      
	  if(index==-1)
	  {
		  index++;
          Array[index]=val;
	  }
	  else
	  {
	      index++;
          i=index;
          Array[i]=val;
	      while(i>0)
	      {
	      parent=(i - 1) / 2;
	      if(val>Array[parent])
	      {
	          swap(&Array[i],&Array[parent]);
	          i=parent;
	      }
	      else
	      {
	          break;
	      }
	      
	      }   
		}
  }

  void heapify(int i)
  {
	int l,r,big;

	l=(2*i)+1;
	r=(2*i)+2;
	big=i;

	if(l<=index  &&  Array[l]>Array[big])
	{
          big=l;
	}
	if(r<=index  &&  Array[r]>Array[big])
	{
          big=r;
	}
	if(big!=i)
	{
		swap(&Array[i],&Array[big]);
		heapify(big);
	}

  }




  void Delete(int i)
  {
	 int j=0;	
	 if(i>index || i < 0)
	 {
		cout<<"Can't Delete Searched Value Not Found";
	 }
	 else
	 {
	     swap(&Array[i],&Array[index]);
		 index--;  
		 heapify(i);
	 }
      
     
  }






  
  void swap(int *x,int *y)
  {
    int z;
	 z=*x;
    *x=*y;
	*y=z;
  }

  
   void print()
   {
	int i=0;
	if(index==-1)
	{
		cout<<"Error: Heap is Empty Can't Print"<<endl;
	}
	else
	{
	while(i<=index)
	{
		cout<<"["<<Array[i]<<"]"<<" ";
		i++;
	}
	cout<<endl;
	}
   }

   ~Heap()
   {
	while(index!=-1)
	{
		Delete(0);
	}
   }

};




int main()
{
Heap h1(6);

h1.insert(90);
h1.insert(70);
h1.insert(50);
h1.insert(30);
h1.insert(60);

h1.print();
h1.Delete(0);
h1.print();




return 0;
}



 