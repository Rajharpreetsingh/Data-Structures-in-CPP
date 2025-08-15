#include<iostream>
using namespace std;


class Queue
{
	public:
	int front,rear,capacity,*ptr;
	Queue(int val)
	{
		capacity=val;
		front=-1;
		rear=-1;
		ptr=new int[val];
	}
	void enqueue(int val)
	{
        if(isFull())
		{
          cout<<"Error:Queue Overflow"<<endl;
		}
		else  if(isEmpty())
		{
           front=0;
		   rear=0;
		   ptr[rear]=val;
		}
		else if(rear==capacity-1)
		{
            rear=0;
			ptr[rear]=val;
		}
		else
		{
			rear++;
			ptr[rear]=val;
		}
	}
	bool isFull()
	{
       return((front==0 && rear==capacity-1  || rear+1==front));
	}
	bool isEmpty()
	{
		if(front==-1 && rear==-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int get_rear()
	{
		if(!isEmpty())
		{
          return(ptr[rear]); 
		}
		else
		{
			cout<<"Error:Queue is Empty"<<endl;
		}
	}
	int get_front()
	{
		if(!isEmpty())
		{
          return(ptr[front]); 
		}
		else
		{
			cout<<"Error:Queue is Empty"<<endl;
		}
	}
	void dequeue()
	{
		if(isEmpty())
		{
          cout<<"Error:Q ueue is Empty"<<endl;
		}
		else if(front==rear)
		{
           front=-1;
		   rear=-1;
		}
		else if(front==capacity-1)
		{
             front=0;
		}
		else
		{
			front++;
		}
	}
	~Queue()
	{
		delete []ptr;
	}
	Queue(Queue &q)
	{
		capacity=q.capacity;
		front=q.front;
		rear=q.rear;
		ptr=new int[capacity];
		int n=q.count();
		int i=q.front;
		while(n)   
		{
			ptr[i]=q.ptr[i];
			if(i==capacity-1)
			{
				i=0;
			}
			else
			{
				i++;
			}
			n--;
		}
	}
	int count()
	{
		int c=0;
		if(isEmpty())
		{
            return 0;
		}
		else if(front<=rear)
		{
          return (rear-front+1);
		}
		else 
		{
          return (capacity-front+rear+1);
		}
	}

	Queue& operator=(Queue &q)
    {
       capacity=q.capacity;
	   front=q.front;
	   rear=q.rear;
	   if(ptr!=NULL)
	   {
          delete []ptr;
	   }
	    ptr=new int[capacity];
		int n=q.count();
		int i=q.front;
		while(n)
		{
			ptr[i]=q.ptr[i];
			if(i==capacity-1)
			{
				i=0;
			}
			else
			{
				i++;
			}
			n--;
		}
	  

	}

};


int main()
{
	Queue q1(5);

}