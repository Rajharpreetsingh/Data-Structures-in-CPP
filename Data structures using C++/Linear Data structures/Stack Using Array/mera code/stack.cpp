#include<iostream>
using namespace std;

class stack 
{
	public:
	int top=-1,*ptr,capacity,min;
	stack(int val)
	{
		 capacity=val;
	     ptr=new int[val];
	}
	void push(int val)
	{
		if(top==capacity-1)
		{
			cout<<"Error:Stack Overflow"<<endl;
		}
		else if(top==-1)
		{
		    top++;
		    ptr[top]=val;
		    min=val;
		}
		else
		{
		   if(val<min)
		   {
			  min=val;
		   }
		   top++;
		   ptr[top]=val;
		   
		}
	}
	
	void pop()
	{
		if(top==-1)
		{
			cout<<"Error:Stack Underflow\n\n";
		}
		else
		{
          int i=0;
		  while(i<top)
		  {
			if(ptr[i]<min)
			{
				min=ptr[i];
				break;
			}
			i++;
		  }
		  top--;
		}
	}

	
	bool stackoverflow()
	{
		if(top==capacity-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool stackunderflow()
	{
		if(top==-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void print()
	{
		int i=top;
		while(i>=0)
		{
			cout<<"["<<ptr[i]<<"]"<<endl;
			i--;
		}
		cout<<"\n";
	}
	void reverse()
	{
		int i=0,j=top;
		int temp;
		while(i<=j)
		{
			temp=ptr[i];
			ptr[i]=ptr[j];
			ptr[j]=temp;
			i++;
			j--;
		}
        i++;
		cout<<"Top ki value:"<<top<<endl;
	}
	int getmin()
	{
	    return(min);
	}
	~stack()
	{
		delete ptr;
	}

};


int main()
{
	stack s1(5);
	s1.push(17);
	s1.push(11);
	s1.push(3);
	s1.push(89);
	s1.push(5);
	s1.print();
    cout<<"value of min is :"<<s1.getmin();

}