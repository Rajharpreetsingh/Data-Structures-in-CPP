#include<iostream>
using namespace std;

class Array
{
int capacity;
int lastindex;
int *ptr;
public:	

void operator=(Array &arr)
{
  capacity=arr.capacity;
  lastindex=arr.lastindex;
  if(ptr!=NULL)
  {
  delete [] ptr;
  }
  ptr=new int[capacity];
  
  for(int i=0;i<=lastindex;i++)
  {
	ptr[i]=arr.ptr[i];
  }

}
Array(int cap)
{
	capacity=cap;
	lastindex=-1;
	ptr=new int[cap];
}
Array(Array &arr)
{
  capacity=arr.capacity;
  lastindex=arr.lastindex;
  ptr=new int[capacity];
  for(int i=0;i<=lastindex;i++)
  {
	ptr[i]=arr.ptr[i];
  }
}
int GetCapacity()
{
 return(capacity);
}
bool isFull()
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

bool isEmpty()
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

void append(int val)
{
	if(lastindex==capacity-1)
	{
		cout<<"Error:Array is full can not append\n";
	}
	else
	{
		lastindex++;
		ptr[lastindex]=val;
	}
}

void insert(int index,int val)
{
	int i;
	if(lastindex==capacity-1)
	{
	 cout<<"Error:Array is full can not insert\n";
	}
	else if(index>lastindex+1 || index<0)
	{
	 cout<<"Error:Invalid index can not insert\n";
	}
	else
	{
		i=lastindex;
		for(i;i>=index;i--)
		{
			ptr[i+1]=ptr[i];
		}
		ptr[index]=val;
		lastindex++;	
	}	
}




void edit(int index,int val)
{
	if(index>=0 && index<=lastindex)
	{
		ptr[index]=val;
	}
}

void Delete(int index)
{
	int i;
	if(lastindex==-1)
	{
		cout<<"Error:Array is Empty can not Delete \n";
	}
	else if(index<0 || index>lastindex)
	{
		cout<<"Error:Invalid index can not Delete \n";
	}
	else
	{
		for(i=index;i<lastindex;i++)
		{
			ptr[i]=ptr[i+1];
		}
		lastindex--;
	}
}

int get(int index)
{
	if(index<=lastindex || index>=0)
	{
		return(ptr[index]);
	}
	else
	{
		cout<<"Error:Invalid index\n";
	}
}

int count()
{
	return(lastindex+1);
}

int find(int val)
{
	int i;
	for(i=0;i<=lastindex;i++)
	{
		if(ptr[i]==val)
		{
			return(i);
		}
		return(-1);
	}
}
void print()
{
	int i;
	for(i=0;i<=lastindex;i++)
	{
		cout<<"["<<ptr[i]<<"]"<<" ";
	}
	cout<<endl;
}
~Array()
{
    delete []ptr;
}


};


int main()
{
	Array a1(7); int array[7];
	a1.insert(0,1);
	a1.insert(0,2);
	a1.insert(0,3);
	a1.insert(0,4);
	a1.insert(0,5);
	a1.insert(0,6);
	a1.insert(0,17);
	a1.print();
	return 0;
}
