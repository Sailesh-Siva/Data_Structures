#include<iostream>
using namespace std;

struct node
{
    node *left,*right; 
    int data;
};
class BST
{
    public:
    node *root;
    BST()
    {
        root=NULL;
    }
    node* insert(node *root,int data)
    {
        node *nn = new node;
        if(root==NULL)
        {
            nn->data=data;
            nn->left=NULL;
            nn->right=NULL;
            return nn;
        }
        if(data<root->data)
        {
            root->left=insert(root->left,data);
        }
        else if(data>=root->data)
        {
            root->right=insert(root->right,data);
        }
        return root;
    }
    void infix(node* root)
    {
        if(root!=NULL)
        {
            infix(root->left);
            cout<<root->data<<" ";
            infix(root->right);
        }
    }
    void prefix(node* root)
    {
        if(root!=NULL)
        {
            cout<<root->data<<" ";
            prefix(root->left);
            prefix(root->right);
        }
    }
    void postfix(node* root)
    {
        if(root!=NULL)
        {
            postfix(root->left);
            postfix(root->right);
            cout<<root->data<<" ";
        }
    }
    void smallest(node *root)
    {
        while(root!=NULL)
            root=root->left;
        cout<<root;
    }
    void largest(node *root)
    {
        while(root!=NULL)
            root=root->right;
        cout<<root;
    }
    void remove(node *root,int data)
    {
        if(root==NULL)
            cout<<"Not found";
        else if(root->data<data)
        {
            remove(root->right,data);
        }
        else if(root->data>data)
        {
            remove(root->left,data);
        }
        else
        {
            root=root->left;
            while(root!=NULL)
                root=root->right;
        }
    }
};
int main()
{
    BST b;
    b.root = b.insert(b.root,15);
    b.root = b.insert(b.root,10);
    b.root = b.insert(b.root,20);
    b.infix(b.root);
    cout<<endl;
    b.postfix(b.root);
    cout<<endl;
    b.prefix(b.root);
    cout<<endl;
    b.smallest(b.root);
    cout<<endl; 
}