#include<iostream>
using namespace std;

class node
{
 public:
 int data;
 node *left;
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
  
  void insert(int val)
  {
    node *n=new node;
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    if(isEmpty())  // empty tree
    {
      root=n;
    }
    else
    {
       node *t=root;
       while(t!=NULL)
       {
        if(t->data == n->data)
        {
            cout<<"ERROR:Can't Insert Duplicate Value "<<n->data<<" In the Tree"<<endl; 
            break;
        }
        else if(t->data < n->data)     // if inserted node is bigger then current nowhictraversed;
        {
            if(t->right==NULL)
            {
                t->right=n;
                break;
            }
            else
            {
              t=t->right;
            }
        }
        else if(t->data > n->data)
        {
            if(t->left==NULL)
            {
                t->left=n;
                break;
            }
            else
            {
            t=t->left;    
            }        // if inserted node is smaller node  then current node which is traversed;
        }
       }
      
    }
  }
  node* search(int val)
  {
    node *t=root;
    while(t!=NULL && t->data!=val )
    {
       if(t->data > val)
       {
           t=t->left;
       }
       else if(t->data < val)
       {
           t=t->right;
       }
    }  
    return(t);
  }
  
  
  void del_node(int val)
  {
      root=delete_node(root,val);
  }


node* delete_node(node *ptr,int val)
{
 if(ptr==NULL)
 {
     return NULL;
 }
 else if(val<ptr->data)
 {
     ptr->left=delete_node(ptr->left,val);
 }
 else if(val>ptr->data)
 {
     ptr->right=delete_node(ptr->right,val);
 }
 else
 {
     if(ptr->left==NULL && ptr->right==NULL)
     {
         delete ptr;
         return NULL;
     }
     if(ptr->left==NULL || ptr->right==NULL)
     {
         node *child;
         if(ptr->left!=NULL)
         {
          child=ptr->left;
          delete ptr;
          return child;
         }
         else if(ptr->right!=NULL)
         {
          child=ptr->right;
          delete ptr;
          return child;
         }
     }
     if(ptr->left!=NULL && ptr->right!=NULL)
     {
      node *pre,*parent;
      pre=ptr;
      parent=pre->left;
      while(pre->right!=NULL)
      {
        ptr=ptr->right;
      }
      ptr->data=pre->data;
      parent->right=delete_node(pre,pre->data);
     }
 }
 return(ptr);
}





~BST()
{ 
  
    node *t=root;
    while(t!=NULL)
    {
        del_node(t->data);
    }
}

};



void preorder(node *n)
{
  if(n!=NULL)
  {   
    cout<<n->data<<" ";
    preorder(n->left);
    preorder(n->right);
  }
}
void inorder(node *n)
{
  if(n!=NULL)
  {   
    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);
  }
}
void postorder(node *n)
{
  if(n!=NULL)
  {   
    postorder(n->left);
    postorder(n->right);
    cout<<n->data<<" ";
  }
}


int main()
{
  node *t;
  BST b1;
  b1.insert(5);
  b1.insert(3);
  b1.insert(7);
  b1.insert(2);
  b1.insert(4);
  b1.insert(6);
  inorder(b1.root);cout<<endl;
  b1.del_node(6);
  inorder(b1.root);cout<<endl;
  return 0;
}


