#include"C:\Users\rajha\Desktop\STUDY MATERIAL\Data structures using C++\Array\Assignment - 1\Program.cpp"

class Stack:private Array
{
 public:

 void operator=(Stack &S1)
 {
    Array::operator=(S1);
 }
 Stack(Stack &S):Array(S)
 {
   
 }
 Stack(int size):Array(size)
 {
 
 }
int GetStackSize()
{
 return(Array::GetCapacity());
}
 void push(int val)
 {
    if(isFull())
    {
        cout<<"Stack Overflow"<<endl;
    }
    else
    {
     append(val);
    }
    
 }

 int peek()
 {
   if(!isEmpty()) 
   {
      return(get(count()-1));
   }
   else
   {
     cout<<"Stack is Empty"<<endl;
   }
 }

 void pop()
 {
    if(isEmpty())
    {
      cout<<"Stack Underflow"<<endl;
    }
    else
    {
        Delete(count()-1);
    }
    

 
 }

 ~Stack()
 {

 }

 virtual bool isFull()
 {
    return Array::isFull();
 }

 virtual bool isEmpty()
 {
    return Array::isEmpty();
 }


};

 void reverse(Stack &s1)
 {
    Stack s2(s1.GetStackSize());
    while(!s1.isEmpty())
    {
    s2.push(s1.peek());
    s1.pop();
    }
    s1=s2;
 }
 void pushInStack(Stack &s, Stack &minStack,int data)
 {
   s.push(data);
   if(minStack.isEmpty())
   {
      minStack.push(data);
   }
   else
   {
      if(data>minStack.peek())
      {
         minStack.push(minStack.peek());
      }
      else
      {
         minStack.push(data);
      }
   }
}

void popFromStack(Stack &s, Stack &minStack)
{
  s.pop();
  minStack.pop();
}
  

int main()
{
    
    Stack s1(5);
    Stack minStack(5);
    pushInStack(s1,minStack,50);
    cout<<"current minimum value is :"<<minStack.peek()<<endl;
    pushInStack(s1,minStack,40);
    cout<<"current minimum value is :"<<minStack.peek()<<endl;
    pushInStack(s1,minStack,60);
    cout<<"current minimum value is :"<<minStack.peek()<<endl;
    pushInStack(s1,minStack,70);
    cout<<"current minimum value is :"<<minStack.peek()<<endl;
    pushInStack(s1,minStack,30);
    cout<<"current minimum value is :"<<minStack.peek()<<endl;
    cout<<"Poping Start";
    popFromStack(s1,minStack);
    cout<<"current minimum value is :"<<minStack.peek()<<endl;
        popFromStack(s1,minStack);
    cout<<"current minimum value is :"<<minStack.peek()<<endl;
        popFromStack(s1,minStack);
    cout<<"current minimum value is :"<<minStack.peek()<<endl;
        popFromStack(s1,minStack);
    cout<<"current minimum value is :"<<minStack.peek()<<endl;
        popFromStack(s1,minStack);
    cout<<"current minimum value is :"<<minStack.peek()<<endl;
    return 0;
}