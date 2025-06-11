#include<iostream>
#define size 5
using namespace std;
struct node{
    int data;
    node *link;
};
class SLL
{
	node *first;
	public:
	SLL()
	{
		first = NULL;
	}
	void insertBeg(int d)
	{
		node *t = new node;
        t->data= d;
        t->link = first;
        first=t;
	}
	void insertEnd(int d)
	{
        node*t = new node;
        t->data=d;
		if(first ==NULL)
		{
            first=t;
        }
        else
        {
            node *temp = first;      
		    for(;temp->link!=NULL;temp=temp->link);
            temp->link=t;
        }
         t->link=NULL;
	}
    void insertAtLoc(int d,int loc)
	{
        if(first==NULL)
            cout<<"Can't Perform"<<endl;
        else
        {
            node*t=new node;
            t->data=d;
            node *temp=first;
		    for(int i=0;i<loc-1;i++)
            {
                temp=temp->link;
            }
            t->link=temp->link;
            temp->link=t;
        }
    }
	void deleteBeg(int &d)
	{
        if(first==NULL)
            cout<<"Can't Perform"<<endl;
        else
        {
		    node *t = first;
            first=first->link;
            d=t->data;
            delete t;
        }
	}
    void deleteEnd(int &d) 
    {
        if (first == NULL) 
        {
            cout << "Can't Perform" << endl;
            return;
        }

        if (first->link == NULL) 
        {
            d = first->data;
            delete first;
            first = NULL;
            return;
        }

        node *temp = first;
        node *temp2 = NULL;

        while (temp->link != NULL) 
        {
            temp2 = temp;
            temp = temp->link;
        }

        d = temp->data;
        temp2->link = NULL;
        delete temp;
    }
    void deleteAtLoc(int loc)
	{
        if(first==NULL)
            cout<<"Can't Perform"<<endl;
        else
        {
            node *t1=first;
            node *t2;
		    for(int i=0;i<loc;i++)
            {
                t2=t1;
                t1=t1->link;
            }
            if(loc!=1)
                t2->link=t1->link;
            else
                first=t1->link;
            delete t1;
        }
    }
	void traversal()
	{
        if(first==NULL)
            cout<<"No data present"<<endl;
        else
        {
            for(node*temp=first;temp!=NULL;temp=temp->link)
            {
                cout<<temp->data<<" ";
            }
        }
        cout<<endl;
	}
};
int main()
{
	SLL s;
	int data,loc,opt;
	do
	{
		cout<<"Enter"<<endl
			<<"1 for Insert at beginning"<<endl
			<<"2 for Insert at end"<<endl
			<<"3 for Insert at loc"<<endl
			<<"4 for Delete at beginning"<<endl
			<<"5 for Delete at end"<<endl
			<<"6 for Delete at loc"<<endl
            <<"7 for Traversal"<<endl;
		cin>>opt;
		switch(opt)
		{
			case 1:
			    cout<<"Enter element to be inserted "<<endl;
			    cin>>data;
			    s.insertBeg(data);
			    break;
			case 2:
                cout<<"Enter element to be inserted "<<endl;
			    cin>>data;
                s.insertEnd(data);
			    break;
			case 3:
			    cout<<"Enter element to be inserted and location"<<endl;
			    cin>>data>>loc;
                s.insertAtLoc(data,loc);
			    break;
            case 4:
			    s.deleteBeg(data);
				cout<<data<<endl;
			    break;
			case 5:
                s.deleteEnd(data);
				cout<<data<<endl;
			    break;
			case 6:
                cout<<"Enter the location"<<endl;
			    cin>>loc;
                s.deleteAtLoc(loc);
				cout<<data<<endl;
			    break;
			case 7:
			    s.traversal();
			    break;
			default:
			    cout<<"Enter vaild option"<<endl;		
			    break;
		}	
		cout<<"Do you want to continue 1 for yes 0 for no"<<endl;
		cin>>opt;
	}while(opt==1);
}