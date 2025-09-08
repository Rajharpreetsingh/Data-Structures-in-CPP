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

bool isPresent(int val)
{
    node *t=front;
    while(t!=NULL)
    {
        if(t->data==val)
        {
            return true;
        }
        t=t->next;
    }
    return false;
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

class stack 
{
	public:
	node *top;
    stack()
	{
		top=NULL;
	}

    bool isEmpty()
    {
        if(top==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
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



class Graph
{
public:
int v;
int **matrix;

Graph()
{

}


Graph(int n)
{
v=n;
int i,j;
matrix=new int*[n];               //DMA 
for(i=0;i<n;i++)
{
    matrix[i]=new int[n];
}


for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
   matrix[i][j]=0;
}

}


for(i=0;i<n;i++)
{
cout<<"Enter Data of Node:"<<i<<endl;
for(j=0;j<n;j++)
{
   cout<<"Enter Node Value:";
   cin>>matrix[i][j];
}
cout<<endl;
}


}

void Print_Matrix()
{
int i,j;
for(i=0;i<v;i++)
{
for(j=0;j<v;j++)
{
   cout<<" "<<matrix[i][j]<<" ";
}
cout<<endl;
}
}



void BFS(int n)
{
    int start=n,j=0,curent;
    node *temp;
    Queue queue;
    queue.enqueue(start);
    bool *visited = new bool[v];
    for(j=0;j<v;j++)
    {
        visited[j]=false;
    }
    visited[start]=true;
    cout<<"BFS:";
    while(queue.isEmpty()!=true)
    {
        temp=queue.get_front();
        curent=temp->data; 
        cout<<curent<<" ";
        queue.dequeue();
        for(j=0;j<v;j++)
        {
            if(matrix[curent][j]==1 && visited[j]==false)
            {
                visited[j]=true;
                queue.enqueue(j);
            }
        }  
    }
    delete [] visited ;
}


void DFS(int start)
{
    int i,j,current;
    stack s1;
    bool *visited= new bool[v];
    for(i=0;i<v;i++)
    {
        visited[i]=false;
    }
    cout<<"DFS:";
    s1.push(start);
    while(s1.isEmpty()!=true)
    {
        current=s1.peek();
        s1.pop();
        if(visited[current]==false)
        {
            cout<<current<<" ";
            visited[current]=true;
            for(j=v-1;j>=0;j--)
            {
                if(matrix[current][j]==1 && visited[j]==false)
                {
                    s1.push(j);       
                }
            }
        }
    }
       delete [] visited ;
}





~Graph()
{
    int i=0;
    for(i;i<v;i++)
    {
        delete [] matrix[i];
    }
    delete [] matrix;
}



};

int main()
{
     int n;
     Graph g1(5);
    
     g1.BFS(0);
     cout<<endl;
     g1.DFS(0);
     return 0;
}