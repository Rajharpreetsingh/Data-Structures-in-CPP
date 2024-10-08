#include<iostream>
#include<string.h>
using namespace std;

class node
{
public:
int data;
node *next;
};


class stack 
{
	public:
	node *top;
    stack()
	{
		top=NULL;
	}
	stack(stack &s1)
	{
      node *t1,*t2,*n;
	  t1=s1.top;
	  t2=NULL;
	  while(t1!=NULL)
	  {
		n = new node;
		n->data=t1->data;
		if(top==NULL)
		{
			top=n;
		}
		else
		{
            t2->next=n;
		}
        t1=t1->next;
		t2=n;
	  }
	  if(t2!=NULL)
	  {
	  t2->next=NULL;
	  }
	}
	void push(int val)
	{
        node *n= new node;
		n->data=val;
		n->next=NULL;
		if (top==NULL)
		{
			top=n;
		}
		else
		{
			n->next=top;
			top=n;
		}
		
	}
	void pop()
	{
		if(top==NULL)
		{
			cout<<"Error:Stack UnderFlow\n";
		}
		else
		{
		node *t=top;
        top=top->next;
		delete t;
		}
	}

    

    
	void print()
	{
		if(top==NULL)
		{
          cout<<"Error:Stack is Empty Can't Print\n";
		}
		else
		{
		node *t;
		t=top;
		while(t!=NULL)
		{
			cout<<"["<<t->data<<"]"<<endl;
			t=t->next;
		}
		cout<<endl;
		}
	}
	int peek()
	{
		    return(top->data);
	}
	~stack()
	{
		while(top!=NULL)
		{
           pop();
		}		
	}

    void reverse()
	{
		int temp;
		node *t1,*t2,*t3;
		if(top==NULL)
		{
			cout<<"Error:Stack is Empty can't Reverse\n";
		}
		else if(top->next==NULL)
		{
			cout<<"Error:Stack Has Only One Element Can't Reverse\n";
		}
		else if(top->next->next==NULL)
		{
			temp=top->data;
			top->data=top->next->data;
			top->next->data=temp;
		}
		else
		{
			t1=top;
			t2=top->next;
			t3=top->next->next;
			t1->next=NULL; 
			while(t2!=NULL)
			{
                t2->next=t1;
                t1=t2;
				t2=t3;
				if(t3==NULL)
				{
					continue;
				}
				t3=t3->next;
			}
			top=t1;
		}
	}
	int Length(int n)
	{
	    int i=0;
	    while(n!=0)
	    {
	        i++;
	        n=n/10;
	    }
	    return i;
	}
	bool IsPlaindrome(int n)
	{
		stack s;
       int length=Length(n);
	   int i=length/2;
	   while(i!=0)
	   {
		s.push(n%10);
		n=n/10;
		i--;
	   }
	   if(length%2)
	   {
		n=n/10;
	   }
	   while(n!=0)
	   {
		 if(n%10==s.peek())
		 {
			s.pop();
			n=n/10;
		 }
		 else
		 {
			return false;
		 }
	   }
	   return true;
	}

	bool isPlaindrome(int n)
	{
	  stack s1,s2;
	  node *t1,*t2;

	  while(n!=0)
	  {
		s1.push(n%10);
		s2.push(n%10);
		n=n/10;
	  }
	   s2.reverse();
	   t1=s1.top;
	   t2=s2.top;
	  while(t1!=NULL && t2!=NULL)
	  {
	      if(t1->data!=t2->data)
	      {
	          return(false);
	      }
	      t1=t1->next;
	      t2=t2->next;
	  }
	  return(true);
	}
    
};




int main()
{
    
	stack s1;

	 if(s1.isPlaindrome(1021))
	 {
	     cout<<"Plaindrome hai\n";
	 }
	 else
	 {
	     cout<<"Plaindrome Nahi hai\n";
	 }
	 
	 
	      
	  return 0;
}