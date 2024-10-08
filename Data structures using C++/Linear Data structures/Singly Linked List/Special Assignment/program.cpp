#include<iostream>
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
	int count()
    {
 	if(start==NULL)
 	{
 		return 0;
	}
	else
	{
 	int i=0;
 	node *t;
 	t=start;
 	while(t!=NULL)
 	{
 		i++;
 		t=t->next;
	}
	return(i);
    }
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

  
  void reverse()
  {
  	node *t1,*t2,*t3;
	t1=start;
    if(start==NULL)
	{
		cout<<"ERROR:List is Empty Can Not Reverse"<<endl;
	}
	else if(start->next==NULL)
	{
		cout<<"ERROR:List has only One Node Can Not Reverse"<<endl;
	}
	else
	{
		t1=start;
		t2=start->next;
		t3=start->next->next;
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
       start=t1;
	}

  }
  
   node* middleNode()
  {
    node *t=start;
    int i=0,length=count(),mid;
    mid=length/2;
    while(i<mid)
    {
        t=t->next;
        i++;
    }
     return(t);
  }
  
  node* GetFirstNode()
  {
	if(start==NULL)
	{
		return NULL;
	}
	else
	{
	return start;
	}
  }
  
  void sort()
  {
    int i=0,j=0,temp;
    int length=count();
    node *t=start;
	if(start==NULL)
	{
		cout<<"ERROR:List is Empty Can Not Sort"<<endl;
	}
	else if(start->next==NULL)
	{
		cout<<"ERROR:List Has Only One Node Can Not Sort"<<endl;
	}
    else
    {
		while(i<length)
		{
		    t=start;
		    j=0;
		    while(j<length)
		    {
		        if(t->next!=NULL && t->data > t->next->data)
		        { 
		            temp=t->data;
		            t->data=t->next->data;
		            t->next->data=temp;
		        }
		       t=t->next;
			   j++;
		    }
		    i++;
		}
    }
  }
  
  void merge(SLL &l1)
  {
   node *t;
   t=l1.GetFirstNode();
   while(t!=NULL)
   {
    endinsert(t->data);
	t=t->next;
   }
   sort();
  }


};

bool check_cycle(SLL &obj)
  {
	node *t1=obj.GetFirstNode(),*t2=obj.GetFirstNode();
    if(t1==NULL)
	{
		return(false);
	}
	else 
    {
		do
		{
		    if(t2==NULL)
		    {
		        return(false);
		    }
			else if(t2->next!=NULL)
			{
               t2=t2->next->next;
			}
			else
			{
			    return false;
			}
			t1=t1->next;
		}
		while(t1!=t2);
		return(true);
	}
  
   }

 int cycle_length(SLL &obj)
   {
	  if(check_cycle(obj))
	  {
		int i=1;
		node *t1,*t2;
		t1=obj.GetFirstNode();
		t2=obj.GetFirstNode();
		do
		{
           t1=t1->next;
		   t2=t2->next->next;
		}
		while(t1!=t2);

		while(t1->next!=t2)
		{
			i++;
			t1=t1->next;
		}
        return(i);
	  }
	  else
	  {
		return(0);
	  } 
   }  

SLL* Add(SLL &l1,SLL &l2)
{
        node *t;
        int carry=0;
	    SLL *l3=new SLL();
	    SLL *l4=new SLL();
	    l1.reverse();
	    l2.reverse();
        node *t1=l2.GetFirstNode();
		node *t2=l1.GetFirstNode();
		while(t2!=NULL && t1!=NULL)
		{
		     if(t1->data+t2->data>=10)
		     {
		        l3->endinsert((t1->data+t2->data)%10+carry);
		        carry=(t1->data+t2->data)/10;
		     }
		     else
		     {
               l3->endinsert(t1->data+t2->data+carry);
               carry=0;
		     }
             
			 t2=t2->next;
			 t1=t1->next;
		}
		t=l3->GetFirstNode();
		while(t!=NULL)
		{
		    l4->endinsert(t->data);
		    t=t->next;
		}
		l4->reverse();
		return(l4);
}



class polynomial:public SLL
{
	 public:
     class node
	 {
		public:
		int co;
		int deg;
		node *next;
	 };
	 node *start;
     node* GetFirstNode()
	 {
		return(start);
	 }
	 polynomial()
	 {
		start=NULL;
	 }

	 void insert(int c,int d)
	 {
		node *t=start;
		node *p=start;
		node  *n = new node;
		n->next=NULL;
		n->co=c;
		n->deg=d;
 
		if(start==NULL)
		{
		   start=n;
		}
		else if(t->next==NULL)
		{
			if(t->deg < n->deg)
			{
                n->next=t;
				t=n;
			}
			else
			{
		      t->next=n;
			}
		}
		else
		{
              t=t->next;
			  while(t!=NULL)
			  {
				if(t->deg  <  n->deg)
				{
                  p->next=n;
				  n->next=t;
				}
				else if (t->next==NULL)
				{
				    t->next=n;
				    break;
				}
				p=t;
				t=t->next;
			  }
			
			  
		}
		   

	 }

    void add(polynomial &p1)
	{
	  node *t1=GetFirstNode();
      node *t2=p1.GetFirstNode();
      polynomial p3;
      while(t1!=NULL && t2!=NULL)
	  {
                if(t1->deg==t2->deg)
				{
					p3.insert(t1->co+t2->co,t1->deg);
				}
				else
				{
				    p3.insert(t1->co,t1->deg);
                    p3.insert(t2->co,t2->deg);
				}

				t1=t1->next;
				t2=t2->next;
	  }
    
      start=p3.start;
      
	}


	void print()
	{
       node *t=start;
	   while(t!=NULL)
	   {
        cout<<t->co<<"^"<<t->deg<<" ";
		t=t->next;
	   }
	   cout<<endl;
	}
};


int main()
{
 polynomial p1,p2;
 SLL l1,l2;
 SLL *l3;
 
 l1.endinsert(4);
 l1.endinsert(0);
 l1.endinsert(9);
 l1.print();
 
l2.endinsert(1);
l2.endinsert(0);
l2.endinsert(1);
l2.print();

l3=Add(l1,l2);

l3->print();



 SLL  s1,s2;
 s1.endinsert(1);	
 s1.endinsert(5);
 s1.endinsert(7);
 s1.endinsert(2);
 s1.endinsert(4);
 s1.endinsert(3);
 s1.print();
 s1.reverse();
 s1.print();
 s1.sort();
 s1.print();


 
 return 0;
}
