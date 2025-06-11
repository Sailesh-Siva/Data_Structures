#include<iostream>
#define size 5
using namespace std;
class Queue
{
	int a[size],F,R;
	public:
	Queue()
	{
		F=R=-1;
	}
	bool emptyQueue()
	{
		if(F==-1)
			return true;
		else
			return false;
	}
	bool fullQueue()
	{
		if(R==size-1)
			return true;
		else
			return false;
	}
	bool enqueue(int data)
	{
		if(fullQueue())
			return false;
		else
        {
			R++;
			a[R]=data;
            if(F==-1)
                F++;
		    return true;
        }
	}
	bool dequeue(int &d)
	{
		if(emptyQueue())
			return false;
		else
        {
			d=a[F];
			if(F==R)
                F=R=-1;
            else
                F++;
            return true;
        }
	}
	bool queueFront(int &data)
	{
		if(emptyQueue())
			return false;
		else
        {
			data=a[F];
			return true;
        }
    }
    bool queueRear(int &data)
	{
		if(emptyQueue())
			return false;
		else
        {
			data=a[R];
			return true;
        }
    }
	void display()
	{
		int i;
		for(i=F;i<R+1;i++)
		{
			cout<<a[i]<<endl;
		}
	}
};
int main()
{
	Queue q;
	int data,opt;
	do
	{
		cout<<"Enter"<<endl
			<<"1 for Enqueue"<<endl
			<<"2 for Dequeue"<<endl
			<<"3 for Queue Front"<<endl
			<<"4 for Queue Rear"<<endl
			<<"5 for Queue Empty"<<endl
			<<"6 for Queue Full"<<endl
            <<"7 for Display"<<endl;
		cin>>opt;
		switch(opt)
		{
			case 1:
			cout<<"Enter element to be inserted "<<endl;
			cin>>data;
			if(q.enqueue(data))
				
				cout<<"Inserted Successfully"<<endl;
			else
				cout<<"Overflow"<<endl;
			break;
			case 2:
			if(q.dequeue(data))
				cout<<"Deleted element "<<data<<endl;
			else
				cout<<"Underflow"<<endl;
			break;
			case 3:
			if(q.queueFront(data))
				cout<<"Queue Front "<<data<<endl;
			else
				cout<<"Underflow"<<endl;
			break;
            case 4:
            if(q.queueRear(data))
				cout<<"Queue Rear "<<data<<endl;
			else
				cout<<"Underflow"<<endl;
			break;
			case 5:
			if(q.emptyQueue())
				cout<<"Queue is empty"<<endl;
			else
				cout<<"Queue is not empty"<<endl;
			break;
			case 6:
			if(q.fullQueue())
				cout<<"Queue is full"<<endl;
			else
				cout<<"Queue is not full"<<endl;
			break;
			case 7:
			cout<<"Queue is displayed"<<endl;		
			q.display();
			break;
			default:
			cout<<"Enter vaild option"<<endl;		
			break;
		}	
		cout<<"Do you want to continue 1 for yes 0 for no"<<endl;
		cin>>opt;
	}while(opt==1);
}
