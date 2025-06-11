#include<iostream>
#define size 5
using namespace std;
struct node{
    int data;
    node *link;
};
struct list{
    int count;
    node *head;
};
class SLL
{
    public:
	list *slist;
    node *ppre,*ploc;
	SLL()
    {
		slist= NULL;
	}
    void createList()
    {
        slist = new list;
        slist->count=0;
        slist->head=NULL;
    }
    void fullList()
	{
		node *t = new node;
        
        if(t==NULL)
            cout<<"List is full"<<endl;
        else
            cout<<"List is not full"<<endl;
	}
    void emptylist()
	{     
        if(slist->count==0)
            cout<<"List is empty"<<endl;
        else
            cout<<"List is not empty"<<endl;
	}
	bool search(int target)
	{
		ploc = slist->head;
        ppre =NULL;
        while(ploc!=NULL && target>ploc->data)
        {
            ppre=ploc;
            ploc=ploc->link;
        }
        if(ploc!=NULL && target==ploc->data)
        {
            return true;
        }
        else
        {
            return false;
        }
	}
    void insertNode(int d)
    {

        if(!search(d))
        {
            node *pnew = new node;
            pnew->data=d;

            if(ppre==NULL)
            {
                pnew->link=slist->head;
                slist->head=pnew;
            }
            else
            {
                pnew->link=ppre->link;
                ppre->link=pnew;
            }
            slist->count++;     
        }
        else
        {
            cout<<"Element found can't insert"<<endl;
        }
    }
    void deleteNode(int &d)
    {
        if(search(d))
        {
            ploc->data=d;
            if(ppre==NULL)
            {
                slist->head=ploc->link;
            }
            else{
                ppre->link=ploc->link;
            }
            delete ploc;
            slist->count--;
        }
        else
        {
            cout<<"Element not found can't delete"<<endl;
        }
    }

    int listCount()
    {
        return slist->count;
    }
    void traversal()
	{
		node *pnew = slist->head;
        while(pnew!=NULL){
            cout<<pnew->data<<" ";
            pnew=pnew->link;
        }
        cout<<endl;
	}
    void destroyList()
	{
		node *pnew1 = NULL;
        node *pnew2 = slist->head;
        while(pnew2!=NULL){
            pnew1=pnew2;
            pnew2=pnew2->link;
            delete pnew1;
        }
        slist->head=NULL;
        slist->count=0;
	}
};
int main()
{
	SLL s;
    int data,opt;
	node *ppre=NULL,*ploc=NULL;
    s.createList();
    do
	{
	    cout<<"Enter"<<endl
			<<"1 for Insert"<<endl
			<<"2 for Delete"<<endl
			<<"3 for List count"<<endl
			<<"4 for Empty List"<<endl
			<<"5 for Full List"<<endl
            <<"6 for Traversal"<<endl
            <<"7 for Delete List"<<endl;
		cin>>opt;
		switch(opt)
		{
			case 1:
			    cout<<"Enter element to be inserted "<<endl;
			    cin>>data;
                s.insertNode(data);
			    break;
			case 2:
                cout<<"Enter element to be deleted "<<endl;
			    cin>>data;
                s.deleteNode(data);
                cout<<data<<endl;
			    break;
            case 3:
			    s.listCount();
				cout<<data;
			    break;
			case 4:
                s.emptylist();
			    break;
			case 5:
                s.fullList();
			    break;
			case 6:
			    s.traversal();
			    break;
            case 7:
			    s.destroyList();
			    break;    
			default:
			    cout<<"Enter vaild option"<<endl;		
			    break;
		}	
		cout<<"Do you want to continue 1 for yes 0 for no"<<endl;
		cin>>opt;
	}while(opt==1);
}