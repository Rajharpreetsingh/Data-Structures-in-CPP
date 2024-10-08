#include<iostream>
#include<string.h>
using namespace std;

class node
{
public:
int data;
node *next;
};


class stack 
{
	public:
	node *top;
    stack()
	{
		top=NULL;
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
          cout<<'['<<" "<<']'<<"\n";
		}
		else
		{
		node *t;
		t=top;
		while(t!=NULL)
		{
			cout<<'['<<t->data<<']'<<" ";
			t=t->next;
		}
		cout<<endl;
		}
	}
	int peek()
	{
		if(top==NULL)
		{
           return('0');
		}
		else
		{
          return(top->data);
		}
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


int number(char n)
{
    switch(n)
    {
        case '1':return(1);break;
        case '2':return(2);break;
        case '3':return(3);break;
        case '4':return(4);break;
        case '5':return(5);break;
        case '6':return(6);break;
        case '7':return(7);break;
        case '8':return(8);break;
        case '9':return(9);break;
        case '0':return(0);break;
        default : cout<<"Invalid case\n";
    }
    return(-1);
}



void EvaluatePostFix(string input)
{
    int op1,op2,temp;
    string c;
    cout<<"InFix:"<<input<<endl;
    int i=0,j=0;
    string output="";
    int length=input.length();
	stack s1;
    while(i<length)
    {
        if(input.at(i)>='0' && input.at(i)<='9')
        {
            j=i;
            while(j<length && input.at(j)!=' ')  //j<length This ensures j dosen't access a invalid memory block
            {
             c=input.at(j);
             output.append(c);
             j++;
            }
            cout<<"Appended string:"<<output<<"    stack:";
            temp=stoi(output);
            output="";
            s1.push(temp);
            s1.print();
            i=j; // this will ensure that outer-loop start from the place from where j was;
        }
        if(input.at(i)=='+')
        {
           op1=s1.peek();
           s1.pop();
           op2=s1.peek();
           s1.pop();
           s1.push(op1+op2);
       
        }
        if(input.at(i)=='-')
        {
           op1=s1.peek();
           s1.pop();
           op2=s1.peek();
           s1.pop();
           s1.push(op2-op1);
        }
        if(input.at(i)=='*')
        {
           op1=s1.peek();
           s1.pop();
           op2=s1.peek();
             s1.pop();
           s1.push(op1*op2);
       
        }
        if(input.at(i)=='/')
        {
           op1=s1.peek();
           if(op1==0)
           {
             cout<<"Error:can't divide by 0 \n";
             break;
           }
           s1.pop();
           op2=s1.peek();
           s1.pop();
           s1.push(op2/op1);
        }
  
        i++;
    }
   cout<<"Result:"<<s1.peek();
}

int main()
{
      EvaluatePostFix("100 200 + 2 / 5 * 7 +");
	  return 0;
}