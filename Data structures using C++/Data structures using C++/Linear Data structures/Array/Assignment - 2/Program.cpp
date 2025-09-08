#include<iostream>
using namespace std;

class Array
{
int capacity;
int lastIndex;
int *ptr;
public:	

void sort()
{
	int i,j,k;
	for(i=0;i<=lastIndex;i++)
	{
     for(j=0;j<lastIndex;j++)
    	{
		   if(ptr[j]>ptr[j+1])
		   {
		   	k=ptr[j];
		   	ptr[j]=ptr[j+1];
		   	ptr[j+1]=k;
		   }
	    }
	}
}
Array(int size)
{
	capacity=size;
	ptr=new int[capacity];
	lastIndex=-1;
}
bool IsEmpty()
{
	if(lastIndex==-1)
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
	if(lastIndex==capacity-1)
	{
	cout<<"Error:Array is Full can not Append\n";
	}
	else
	{
	lastIndex++;
	ptr[lastIndex]=val;
    }
}

void insert(int val,int index)
{
	if(index<0 || index>lastIndex)
	{
		cout<<"Error:Invalid Index\n";
	}
	else
	{
	int i=lastIndex;
	for(i;i>=index;i--)
	{
		ptr[i+1]=ptr[i];
	}
	ptr[index]=val;
	lastIndex++;
    }
}

void edit(int val,int index)
{
	if(index<0 || index>lastIndex)
	{
		cout<<"Error:Invalid Index\n";
	}
	else
	{
	ptr[index]=val;
    }
}
void Delete(int index)
{
	if(index<0 || index>lastIndex)
	{
		cout<<"Error:Invalid Index\n";
	}
	else
	{
	int i=index;
	for(i;i<=lastIndex;i++)
	{
		ptr[i]=ptr[i+1];
	}
	lastIndex--;
    }
}

bool IsFull()
{
	if(lastIndex==capacity-1)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}

int get(int index)
{
	int val;
	if(index<0 || index>lastIndex)
	{
		cout<<"Error:Invalid Index\n";
		return(0);
	}
	else
	{
	int i=0;
	for(i=0;i<=index;i++)
	val=ptr[i];
	return(val);
    }
}

int count()
{
	if(lastIndex<0)
	{
	  return(0);
	}
	else
	{
      return(lastIndex+1);
    }
}

int search(int val)
{
	int i=0;
	for(i=0;i<=lastIndex;i++)
    {
    	if(ptr[i]==val)
    	{
    		return(i);
    		break;
		}
	}
	return(-1);
}

void print()
{
	int i=0;
	while(i<=lastIndex)
	{
		cout<<"["<<ptr[i]<<"]"<<" ";
		i++;
	}
	cout<<endl;
}
~Array()
{
	delete ptr;
}

int greatest()
{
	int val,i;
	Array temp(capacity);
	while(i<=lastIndex)
	{
		temp.append(ptr[i]);
		i++;
	}
	temp.sort();
	val=temp.get(lastIndex);
    return(val);
}

int smallest()
{
	int val,i;
	Array temp(capacity);
	while(i<=lastIndex)
	{
		temp.append(ptr[i]);
		i++;
	}
	temp.sort();
	val=temp.get(0);
    return(val);
}

int sum()
{
	int i=0,total=0;
	while(i<=lastIndex)
	{
		total=total+ptr[i];
		i++;
	}
	return(total);
}

int Average()
{
	int s,e,total;
    s=sum();
    e=count();
    total=s/e;
	return(total);
}

void rotate_array()
{
	int  temp,i;
	temp=ptr[lastIndex];
    for(i=lastIndex;i>0;i--)
    {
      ptr[i]=ptr[i-1];
	}
	ptr[0]=temp;
}

void removeduplicate()
{
    int temp[capacity];
	int i=0,j=0,k;
	while(i<=lastIndex)
	{
		temp[i]=ptr[i];
		i++;
	}
	
	for(j=0;j<=lastIndex;j++)
	{
		for(i=0;i<lastIndex;i++)
		{
		   if(temp[i]>temp[i+1]) 
		   {
		   	   k=temp[i];
		   	   temp[i]=temp[i+1];
		   	   temp[i+1]=k;
		   } 
		}
	}
	
	for(i=0;i<lastIndex;i++)
	{
		if(temp[i]==temp[i+1])
		{
			temp[i+1]=temp[i+1+1];
		}
	}
    lastIndex--;
    i=0;
	while(i<=lastIndex)
	{
		ptr[i]=temp[i];
		i++;
	}
}

int secondgreatest()
{
	int val,i;
	Array temp(capacity);
	while(i<=lastIndex)
	{
		temp.append(ptr[i]);
		i++;
	}
	temp.sort();
	val=temp.get(lastIndex-1);
    return(val);
}
void swap(int index1,int index2)
{
	int temp;
    if(index1 > lastIndex  && index1 > lastIndex)
    {
     	  cout<<"Error:Invalid Index\n";
	}
	else if(index2 > lastIndex  && index2 > lastIndex)
    {
     	  cout<<"Error:Invalid Index\n";
	}
	else	
	{
		temp=ptr[index1];
		ptr[index1]=ptr[index2];
		ptr[index2]=temp;
	}
	 
}
};


int main()
{
	Array a1(5);
	a1.append(11);
		a1.append(11);
			a1.append(15);
				a1.append(9);
					a1.append(10);
				   	a1.print();
				   	a1.removeduplicate();
				   	a1.print();
				   	a1.swap(3,0);
				   	a1.print();
				   
	return 0;
}