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