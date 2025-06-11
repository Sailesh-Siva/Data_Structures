#include<iostream>
using namespace std;
struct ga;
struct gv
{
    char name;
    bool processed;
    gv *nextvertex;
    ga *firstarc;
};
struct ga
{
    gv *adj;
    ga *link;    
};
struct node
{
    gv *data;
    node *link;
};
class Stack
{
    public:
    node *top;
    Stack()
    {
        top=NULL;
    }
    void push(gv *v)
    {
        node *n = new node;
        n->data=v;
        n->link=NULL;
        if(top!=NULL)
        {
            n->link=top;
        }
        top=n;
    }       
    gv* pop()
    {
        node *n = new node;
        if(top!=NULL)
        {
            n->data=top->data;
            top=top->link;
        }
        return n->data;
    }
    gv *stacktop()
    {
        if(top!=NULL)
            return top->data;
    }
    bool emptystack()
    {
        return top==NULL;
    }
};
class DFS
{
    public:
    gv *first;
    DFS()
    {
        first=NULL;
    }
    void insertv(char d)
    {
        gv *n = new gv;
        n->name=d;
        n->firstarc=NULL;
        n->nextvertex=NULL;
        n->processed=false;
        if(first==NULL)
        {
            first=n;
        }
        else
        {
            gv *temp = first;
            while(temp->nextvertex!=NULL)
            {
                temp=temp->nextvertex;
            }
            temp->nextvertex=n;
        }
    }
    void inserta(char a,char b)
    {
        gv *temp1 = first;
        gv *temp2 = first;
        while(temp1!=NULL && temp1->name!=a)
            temp1=temp1->nextvertex;
        while(temp2!=NULL && temp2->name!=b)
            temp2=temp2->nextvertex;
        if(temp1==NULL || temp2==NULL)
        {
            cout<<"Wrong entry"<<endl;
        }
        else
        {
           
            ga *nn = new ga;
            nn->adj=temp2;
            nn->link=temp1->firstarc;
            temp1->firstarc=nn;

            nn = new ga;
            nn->adj=temp1;
            nn->link=temp2->firstarc;
            temp2->firstarc=nn;
            //cout<<temp1->firstarc->adj->name<<temp2->firstarc->adj->name;
        }
    }
    void dfsop()
    {
        if(first==NULL)
            return;
        Stack s;
        gv *v = first;
        while(v!=NULL)
        {
            v->processed=false;
            v=v->nextvertex;
        }   
        gv *t = first;
        while(t!=NULL)
        {
            v=t;
            if(v->processed==false)
            {
                s.push(v);
                while(s.emptystack()==false)
                {
                    v=s.pop();
                    v->processed=true;
                    cout<<v->name;
                    ga *dest=v->firstarc;
                    while(dest!=NULL)
                    {
                        if(dest->adj->processed==false)
                        {
                            s.push(dest->adj);
                        }
                        dest=dest->link;
                    }
                }
            }
            t=t->nextvertex;
        } 
    }
};
int main()
{
    DFS dfs;
    char op,data1,data2;
    cout<<"\t\t1.Insert Vertex\n\t\t2.Insert Arc\n\t\t3.Breadth First Traversal\n\t\t4.Exit\n";
    do{
    cout<<"Enter The Choice: ";
    cin>>op;
        switch(op)
        {
            case '1':cout<<"Enter Vertex: ";
            cin>>data1;
            dfs.insertv(data1);
            break;
            case '2':cout<<"Enter Edge: ";
            cin>>data1>>data2;
            dfs.inserta(data1,data2);
            break;
            case '3':dfs.dfsop();
            cout<<endl;
            break;
            case '4':cout<<"Exited"<<endl;
            break;
            case '5':
            {
            gv *temp = dfs.first;
            while(temp!=NULL)
            {
                cout<<temp->name;
                temp=temp->nextvertex;
            }
            break;
            }
            default:cout<<"Invalid Choice"<<endl;
        }
    }while(true);
}