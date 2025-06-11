
#include<iostream>
#define size 5
using namespace std;
struct node
{
    int data;
    node *link;
};
struct queuemetadata
{
    int count;
    node *front;
    node *rear;
};
class Queue
{
	queuemetadata *qm;
	public:
	Queue()
	{
		qm=NULL;  
	}
    void createQueue()
    {
        qm=new queuemetadata();
        qm->count=0;
        qm->front=NULL;
        qm->rear=NULL;
    }
	void enqueue(int d)
	{
		node *t = new node;
        t->data= d;
        
        if(qm->rear==NULL)
        {   
            qm->front=t;

        }
        else
            qm->rear->link=t;
        qm->rear=t;
        t->link=NULL;
        qm->count++;
	}
    void dequeue(int &d) 
    {
        if (qm->count==0) 
        {
            cout << "Can't Perform" << endl;
            return;
        }
        if (qm->count==1) 
        {
            d = qm->front->data;
            delete qm->front;
            qm->front=NULL;      
            qm->rear = NULL;
        }
        else
        {
            node *temp = qm->front;
            d = qm->front->data;
            qm->front=qm->front->link; 
            delete temp;
        }
        qm->count--;
    }
    int queueFront(int &d)
	{
        if(qm->front==NULL)
            cout<<"Can't Perform"<<endl;
        else
		    d=qm->front->data;
	}
    int queueRear(int &d)
	{
        if(qm->rear==NULL)
            cout<<"Can't Perform"<<endl;
        else
		    d=qm->rear->data;
	}
    void fullQueue()
	{
		node *t = new node;
        
        if(t==NULL)
            cout<<"Queue is full"<<endl;
        else
            cout<<"Queue is not full"<<endl;
	}
    void emptyQueue()
	{     
        if(qm->count==0)
            cout<<"Queue is empty"<<endl;
        else
            cout<<"Queue is not empty"<<endl;
	}
    void traversal()
	{
        if(qm->front==NULL)
            cout<<"No data present"<<endl;
        else
        {
            for(node *temp=qm->front;temp!=NULL;temp=temp->link)
            {
                cout<<temp->data<<" ";
            }
        }
        cout<<endl;
	}
	void destroyQueue()
	{
        if(qm->rear==NULL)
            cout<<"No data present"<<endl;
        else
        {
            node *temp= qm->front;
            while(qm->front!=NULL)
            {
                qm->front=qm->front->link;
                delete temp;
            }
        }
        delete qm;
	}
};
int main()
{
	Queue s;
	int data,loc,opt;
    s.createQueue();
	do
	{
		cout<<"Enter"<<endl
			<<"1 Enqueue"<<endl
			<<"2 Dequeue"<<endl
			<<"3 Queue Front"<<endl
			<<"4 Queue Rear"<<endl
			<<"5 Full Queue"<<endl
			<<"6 Empty Queue"<<endl
            <<"7 Traversal"<<endl
            <<"8 Destroy Queue"<<endl;
		cin>>opt;
		switch(opt)
		{
			case 1:
			    cout<<"Enter element to be enqueued"<<endl;
			    cin>>data;
			    s.enqueue(data);
			    break;
			case 2:
                s.dequeue(data);
                cout<<data<<endl;
			    break;
			case 3:
                s.queueFront(data);
                cout<<data<<endl;
			    break;
            case 4:
                s.queueRear(data);
                cout<<data<<endl;
			    break;
			case 5:
                s.fullQueue();       
			    break;
			case 6:
                s.emptyQueue();        
				cout<<data;
			    break;
			case 7:
                s.traversal();
			    break;
            case 8:
                s.destroyQueue();
			    break;
			default:
			    cout<<"Enter vaild option"<<endl;		
			    break;
		}	
		cout<<"Do you want to continue 1 for yes 0 for no"<<endl;
		cin>>opt;
	}while(opt==1);
}