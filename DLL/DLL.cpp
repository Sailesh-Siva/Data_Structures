#include <iostream>
#include <string>
#define size 5
using namespace std;

struct node
{
    int data;
    node *fore;
    node *back;
};
struct list
{
    int count;
    node *head;
    node *rear;
};
class DLL
{
    public:
	list *l;
    node *pred,*succ;
    bool found;
	DLL()
    {
        l = new list;
        l->count=0;
        l->head=NULL;
        l->rear=NULL;
	}
    bool listfull()
    {
        list *temp = new list;
        if(temp==NULL)
            return true;
        else
            return false;
    }
    bool listempty()
    {
        return(l->count==0);
    }
    void searchList(int target)
    {
        pred=NULL;
        succ=l->head;
        while(succ!=NULL && target > succ->data)
        {
            pred=succ;
            succ=succ->fore;
        }
        if(succ==NULL)
        {
            found=false;
        }
        else
        {
            if(target==succ->data)
                found=true;
            else
                found=false;
        }
    }
    void insert(int d)
    {
        if(listfull())
        {
            cout<<"List is full";    
            return;
        }
        searchList(d);
        if(!found)
        {
            node *t = new node;
            t->data=d;
            l->count++;
            if(pred==NULL)
            {
                t->back=NULL;
                t->fore=l->head;
                l->head=t;
            }
            else
            {
                t->fore=succ;
                t->back=pred;
                pred->fore=t;
            }
            if(succ==NULL)
                l->rear=t;
            else
                succ=t;
            cout<<"Element Inserted"<<endl;
        }
    }
    void HeadToRear()
    {
        node *pwalker = l->head;
        while(pwalker !=NULL )
        {
            cout<<pwalker->data;
            pwalker=pwalker->fore;
        }
    }
};
int main()
{   
    DLL d;
    d.insert(10);
    d.insert(20);
    d.insert(30);
    d.HeadToRear();
}