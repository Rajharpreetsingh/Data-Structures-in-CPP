#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;
};

class Queue
{
 public:
 node *front,*rear;
Queue()
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
void enqueue(int val)
{
    node *n=new node;
    n->data=val;
    n->next=NULL; 
    if(isEmpty())  // jab list empty ho
    {
        rear=n;
        front=n;
    }
    else
    {
        rear->next=n;
        rear=n;
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
void Empty()
{
     while(!isEmpty())
    {
        dequeue();
    }
}
void dequeue()
{
    node *temp;
    if(isEmpty())
    {
       cout<<"Error:List is Empty Can Not Delete";
    }
    else if(front->next==NULL)
    {
        delete front;
        front=NULL;
        rear=NULL;
    }
    else
    {
        temp=front;
        front=front->next;
        delete temp;
    }
}
int count()
{
    if(isEmpty())
    {
        return(0);
    }
    int c=0;
    node *t;
    t=front;
    while(t!=NULL)
    {
        t=t->next;
        c++;
    }
    return(c); 
}
Queue(Queue &q)
{
    node *t=q.front;
    while(!isEmpty())
    { 
        dequeue();
    }
    
    while(t!=NULL)
    {
       enqueue(t->data);
       t=t->next;
    }
}

Queue& operator=(Queue &q)
{
    node *t=q.front;
    while(!isEmpty())
    { 
        dequeue();
    }
    while(t!=NULL)
    {
       enqueue(t->data);
       t=t->next;
    }
    return(q);
}
~Queue()
{
    while(!isEmpty())
    {
        dequeue();
    }
}
void print()
{
    node *t=front;
    while(t!=NULL)
    {
        cout<<"["<<t->data<<"]"<<" ";
        t=t->next;
    }
    cout<<endl;
}
};

void asc_sort(Queue &q1)
{
   node *t1,*t2;
   Queue q2,q3;
   while(!q1.isEmpty())
   {
       t1=q1.get_front();
       t2=q2.get_rear();
       if(q2.isEmpty())
       {
        q2.enqueue(t1->data);
       }
       else if(t1->data < t2->data) // yeh test case special hai
       {
           if(!q2.isEmpty())
           {
           t2=q2.get_front();
           while(t2->data < t1->data )
           {
               q3.enqueue(t2->data);
               t2=t2->next;
               q2.dequeue();
           }
           q3.enqueue(t1->data);
           while(!q2.isEmpty())
           {
                t2=q2.get_front();
                q3.enqueue(t2->data);
                q2.dequeue();
           }
           q2=q3;
           q3.Empty();
           }
       }
       else if(t1->data > t2->data)
       {
          q2.enqueue(t1->data);
       }
       q1.dequeue();
   }
   q1=q2;
}
void dsc_sort(Queue &q1)
{
 node *t1,*t2;
 Queue q2,q3;
   while(!q1.isEmpty())
   {
       t1=q1.get_front();
       t2=q2.get_rear();
       if(q2.isEmpty())
       {
        q2.enqueue(t1->data);
       }
       else if(t1->data < t2->data)
       {
          q2.enqueue(t1->data);
       }
       else if(t1->data > t2->data) // yeh test case special hai
       {
           if(!q2.isEmpty())
           {
           t2=q2.get_front();
           while(t2->data > t1->data )
           {
               q3.enqueue(t2->data);
               t2=t2->next;
               q2.dequeue();
           }
           q3.enqueue(t1->data);
           while(!q2.isEmpty())
           {
                t2=q2.get_front();
                q3.enqueue(t2->data);
                q2.dequeue();
           }
           q2=q3;
           q3.Empty();
           }
       }
       q1.dequeue();
   }
   q1=q2;
}

int main()
{
    Queue q1,q2;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.print();
    dsc_sort(q1);
    q1.print();
    return 0;
}