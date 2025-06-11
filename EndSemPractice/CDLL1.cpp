#include<iostream>
using namespace std;
struct node
{
    node *nextnode;
    int data;
    node *previousnode;
};
struct nodemd
{
    node *first;
    int count;
    node *last;
};
class CDLL
{
    public:
    nodemd *md;
    CDLL()
    {
        md=new nodemd;
        md->first=NULL;
        md->last=NULL;
        md->count=0;
    }
    void insert(int d)
    {
        node *n = new node;
        n->data=d;
        n->nextnode=NULL;
        n->previousnode=NULL;
        if(md->count==0)
        {
            md->first = n;
            n->nextnode = n;
            n->previousnode = n;
            md->last = n;
        }
        else
        {
            node *temp=md->first;
            node *temp1;
            int i=0;
            while(i<md->count && temp->data<n->data)
            {
                temp1=temp;
                temp=temp->nextnode;
                i++;
            }
            if(i==md->count)
            {
                md->last=n;
            }
            n->nextnode=temp;
            temp->previousnode=n;
            n->previousnode=temp1;
            temp1->nextnode=n;
        }
        md->count++;
    }
    void display()
    {
        node *temp = md->first;
        int counter=md->count;
        while(counter>0)
        {
            cout<<temp->data<<" ";
            temp=temp->nextnode;
            counter--;
        }
    }
    void search(int s)
    {

        node *temp1 = md->first,*temp2 = md->last;
        int counter1=0,counter2=0;
        while(counter1<md->count)
        {
            if(s==temp1->data)
            {
                break;
            }
            temp1=temp1->nextnode;
            counter1++;
        }
        while(counter2<md->count)
        {
            if(s==temp2->data)
            {
                break;
            }
            temp2=temp2->previousnode;
            counter2++;
        }
        if(counter1<counter2)
        {
            cout<<"1";
        }
        else if(counter2<counter1)
        {
            cout<<"2";
        }
        else
        {
            cout<<"Equal";
        }
        cout<<endl;
    }

};
int main()
{
    CDLL cd;
    cd.insert(1);
    cd.insert(2);
    cd.insert(5);
    cd.insert(4);
    cd.insert(6);
    cd.display();
    cout<<endl;
    cd.search(2);
    cd.search(4);
    cd.search(5);
}