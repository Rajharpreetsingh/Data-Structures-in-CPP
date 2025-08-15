#include<iostream>
using namespace std;

class node
{
	public:
	node  *next;
	int data;
	node  *prev;
};

class CDLL
{
	public:
	node *start;
	void startinsert(int val)
	{
		node *n=new node;
		n->data=val;
		if(start==NULL)
		{
			n->next=n;
			n->prev=n;
			start=n;
		}
		else
		{
			n->prev=start->prev;
			n->next=start;	
			start->prev->next=n;
			start->prev=n;
			start=n;
		}
	}
	
	void lastinsert(int val)
	{
		node *n=new node;
			n->data=val;
		if(start==NULL)
		{
			n->next=n;
			n->prev=n;
			start=n;
		}
		else
		{
		   n->next=start;
		   n->prev=start->prev;
		   start->prev->next=n;
		   start->prev=n;
		}
	}
	void insertafter(node *address,int val)
	{
		if(start==NULL)
		{
			cout<<"Error:List is empty can't insert node\n";
		}
		else
		{
		node *n=new node;
		n->data=val;
		if(address==start)
		{
			n->next=address->next;
			n->prev=address;
			address->next=n;
		}
		else if(address==start->prev)
		{
			lastinsert(val);
		}
		else
		{
			n->next=address->next;
			n->prev=address;
			address->next->prev=n;
			address->next=n;
		}
		}
	}
	node* search(int val)
	{
		node *t;
		t=start;
		if(start==NULL)
		{
			cout<<"Error:List is empty can't search node\n";
		}
		else
		{
	    do
		{
			if(t->data==val)
			{
				return(t);
			}
			t=t->next;
		}
		while(t!=start);
		return(NULL);
	    }
	}
	void print()
	{
		node *t;
		t=start;
		if(start==NULL)
		{
			cout<<"Error:List is empty can't print\n";
		}
		else
		{
		do
		{
		    cout<<"["<<t->data<<"]"<<"-->";
			t=t->next;
		}
		while(t!=start);
		cout<<endl;
	    }
	}
	void deletefirst()
	{
		if(start==NULL)
		{
			cout<<"Error:List is empty can't delete node\n";
		}
		else if(start->next==start &&  start->prev==start)
		{
			delete start;
			start=NULL;
		}
		else
		{
			node *n;
			n=start->next; 
			n->prev=start->prev;
			start->prev->next=n;
			delete start;
			start=n;
		}
	}
	void deletelast()
	{
	   if(start==NULL)
		{
			cout<<"Error:List is empty can't delete node\n";
		}
		else if(start->next==start &&  start->prev==start)
		{
			delete start;
			start=NULL;
		}
		else
		{
			node *lastnode;
			lastnode=start->prev; 
			
			lastnode->prev->next=start;
			start->prev=lastnode->prev;
			delete lastnode;
		
		}
	}
	void deletenode(node *address)
	{
		if(start==NULL)
		{
			cout<<"Error:List is empty can't insert node\n";
		}
		else if(address==NULL)
		{
			cout<<"Error:Searched Node not found\n";
		}
		else
		{
		if(address==start)
		{
		     deletefirst();
		}
		else if(address==start->prev)
		{
			deletelast();
		}
		else
		{
		    node *n=address->prev;
		    
		    n->next=address->next;
		    address->next->prev=n;
		    delete address;
		}
		}
	}
	CDLL()
	{
		start=NULL;
	}
	~CDLL()
	{
		while(start!=NULL)
		{
			deletefirst();
		}
	}
};

int main()
{
	CDLL c1;
	c1.startinsert(1);
	c1.startinsert(2);
	c1.startinsert(3);
	c1.startinsert(4);
	c1.print();
	c1.insertafter(c1.search(2),33);
	c1.print();
	c1.deletefirst();
	c1.print();
	c1.deletefirst();
	c1.print();
	c1.deletefirst();
	c1.print();
	c1.deletefirst();
	c1.print();
	c1.deletefirst();
	c1.print();
	c1.deletefirst();
	c1.lastinsert(1);
	c1.lastinsert(2);
	c1.lastinsert(3);
	c1.lastinsert(4);
	c1.lastinsert(5);
	c1.print();
	c1.deletelast();
	c1.print();
	c1.deletelast();
	c1.print();
	c1.deletelast();
	c1.print();
	c1.deletelast();
	c1.print();
	c1.deletelast();
	c1.print();
	c1.deletelast();
	c1.lastinsert(1);
	c1.lastinsert(2);
	c1.lastinsert(3);
	c1.lastinsert(4);
	c1.lastinsert(5);
	c1.print();
	c1.deletenode(c1.search(4));
	c1.print();
	c1.deletenode(c1.search(5));
	c1.print();
	c1.deletenode(c1.search(2));
	c1.print();
	c1.deletenode(c1.search(3));
	c1.print();
	c1.deletenode(c1.search(1));
    c1.print();
	c1.lastinsert(1);
	c1.lastinsert(2);
	c1.lastinsert(3);
	c1.lastinsert(4);
	c1.lastinsert(5);
    c1.print();
	c1.insertafter(c1.search(5),6);
	c1.print();
    c1.insertafter(c1.search(2),90);
	c1.print();
	c1.deletenode(c1.search(90));
	c1.print();
	return 0;
}