#include<iostream>
using namespace std;

class node
{
	public:
		node *prev;
		int data;
		node *next;
};
class DLL
{
	public:
		node *start;
		DLL()
		{
			start=NULL;
		}
	    void startinsert(int val)
	    {
	    	node *n=new node;
	    	n->data=val;
	    	n->next=NULL;
	    	n->prev=NULL;
	    	if(start==NULL)
	    	{
	    		start=n;
			}
			else
			{
				n->next=start;
				start->prev=n;
				start=n;
				start->prev=NULL;
			}
		}
		
		void endstart(int val)
		{
			node *t=start;
			node *n=new node;
			n->data=val;
			n->next=NULL;
	    	n->prev=NULL;
			if(start==NULL)
			{
				start=n;
			}
			else
			{
				while(t->next!=NULL)
				{
					t=t->next;
				}
				n->prev=t;
				t->next=n;
			}
		}
		
		node* search(int val)
		{
			node *t=start;
			while(t!=NULL)
			{
				if(t->data==val)
				{
					return(t);
				}
				t=t->next;
			}
            return(NULL);
		}
		
		void insertafter(node *backnode,int val)
		{
			if(start==NULL)
			{
				cout<<"Error:List is Empty can not insert\n";
			}
			else if(backnode==NULL)
			{
			  cout<<"Error:Searched Node not found\n";
			}
			else
			{
			node *n=new node;
			n->data=val;
			n->next=NULL;
	    	n->prev=NULL;
			n->next=backnode->next;
			n->prev=backnode;
			backnode->next=n;
			}
		}
		
		void deletefirst()
		{
			node *t=start;
			if(start==NULL)
			{
			 cout<<"Error:List is Empty can not delete\n";
			}
			else if(start->next==NULL)
			{
				start=NULL;
				delete t;
			}
			else
			{
			    start=start->next;
			    start->prev=NULL;
			    delete t;
			}
		}
		void deletelast()
		{
			node *t=start,*t2;
			if(start==NULL)
			{
			 cout<<"Error:List is Empty can not delete\n";
			}
			else if(start->next==NULL)
			{
				start=NULL;
				delete t;
			}
			else
			{
			    while(t->next!=NULL)
			    {
			    	t=t->next;
				}
				t2=t->prev;
				t2->next=NULL;
				delete t;
			}
		}
		void Delete(node *n)
		{
			node *t;
			if(start==NULL)
			{
		      	 cout<<"Error:List is Empty can not delete\n";
			}
			else if(start->next==NULL)
			{
				t=start;
				start=NULL;
				delete t;
			}
			else if(n==NULL)
			{
				 cout<<"Error:Searched Node not found\n";
			}
			else if(n==start)
			{
				deletefirst();
			}
			else if(n->next==NULL)
			{
				deletelast();
			}
			else
			{
				t=n->prev;
				t->next=n->next;
				n->next->prev=t;
				delete t;	
			}
		}
		~DLL()
		{
			while(start!=NULL)
			{
				deletefirst();
			}
		}
		void print()
		{
			node *t=start;
			while(t!=NULL)
			{
				cout<<"["<<t->data<<"]"<<"<-->";
				t=t->next;
			}
			cout<<endl;
		}
};



int main()
{
	DLL d1;
	d1.endstart(1);
	d1.endstart(2);
	d1.endstart(3);
	d1.endstart(4);
    d1.print();
    d1.insertafter(d1.search(4),5);
    d1.print();
    d1.Delete(d1.search(5));
    d1.print();
    d1.Delete(d1.search(1));
    d1.print();
    d1.Delete(d1.search(3));
    d1.print();
    return(0);
}