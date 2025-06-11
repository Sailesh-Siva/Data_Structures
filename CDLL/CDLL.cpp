#include<iostream>
using namespace std;
class node
{
    public:
    node *next, *previous;
    int data;
    node()
    {
        next=NULL;
        previous=NULL;
        data=0;
    }
};
class nodemetadata
{
    public:
    node *first,*last;
    int count;
    nodemetadata()
    {
        first=NULL;
        last=NULL;
        count=0;
    }
};

class CDLL
{
    public:
    nodemetadata *nm;
    
    CDLL()
    {
        nm=new nodemetadata;
    }
    void add(int d)
    {
        node *n = new node;
        n->data=d;
        if(nm->first==NULL)
        {
           nm->first=n;
           nm->last=n; 
           nm->count++;
           n->next=n;
           n->previous=n;
        }
        else if(d>nm->last->data)
        {
            nm->last->next=n;
            n->previous=nm->last;
            nm->last=n;
            nm->count++;

            n->next=nm->first;
            nm->first->previous=nm->last;
        }
        else if(d<nm->first->data)
        {
            n->next=nm->first;
            nm->first->previous=n;
            nm->first=n;
            nm->count++;

            n->previous=nm->last;
            nm->last->next=nm->first;
        }
        else
        {
            node *temp1 = new node;
            node *temp2 = new node;
            temp1=nm->first;
            while(d>temp1->data)
            {  
                temp2=temp1;
                temp1=temp1->next;
            }
            temp2->next=n;
            n->previous=temp2;
            temp1->previous=n;
            n->next=temp1;
            nm->count++;
        }
    }
    void backtraversal()
    {
        node *temp = nm->last;
        int counter=nm->count;
        while(counter!=0)
        {
            cout<<temp->data<<" ";
            temp=temp->previous;
            counter--;
        }
    }
    void remove(int d)
    {
        node *temp1 = nm->first;
        node *temp2;
        int counter=nm->count;
        while(counter!=0)
        {
            if(temp1->data==d)
            {
                temp2=temp1->previous->next=temp1->next;
                temp1->next->previous=temp1->previous;
            }
            temp1=temp1->next;
            counter--;
        }
        nm->count--;
    }
};
int main()
{
    CDLL c;
    c.add(1);
    c.add(4);
    c.add(8);
    c.add(7);
    c.add(10);
    c.add(3);
    c.backtraversal();
    c.remove(7);
    c.backtraversal();
}