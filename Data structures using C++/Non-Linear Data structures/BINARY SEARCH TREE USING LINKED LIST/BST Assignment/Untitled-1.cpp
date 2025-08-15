// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;



class node
{
    public:
    node *left;
    int data;
    node *right;
};


class BST
{
    public:
    node *root;
    BST()
    {
        root=NULL;
    }
    bool isEmpty()
    {
        if(root==NULL)
        {
          return true;
        }
        else
        {
          return false;
        }
    }
    
    node* insert_node(node *t,int val)
    {
        if(t==NULL)
        {
         node *n = new node;
         n->left=NULL;
         n->right=NULL;
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
        return t;
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
    
    
    void insert(int val)
    {
    
        root=insert_node(root,val);
    }
    
    
    void del(int val)
    {
        root=delete_node(root,val);
    }
    
    node* delete_node(node *t,int val)
    {
       if(t==NULL)
       {
           cout<<"Error:Tree is Empty Can't Delete";
       }
       else
       {
           if(t->data > val)           
           {
               t->left=delete_node(t->left,val);
           }
           else if(t->data < val)           
           {
               t->right=delete_node(t->right,val);
           }
           else
           {
               if(t->left==NULL && t->right==NULL)
               {
                   delete t;
                   t=NULL;
               }
               else if(t->right==NULL && t->left!=NULL)    // node has one child in left side;
               {
                   node *temp;
                   temp=t;
                   t=t->left;
                   delete temp;
               }
               else if(t->right!=NULL && t->left==NULL)    // node has one child in right side;
               {
                   node *temp;
                   temp=t;
                   t=t->right;
                   delete temp;
               }
               else if(t->right!=NULL && t->left!=NULL)   //node hs 2 child nodes
               {
                   
                   node *pre;
                   pre=t->right;
                   while(pre->left!=NULL)
                   {
                       pre=pre->left;
                   }
                   t->data=pre->data;
                   t->right=delete_node(t->right,pre->data);
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
            while(t!=NULL)
            {
                if(t->data < val)
                {
                    t=t->right;
                }
                else if(t->data > val)
                {
                    t=t->left;
                }
                else if(t->data==val)
                {
                    break;
                }
            }
              return t;
        }
    }
    
    ~BST()
    {
        while(root!=NULL)
        {
           del(root->data);
        }
    }
    
};




int main() 
{
    BST b1;
    b1.insert(10);
    b1.insert(5);
    b1.insert(15);
    b1.insert(12);
    b1.insert(18);
    b1.inorder(b1.root);cout<<endl;
    node *n=b1.search(32);
    if(n!=NULL)
       cout<<"Searched Node:"<<n->data;
    else
       cout<<"Node nahi mila\n";
    return 0;
}