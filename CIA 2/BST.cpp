#include<iostream>
#include<string.h>
using namespace std;

struct node
{
    public:
    string name;
    int price,expdate;
    node *left, *right;
};

class BST
{
    public:
    node *root,*hnode;
    int hprice,expfind;
    string delarr;
    BST()
    {
        delarr="";
        root=NULL;
        hnode=NULL;
        hprice=0;
    }
    node* insert(node * root,string n,int p,int e)
    {
        node *nn = new node;
        nn->name=n;
        nn->price=p;
        nn->expdate=e;
        nn->left=NULL;
        nn->right=NULL;

        if(root == NULL)
        {
            root = nn;
            return root;
        }
        else if (root->name.compare(nn->name)>0)
        {
            root->left=insert(root->left,n,p,e);
        }
        else if (root->name.compare(nn->name) <= 0)
        {
            root->right=insert(root->right,n,p,e);
        }
        return root;
    }
    void infix(node *root)
    {
        if(root!=NULL)
        {
            infix(root->left);
            cout<<root->name;
            infix(root->right);
        }   
    }
    void highestprice(node *root)
    {
        if(root!=NULL)
        {
            highestprice(root->left);
            if(root->price>hprice)
            {
                hprice=root->price;
                hnode=root;
            }
            highestprice(root->right);
        }   
    }
    void expfinder(node *root)
    {
        if(root!=NULL)
        {
            expfinder(root->left);
            if(root->expdate>expfind)
            {
                delarr.append(root->name);  
            }
            expfinder(root->right);
        }   
    }
    node* delexp(node * root,string n)
    {
        if(root == NULL)
        {
            return root;
        }
        else if (root->name.compare(n)>0)
        {
            root->left=delexp(root->left,n);
        }
        else if (root->name.compare(n) < 0)
        {
            root->right=delexp(root->right,n);
        }
        else
        {
            if(root->left==NULL)
            {
                node *temp = root;
                root=root->right;
                delete temp;
            }
            else if(root->right==NULL)
            {
                node *temp = root;
                root=root->left;
                delete temp;
            }
            else
            {
                node *temp = root->left;
                while(temp->right!=NULL)
                    temp=temp->right;
                root=temp;
                root->left=delexp(root->left,temp->name);
                delete temp;
            }
        }
        return root;
    }

};

int main()
{
    BST bs;
    
    bs.root=bs.insert(bs.root,"a",10,2010);
    bs.root=bs.insert(bs.root,"b",20,2020);
    bs.root=bs.insert(bs.root,"c",70,2030);
    bs.root=bs.insert(bs.root,"d",40,2040);
    bs.root=bs.insert(bs.root,"e",50,2050);
    bs.root=bs.insert(bs.root,"f",60,2060);

    bs.expfind=2040;
    
    bs.infix(bs.root);
    cout<<endl;
    bs.highestprice(bs.root);
    cout<<bs.hnode->name<<" "<<bs.hnode->price<<" "<<bs.hnode->expdate; 
    bs.expfinder(bs.root);
    for(int i=0;i<bs.delarr.length();i++)
    {
        string temp;
        temp += bs.delarr[i];
        bs.delexp(bs.root,temp);
    }
    cout<<endl;
    bs.infix(bs.root);
}