#include<iostream>
using namespace std;


class DynArray
{
	public:
	int capacity,lastindex;
	int *ptr;
	
	DynArray(int size)
	{
	   capacity=size;
	   ptr=new int[capacity];
	   lastindex=-1;
	}
	
	void doubleArray()
	{
		int *temp;
		capacity=capacity*2;
		temp=new int[capacity];
		for(int i=0;i<=lastindex;i++)
		{
			temp[i]=ptr[i];
		}
		delete []ptr;
		ptr=temp;

	}
	void halfArray()
	{
		int *temp;
		capacity=capacity/2;
		temp=new int[capacity];
		for(int i=0;i<=lastindex;i++)
		{
			temp[i]=ptr[i];
		}
		delete []ptr;
		ptr=temp;
	}
    void append(int val)
	{
		if(lastindex==capacity-1)
		{
		    doubleArray();
		}
	    lastindex++;
	    ptr[lastindex]=val;
	}
	void insert(int index,int val)
	{
		if(index<0 || index>lastindex+1)
		{
			cout<<"Invalid Index\n";
		}
		else
		{
		    if(lastindex==capacity-1)
		    {
		    	doubleArray();
			}
			for(int i=lastindex;i>=index;i--)
			{
				ptr[i+1]=ptr[i];
			}
			ptr[index]=val;
			lastindex++;
		}
	}
	
	void Delete(int index)
	{
		if(index<0 || index>lastindex+1)
		{
			cout<<"Invalid Index\n";
		}
		else
		{
		    if(lastindex==(capacity/2)-1 && capacity>1)
		    {
		       halfArray();
			}
			for(int i=index;i<=lastindex;i++)
			{
				ptr[i]=ptr[i+1];
			}
			lastindex--;
		}
	}
	
	void print()
	{
		int i=0;
		while(i<=lastindex)
		{
			cout<<"["<<ptr[i]<<"]"<<" ";
			i++;
		}
	}
	int currentcapacity()
	{
		return(capacity);
	}
	bool IsEmpty()
	{
		if(lastindex==-1)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	bool IsFull()
	{
		if(lastindex==capacity-1)
		{
			return(true);
		}
		else
		{
			return(false);
		}
	}
	int get_element(int index)
	{
		if(index>lastindex || index<0)
		{
			return(NULL);
			cout<<"Invalid Index\n";
		}   
		else                     
		{
			return(ptr[index]);
		}
	}
	int count()
	{
		return(lastindex+1);
	}
	int find(int val)
	{
		int i=0;
		for(i;i<lastindex;i++)
		{
			if(ptr[i]==val)
			{
				return(i);
				break;
			}
		}
		return(-1);
	}
	
	void edit(int index, int val)
	{
		int i=0;
		if(index>lastindex || index<0)
		{
			cout<<"Invalid Index\n";
		}
		else
		{
		for(i=0;i<index;i++);
		ptr[i]=val;
     	}
	}
	~DynArray()
	{
		delete []ptr;
    }
};

int main()
{
 DynArray d1(4);
 d1.append(1);
  d1.append(2);
   d1.append(3);
    d1.append(4);    
	d1.append(5);
    d1.print();
}