#include<iostream>
#define size 5
using namespace std;
struct node
{
    int data;
    node *link;
};
struct stackmetadata
{
    int count;
    node *top;
};
class Stack
{
	stackmetadata *sm;
	public:
	Stack()
	{
		sm=NULL;  
	}
    void createStack()
    {
        sm=new stackmetadata();
        sm->count=0;
        sm->top=NULL;
    }
	void push(int d)
	{
		node *t = new node;
        t->data= d;
        t->link = sm->top;
        sm->top=t;
        sm->count++;
	}
	void pop(int &d)
	{
        if(sm->top==NULL)
            cout<<"Can't Perform"<<endl;
        else
        {
		    node *t = sm->top;
            sm->top=sm->top->link;
            d=t->data;
            delete t;
        }
        sm->count--;
	}
    int stackTop(int &d)
	{
        if(sm->top==NULL)
            cout<<"Can't Perform"<<endl;
        else
		    d=sm->top->data;
	}
    void fullStack()
	{
		node *t = new node;
        
        if(t==NULL)
            cout<<"Stack is full"<<endl;
        else
            cout<<"Stack is not full"<<endl;
	}
    void emptyStack()
	{     
        if(sm->count==0)
            cout<<"Stack is empty"<<endl;
        else
            cout<<"Stack is not empty"<<endl;
	}
	void traversal()
	{
        if(sm->top==NULL)
            cout<<"No data present"<<endl;
        else
        {
            for(node*temp=sm->top;temp!=NULL;temp=temp->link)
            {
                cout<<temp->data<<" ";
            }
        }
        cout<<endl;
	}
    void destroyStack()
	{
		node *pnew1 = NULL;
        node *pnew2 = sm->top;
        while(pnew2!=NULL){
            pnew1=pnew2;
            pnew2=pnew2->link;
            delete pnew1;
        }
        delete sm;
	}
};
int main()
{
	Stack s;
	int data,loc,opt;
    s.createStack();
	do
	{
		cout<<"Enter"<<endl
			<<"1 Push"<<endl
			<<"2 Pop"<<endl
			<<"3 Stack sm"<<endl
			<<"4 Full Stack"<<endl
			<<"5 Empty Stack"<<endl
			<<"6 Destroy Stack"<<endl
            <<"7 Traversal"<<endl;
		cin>>opt;
		switch(opt)
		{
			case 1:
			    cout<<"Enter element to be pushed"<<endl;
			    cin>>data;
			    s.push(data);
			    break;
			case 2:
                s.pop(data);
                cout<<data<<endl;
			    break;
			case 3:
                s.stackTop(data);
                cout<<data<<endl;
			    break;
            case 4:
			    s.fullStack();
			    break;
			case 5:
                s.emptyStack();
			    break;
			case 6:
                s.destroyStack();
				cout<<data;
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