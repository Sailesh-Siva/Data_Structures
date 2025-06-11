#include<iostream>
#define size 5
using namespace std;
class Stack
{
	int a[size],top;
	public:
	Stack()
	{
		top=-1;
	}
	bool emptyStack()
	{
		if(top==-1)
			return true;
		else
			return false;
	}
	bool fullStack()
	{
		if(top==size-1)
			return true;
		else
			return false;
	}
	bool push(int d)
	{
		if(fullStack())
			return false;
		else
			top++;
			a[top]=d;
			return true;
	}
	bool pop(int &d)
	{
		if(emptyStack())
			return false;
		else
			d=a[top];
			top--;
			return true;
	}
	bool stackTop(int &d)
	{
		if(emptyStack())
			return false;
		else
			d=a[top];
			return true;
	}
	void display()
	{
		int i;
		for(i=top;i>-1;i--)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
};
int main()
{
	Stack s;
	int data,opt;
	do
	{
		cout<<"Enter"<<endl
			<<"1 for Push"<<endl
			<<"2 for Pop"<<endl
			<<"3 for Stack Top"<<endl
			<<"4 for Empty Stack"<<endl
			<<"5 for Full Stack"<<endl
			<<"6 for Display"<<endl;
		cin>>opt;
		switch(opt)
		{
			case 1:
			cout<<"Enter element to be inserted "<<endl;
			cin>>data;
			if(s.push(data))
				cout<<"Inserted Successfully"<<endl;
			else
				cout<<"Overflow"<<endl;
			break;
			case 2:
			if(s.pop(data))
				cout<<"Popped element "<<data<<endl;
			else
				cout<<"Underflow"<<endl;
			break;
			case 3:
			if(s.stackTop(data))
				cout<<"Stack Top "<<data <<endl;
			else
				cout<<"Underflow"<<endl;
			break;
			case 4:
			if(s.emptyStack())
				cout<<"Stack is empty"<<endl;
			else
				cout<<"Stack is not empty"<<endl;
			break;
			case 5:
			if(s.fullStack())
				cout<<"Stack is full"<<endl;
			else
				cout<<"Stack is not full"<<endl;
			break;
			case 6:
			cout<<"Stack is displayed"<<endl;		
			s.display();
			break;
			default:
			cout<<"Enter vaild option"<<endl;		
			break;
		}	
		cout<<"Do you want to continue 1 for yes 0 for no"<<endl;
		cin>>opt;
	}while(opt==1);
}






