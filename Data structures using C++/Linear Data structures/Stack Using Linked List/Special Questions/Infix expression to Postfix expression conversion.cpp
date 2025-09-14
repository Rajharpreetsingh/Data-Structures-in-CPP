#include<iostream>
#include<string.h>
using namespace std;

class node
{
public:
char data;
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
	void push(char val)
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
	//	cout<<endl;
		}
	}
	char peek()
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
		char temp;
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
	char Length(char n)
	{
	    char i=0;
	    while(n!=0)
	    {
	        i++;
	        n=n/10;
	    }
	    return i;
	}
	bool IsPlaindrome(char n)
	{
		stack s;
       char length=Length(n);
	   char i=length/2;
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

	bool isPlaindrome(char n)
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
 int presedence(char opter)
{
    if(opter=='+' || opter=='-')
    {
        return(1);
    }
    else if(opter=='*' || opter=='/')
    {
         return(2);
    }
    else if(opter=='^')
    {
         return(3);
    }
	else
	{
		 return(0);
	}
	 
}

char association(char opter)
{
    if(opter=='^')
    {
        return('R');
    }
    else 
    {
         return('L');
    }
}


void ToPostFix(string input)
{
    cout<<"InFix: "<<input<<endl;
    int i=0;
    string c;
    string output="";
    char length=input.length();
	stack s1;
    while(i<length)
    {
     if(input.at(i)>='A' && input.at(i)<='Z' ||input.at(i)>='a' && input.at(i)<='z')
     {
         c=input.at(i);
         output.append(c);
     }
     else if(input.at(i)=='(')
     {
        s1.push(input.at(i));
     }
     else if(input.at(i)==')' )
     {  
         while(s1.peek()!='(')
         {
             c=s1.peek();
             output.append(c);
             s1.pop();
         }
         s1.pop();
     }
     else 
	 {
         if(presedence(input.at(i))>presedence(s1.peek()) || s1.peek()=='0')
         {
              s1.push(input.at(i));
         }
		 if(presedence(input.at(i))<presedence(s1.peek()))
         {
	while(presedence(input.at(i))<presedence(s1.peek()) && s1.peek()!='0' || presedence(input.at(i))==presedence(s1.peek()) && s1.peek()!='0' && association(input.at(i))=='L')
			  {
				c=s1.peek();
				output.append(c);
				s1.pop();
			  }
			  s1.push(input.at(i));
         }
     }
     cout<<"Output:"<<output<<"      "<<"Stack:";
     s1.print();
     cout<<endl;
     i++;
    }
    while(s1.peek()!='0')
    {
        c=s1.peek();
        output.append(c);
        s1.pop();
    }
    cout<<"Output:"<<output<<"      "<<"Stack:";
     s1.print();
     cout<<endl;
}

int main()
{
      ToPostFix("a+b*(c^d-e)^(f+g*h)-i");
	  return 0;
}