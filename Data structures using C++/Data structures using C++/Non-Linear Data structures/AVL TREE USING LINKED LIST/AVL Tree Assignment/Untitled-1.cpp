#include<iostream>
using namespace std;

class node 
{
    public:
    int data;
    int height;
    node *left;
    node *right;
    node()
    {
        height=0;
        left=NULL;
        right=NULL;
    }
};





class AVL 
{
public:
    node *root;


    AVL() 
    {
        root = NULL;
    }
    
    int max(int x,int y)
    {
        if(x>y)
          return x;
        else
          return y;
    }

    node* insert_node(node *t,int val)
    {
         if(t==NULL)
         {
             node *n= new node;
             n->data=val;
             t=n;
         }
         else if(t->data < val)
         {     
              
               t->right=insert_node(t->right,val);
         }
         else if(t->data > val)
         {
               t->left=insert_node(t->left,val);
         }
         t->height=1+max(getheight(t->left),getheight(t->right));
         
         if(get_balance_factor(t)<-1 || get_balance_factor(t)>1)
         {
                // t is Equal to disturbed Node
               int b=get_balance_factor(t);
               cout<<"Disturbed Node is:"<<t->data<<endl;
               if(b > 1 && val < t->left->data)             //left of left insertion
               {
                t=right_rotate(t);
               }
               else if(b > 1 && val > t->left->data)        //right of left insertion
               {
                t->left=left_rotate(t->left);
                t=right_rotate(t);
               }
               else if(b < -1 && val < t->right->data)        //right of left insertion
               {
                t->right=right_rotate(t->right);
                t=left_rotate(t);
               }
               else if(b < -1 && val > t->right->data)        //right of right insertion
               {
               t=left_rotate(t);
               }


         }
              
        
         return t;
         
        
    }
    
    node* right_rotate(node *x)
    {
        node *y,*z;
        y=x->left;
        z=y->right;
        y->right=x;
        x->left=z;
        x->height=1+max(getheight(x->left),getheight(x->right));
        y->height=1+max(getheight(y->left),getheight(y->right));
        return y;
    }
    
    node* left_rotate(node *x)
    {
        node *y,*z;
        y=x->right;
        z=y->left;
        y->left=x;
        x->right=z;
        x->height=1+max(getheight(x->left),getheight(x->right));
        y->height=1+max(getheight(y->left),getheight(y->right));
        return y;
    }
    
    void insert(int val)
    {
        root=insert_node(root,val);
    }
    void Delete(int val)
    {
        root=delete_node(root,val);
    }


    node* delete_node(node *t,int val)
    {
        if(t==NULL)
        {
           cout<<"Error:Tree is Empty Can't Delete";
        }
        else if(t->data < val)
        {
           t->right=delete_node(t->right,val);
        }
        else if(t->data > val)
        {
            t->left=delete_node(t->left,val);
        }
        else if(t->data == val)
        { 
            if(t->left==NULL && t->right==NULL)              //leaf node  
            {
               delete t;
               t=NULL;
               return t;
            }
            else if(t->right==NULL && t->left!=NULL)          //one childode in left
            {
               node *temp;
               temp=t;++
               t=t->left;
               delete temp;
            }
            else if(t->right!=NULL && t->left==NULL)          //one child node in right
            {
               node *temp;
               temp=t;
               t=t->right;
               delete temp;
            }
            else if(t->right!=NULL && t->left!=NULL)          //Has Two child nodes
            {
              node *inorder;
              inorder=t->right;
              while(inorder->left!=NULL)
              {
                inorder=inorder->left;
              }
              t->data=inorder->data;
              t->right=delete_node(t->right,inorder->data);
            }
        }
        
         if(get_balance_factor(t)<-1 || get_balance_factor(t)>1)
         {
            //t is Equal to disturbed Node
            //cout<<"Disturbed Node is:"<<t->data<<endl;
               int b=get_balance_factor(t);
               
               if(t->right!=NULL)
               {
               if(b <-1 &&  get_balance_factor(t->right)<=0)
               {
                    t=left_rotate(t);        //left rotation
               }

               if(b <-1 && get_balance_factor(t->right)>0)
               {
                    t->right=right_rotate(t->right);        //right left rotation
                    t=left_rotate(t);
               }
               }


               if(t->left!=NULL)
               {
               if(b>1 && get_balance_factor(t->left)>=0)    //right rotation
               {
                   t=right_rotate(t);                        
               }
               if(b>1 && get_balance_factor(t->left)<0)
               {
                   t->left=left_rotate(t->left);              //left right rotation
                   t=right_rotate(t);
               }
               }
         }
        return t;
    }


    
    node* search(int val)
    {
        node *t;
        t=root;
        if(t==NULL)
        {
            return t;
        }
        else
        {
           while(t->data!=val)
           {
                if(t->data < val)
                {
                    t=t->right;
                }
                else if(t->data > val)
                {
                    t=t->left;
                }
           }
           return t;
        }
        

    }
     

    int getheight(node* t)
    {
        if(t==NULL)
        {
            return -1;
        }
        else
        {
           return (t->height);
        }
    }

    void inorder(node *t)
    {
         if(t==NULL)
         {
            return;
         }
        else
        {
            inorder(t->left);
            cout<<t->data<<" ";
            inorder(t->right);
        }
    }
    
    void postorder(node *t)
    {
         if(t==NULL)
         {
            return;
         }
        else
        {
            postorder(t->left);
            postorder(t->right);
            cout<<t->data<<" ";
        }
    }
     void preorder(node *t)
    {
         if(t==NULL)
         {
            return;
         }
        else
        {
            cout<<t->data<<" ";
            preorder(t->left);
            preorder(t->right);        
        }
    }
    
    int get_balance_factor(node *n)
    {
        return (getheight(n->left)-getheight(n->right));
    }
    
    ~AVL() 
    {
       while(root!=NULL)
       {
        Delete(root->data);
       }
    }
   
    
};


int main() 
{
    AVL a1;
    node *n;
    a1.insert(9);
    a1.insert(5);
    a1.insert(10);
    a1.insert(0);
    a1.insert(6);
    a1.insert(11);
    a1.insert(-1);
    a1.insert(1);
    a1.insert(2);
    a1.preorder(a1.root);cout<<endl;
    a1.Delete(10);
    a1.preorder(a1.root);
   // n=a1.search(50);
   // cout<<"Node ka balance factor hai:"<<a1.get_balance_factor(n);
    return 0;
}