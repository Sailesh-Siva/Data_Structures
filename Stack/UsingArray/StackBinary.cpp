#include<iostream>
#define size 100
using namespace std;
class Stack
{
	int a[size],top;
	public:
	Stack()
	{
		top=-1;
	}
	void binary(int n)
	{
		int i,r;
		for(i=n;i>0;i=i/2)
		{
			r=i%2;
			push(r);
		}
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
	int n;
	cin>>n;
	s.binary(n);
	s.display();
}






