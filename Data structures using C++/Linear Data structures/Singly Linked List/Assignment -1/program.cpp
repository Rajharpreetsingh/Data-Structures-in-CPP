#include<iostream>
#include<conio.h>
using namespace std;

class node
{
	public:
	int data;
	node *next;
};

class SLL
{
	public:
	node *start;
	SLL()
	{
		start=NULL;
	}
	
	void startinsert(int val)
	{
		node *newnode= new node;
		newnode->data=val;
		newnode->next=NULL;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			newnode->next=start;
			start=newnode;
		}
	}
	
	void endinsert(int val)
	{
		node *newnode= new node;
		newnode->data=val;
		newnode->next=NULL;
		if(start==NULL)
		{
			start=newnode;
		}
		else
		{
			node *t=start;
			while(t->next!=NULL)
			{
				t=t->next;
			}
			t->next=newnode;
		}
	}
	
	node* search(int val)
	{
		if(start==NULL)
		{
			cout<<"List is Empty can not search\n";
		}
		else
		{
			node *t=start;
			while(t!=NULL)
			{
				if(t->data==val)
				{
					return(t);
					break;
				}
				t=t->next;
			}
			return(NULL);
		}
	}
	
	void insertAfter(node *backnode,int val)
	{
		if(start==NULL)
		{
		  cout<<"List is Empty can not Insert\n";
		}
		else
		{
		node *newnode= new node;
		newnode->data=val;
		newnode->next=backnode->next;
		backnode->next=newnode;
	    }
	}
	
	void deletefirst()
	{
		node *temp;
		if(start==NULL)
		{
		  cout<<"Error:List is Empty can't delete";
		}
		else
		{
			temp=start;
			start=start->next;
			delete temp;
		}
	}
	
	void deletelast()
	{
		node *t;
		if(start==NULL)
		{
		  cout<<"Error:List is Empty can't delete";
		}
		else if(start->next==NULL)
		{
			delete start;
			start=NULL;
		}
		else
		{
			t=start;
			while(t->next->next!=NULL)
			{
				t=t->next;
			}
			delete t->next;
			t->next=NULL;
		}
	}
	
	void deleteAt(node *address)
	{
		node *n;
		if(start==NULL)
		{
		cout<<"Error:List is Empty can't delete";
		}
		else 
		{
	        if(address!=NULL)
	        {
	        	if(start==address)
	        	{
	        	    deletefirst();
				}
				else if(address->next==NULL)
				{
					deletelast();
				}
				else
				{
					n=start;
					while(n->next!=address)
					{
						n=n->next;
					}
					n->next=address->next;
					delete address;
				}
			}
	    }
		
	}
	
	void print()
	{
		if(start==NULL)
		{
			cout<<"[start]->[NULL]\n\n";
		}
		else
		{
		node *t=start;
		cout<<"[start]->";
		while(t!=NULL)
		{
		  cout<<"["<<t->data<<"]"<<"-->";
		  t=t->next;
		}
		cout<<"[NULL]\n\n";
	    }
	}
	~SLL()
	{
		while(start!=NULL)
		{
		   deletefirst();
		}
	}
};



int main()
{
	SLL s1;

s1.endinsert(1);
s1.endinsert(2);
s1.endinsert(3);
s1.endinsert(4);
s1.endinsert(5);

	s1.print();
	s1.deletelast();
	s1.print();
}