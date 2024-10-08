#include<iostream>

using namespace std;

class node
{	
public:
int data;
node *next;
};

class  CLL
{
	public:
		node *last;
		CLL()
		{
			last=NULL;
		}
		void insertafter(node *address,int val)
		{
			if(address==NULL)
			{
				cout<<"Error:Searched Node Not Found\n";
			}
			else
			{
				node *n= new node;
				n->data=val;
				if(address==last)
				{
				  endinsert(val);
				}
				else if(address==last->next)
				{
					n->next=address->next;
					address->next=n;
				}
				else
				{
					n->next=address->next;
					address->next=n;
				}
			}
		}
		node* search(int val)
		{
			node *t=last->next;
			do
			{
			  if(t->data==val)
			  {
			  	return(t);
			  }
			  t=t->next;	
			}
			while(t!=last->next);
			return(NULL);
		}
		void startinsert(int val)
		{
			node *n=new node;
			n->data=val;
			if(last==NULL)
			{
				n->next=n;
				last=n;
			}
			else
			{
				n->next=last->next;
				last->next=n;
		    }
     	}
        void endinsert(int val)
		{
			node *n=new node;
			n->data=val;
			if(last==NULL)  //when list is empty
			{
				n->next=n;
				last=n;
			}
			else    //when list is not empty
			{
				n->next=last->next;
				last->next=n;
				last=n;
		    }
     	}
     	void deletefirst()
     	{
     	    if(last==NULL)
     	    {
     	    	cout<<"Error:List is Empty can not delete\n";
			}
			else if(last==last->next)
			{
				delete last;
				last=NULL;
			}
			else
			{
				node *n;
				n=last->next;
				last->next=n->next;
				delete n;
			}
		}
		
		void deletelast()
		{
			if(last==NULL)
     	    {
     	    	cout<<"Error:List is Empty can not delete\n";
			}
			else if(last==last->next)
			{
				delete last;
				last=NULL;
			}
			else
			{
			node *t=last->next,*n;
			do
			{
			  t=t->next;	
			}
			while(t->next!=last);
			n=last;
			t->next=last->next;
			last=t;
			delete n;
			
			}
		}
		void deleteNode(node *address)
		{
		  if(last==NULL)
		  {
		  	cout<<"Error:List is Empty can not delete\n";
		  }
		  else if(address==NULL)
		  {
		    cout<<"Error:Searched Node Not Found\n";
		  }
		  else
		  {
		  if(last->next->data==address->data)
		  {
		  	deletefirst();
		  }
		  else if(last->data==address->data)
		  {
		  	deletelast();
		  }
		  else
		  {
		  	node *t;
		  	t=last->next;
		  	while(t->next!=address)
		  	{
		  		t=t->next;
			}
			t->next=address->next;
			delete address;
		  }
        }
		}
		void print()
		{
			if(last==NULL)
			{
				cout<<"Error:List is Empty can not print\n";
			}
			else
			{
			node *t=last->next;
			do
			{
				cout<<"["<<t->data<<"]"<<"-->";
				t=t->next;
			}
		    while(t!=last->next);
		    cout<<endl;
		    }
	    }
	    ~CLL()
		{
			while(last!=NULL);
			{
				deletefirst();
			}
		}
};


int main()
{
	CLL c1;
	c1.endinsert(1);
	c1.endinsert(2);
	c1.endinsert(3);
	c1.endinsert(4);
    c1.endinsert(5);
	c1.print();
	c1.insertafter(c1.search(5),6);
	c1.print();
	
	c1.insertafter(c1.search(4),77);
	c1.insertafter(c1.search(111),2);
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
	c1.print();
	c1.deletefirst();
	c1.print();
	
	c1.endinsert(1);
	c1.endinsert(2);
	c1.endinsert(3);
	c1.endinsert(4);
    c1.endinsert(5);
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
    c1.endinsert(1);
	c1.endinsert(2);
	c1.endinsert(3);
	c1.endinsert(4);
    c1.endinsert(5);
	c1.print();
	c1.deleteNode(c1.search(1));
	c1.print();
	c1.deleteNode(c1.search(5));
	c1.print();
	c1.deleteNode(c1.search(3));
	c1.print();
	c1.deleteNode(c1.search(2));
	c1.print();
}