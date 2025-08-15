#include<iostream>
using namespace std;

class node
{
   public:
   int data;
   int priority;
   node *next;

};

class PriorityQueue
{
   public:
   node *start;
   PriorityQueue()
   {
    start=NULL;
   }
   void insert(int val,int p)
   {
    node *t;
    node *n= new node;
    n->data=val;
    n->priority=p;
    if(start==NULL)
    {
        start=n;
        n->next=NULL;
    }
    else
    {

           if(start->priority < n->priority)
           {
              n->next=start;
              start=n;
           }
           else
           {
           t=start;
           while(t->next!=NULL)
           {
            if(t->next->priority < n->priority)
            {
                 n->next=t->next;
                 t->next=n;
                 break;
            }
            else if(t->next->priority == n->priority)
            {
              n->next=t->next->next;
              t->next->next=n;
              break;
            }
            t=t->next;
           }
           }
    }
   

   }

   void Delete_highest()
   {
    node *t;
    if(start==NULL)
    {
        cout<<"Error:List is Empty"<<endl;
    }
    else if(start->next==NULL)
    {
       delete start;
       start=NULL;
    }
    else
    {
        t=start;
        start=start->next;
        delete t;
    }
   }

   node* get_highest()
   {
    if(start!=NULL)
    {
      return(start);
    }
    else
    {
        return(NULL);
    }
   }

   int get_highest_number()
   {

    if(start!=NULL)
    {
      return(start->priority);
    }
    else
    {
        return(0);
    }
   }
    bool isEmpty()
    {
        if(start==NULL)
        {
            return(true);
        }
        else
        {
             return(false);
        }
    }

    void print()
    {
        node *t;
        t=start;
        while(t!=NULL)
        {
            cout<<"["<<t->data<<"]"<<"-->";
            t=t->next;
        }
        cout<<"[NULL]"<<endl;
    }
   ~PriorityQueue()
   {
      while(start!=NULL)
      {
        Delete_highest();
      }
   }
};

int main()
{
    node *temp;
    PriorityQueue p1;
    p1.insert(5,10);
    p1.insert(7,11);
    p1.insert(3,12);
    p1.insert(11,15);
    p1.insert(9,12);
    p1.print();
    p1.Delete_highest();
    p1.print();
    cout<<"Highest Priority Number is:"<<p1.get_highest_number()<<endl;
    temp=p1.get_highest();
    cout<<"Highest Priority Element is:"<<temp->data;
    return 0;
}