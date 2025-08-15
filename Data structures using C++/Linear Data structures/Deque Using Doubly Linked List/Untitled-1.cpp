#include<iostream>
using namespace std;

class node
{
	public:
		node *prev;
		int data;
		node *next;
};


class Deque
{
public:
node *front , *rear;
Deque()
{
    front=NULL;
    rear=NULL;
}
bool isEmpty()
{
	if(front==NULL && rear==NULL)
	{
		return(true);
	}
	else
	{
		return(false);
	}
}
void front_insert(int val)
{
	node *n= new node;
	n->data=val;
	n->next=NULL;
	n->prev=NULL;
	if(isEmpty())
	{
		front=n;
		rear=n;
	}
	else
	{

		n->next=front;
	    front->prev=n;
		front=n;
	}
}


void rear_insert(int val)
{
	node *n= new node;
	n->data=val;
	n->next=NULL;
	n->prev=NULL;
	if(isEmpty())
	{
		front=rear=n;
	}
	else
	{
		rear->next=n;
		n->prev=rear;
		rear=n;
	}
}
void delete_front()
{
	node *t;
	if(isEmpty())
	{
	   cout<<"Error:List is Empty Can't Delete"<<endl;
	}
	else if(front->next==NULL && rear->next==NULL)
	{
         delete front;
		 front=NULL;
		 rear=NULL;
	}
	else
	{
	   t=front;
       front=front->next;
	   front->prev=NULL;
	   delete t;
	}
}

void delete_rear()
{
	node *t;
	if(isEmpty())
	{
	   cout<<"Error:List is Empty Can't Delete"<<endl;
	}
	else if(rear->next==NULL && front->next==NULL)
	{
         delete front;
		 front=NULL;
		 rear=NULL;
	}
	else
	{
	   t=rear;
       rear=rear->prev;
	   rear->next=NULL;
	   delete t;
	}
}
node* get_rear()
{
	return(rear);
}

node* get_front()
{
	return(front);
}


void print()
{
	node *t;
	t=front;
	while(t!=NULL)
	{
		cout<<"["<<t->data<<"]"<<"<-->";
		t=t->next;
	}
	cout<<"["<<"NULL"<<"]"<<endl;
}
~Deque()
{
  while(!isEmpty())
  {
      delete_rear();
  }
}

};

int main()
{
	Deque d1;
	node *f,*r;
    d1.front_insert(1);
    d1.front_insert(2);
	d1.front_insert(3);
	d1.front_insert(4);
	d1.front_insert(5);
    d1.print();
    f=d1.get_front();
    r=d1.get_rear();
    cout<<"Front Element is:"<<f->data<<endl;
    cout<<"Rear Element is:"<<r->data<<endl;
    d1.delete_front();
    d1.delete_front();
    d1.delete_front();
    d1.delete_front();
    d1.delete_front();
    if(d1.isEmpty())
    {
        cout<<"Deque is Empty"<<endl;
    }
    else
    {
        cout<<"Deque is not Empty"<<endl;
    }
    return(0);
}