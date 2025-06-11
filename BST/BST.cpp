#include<iostream>
using namespace std;

struct node{
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
    node* addBST(node *root,int data)
    {
        if(root==NULL)
        {
            node *newnode=new node;
            newnode->data=data;
            newnode->left=NULL;
            newnode->right=NULL;
            return newnode;
        }
        if(data<root->data)
            root->left=addBST(root->left,data);
        else
            root->right=addBST(root->right,data);
        return root;
    }
    node* deleteBST(node *root,int data)
    {
        if(root==NULL)
            return root;
        if(data<root->data)
            root->left=deleteBST(root->left,data);
        else if(data>root->data)
            root->right=deleteBST(root->right,data);
        else{
            if(root->left==NULL)
            {
                node *deletenode=root;
                root=root->right;
                delete deletenode;
                return root;
            }
            else if(root->right==NULL)
            {
                node *deletenode=root;
                root=root->left;
                delete deletenode;
                return root;
            }
            else
            {
                node *deletenode=root->left;
                while(deletenode->right!=NULL)
                {
                    deletenode=deletenode->right;
                }
                root->data=deletenode->data;
                root->left=deleteBST(root->left,deletenode->data);
                delete deletenode;
                return root;
            }
        }
        return root;
    }
    void searchBST(node *root,int data)
    {
        if(root==NULL)
        {
            cout<<"Element Not Found";
            return;
        }
        if(data<root->data)
            searchBST(root->left,data);
        else if(data>root->data)
            searchBST(root->right,data);
        else
            cout<<"Element Found";
    }
    void preorder(node *root)
    {
        if(root!=NULL)
        {
            cout<<root->data<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void inorder(node *root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }
    void postorder(node *root)
    {
        if(root!=NULL)
        {
            postorder(root->left);
            postorder(root->right);
            cout<<root->data<<" ";
        }
    }
    void findlargestBST(node *root)
    {
        if(root->right==NULL)
            cout<<root->data;
        else
            findlargestBST(root->right);
    }
    void findsmallestBST(node *root)
    {
        if(root->left==NULL)
            cout<<root->data;
        else
            findsmallestBST(root->left);
    }
};

int main()
{
    BST t;
    int op,data;
    cout<<"\t\t1.Insert\n\t\t2.Traversal\n\t\t3.Find Smallest";
    cout<<"\n\t\t4.Find largest\n\t\t5.Search\n\t\t6.Delete\n\t\t7.Exit\n";
    do{
        cout<<"Enter The Option: ";
        cin>>op;
        switch(op)
        {
            case 1: 
                cout<<"Enter The Data to be Added: ";
                cin>>data;
                t.root=t.addBST(t.root,data);
                break;
            case 2: 
                cout<<"\t\t1.Preorder\n\t\t2.Inorder\n\t\t3.Postorder\n";
                cout<<"Enter The Choice: ";
                cin>>data;
                switch(data)
                {
                    case 1:
                        t.preorder(t.root);
                        break;
                    case 2:
                        t.inorder(t.root);
                        break;
                    case 3:
                        t.postorder(t.root);break;
                        default:cout<<"Invalid Choice";
                }
                cout<<endl;
                break;
            case 3: 
                t.findsmallestBST(t.root);
                cout<<endl;
                break;
            case 4: 
                t.findlargestBST(t.root);
                cout<<endl;
                break;
            case 5: 
                cout<<"Enter The Element to be Searched: ";
                cin>>data;
                t.searchBST(t.root,data);
                cout<<endl;
                break;
            case 6: 
                cout<<"Enter The Element to be Deleted: ";
                cin>>data;
                t.root=t.deleteBST(t.root,data);
                cout<<endl;
                break;
            case 7: 
                cout<<"Tree Ended"<<endl;
                break;
            default:cout<<"Invalid Choice"<<endl;
        }
    }while(op!=7);
}
