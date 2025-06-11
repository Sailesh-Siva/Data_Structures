#include<iostream>
#include<string.h>
using namespace std;
struct ga;
struct gv
{
    char data;
    ga* firstarc;   
    gv* nextvertex;
    bool inqueue,processed;
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
class Queue
{
    public:
    node *begin,*end;
    Queue()
    {
        begin=end=NULL;
    }
    void enqueue(gv *v)
    {
        node *n = new node;
        n->data=v;
        n->link=NULL;
        if(begin==NULL)
        {
            begin=end=n;
        }
        else
        {
            begin->link=n;
            end=n;
        }
    }
    gv * dequeue()
    {
        gv *temp;
        if(begin==NULL)
        {}
        else
        {
            temp=begin->data;
            begin=begin->link; 
            if(begin==NULL)
                end=NULL;
            return temp;
        }
    }
    bool queueEmpty()
    {
        return begin==NULL;
    }
};
class BFS
{
    public:
    gv *first;
    BFS()
    {
        first=NULL;
    }
    void insertv(char c)
    {
        gv *n = new gv;
        n->data=c;
        n->firstarc=NULL;
        n->nextvertex=NULL;
        n->inqueue=false;
        n->processed=false;
        if(first==NULL)
        {
            first=n;
        }
        else
        {
            gv *temp=first;
            while(temp->nextvertex!=NULL)
            {
                temp=temp->nextvertex;        
            }
            temp->nextvertex=n;
        }
    }
    void inserta(char a,char b)
    {
        gv *temp1=first,*temp2=first;
        while(temp1!=NULL && temp1->data!=a)
            temp1=temp1->nextvertex;
        while(temp2!=NULL && temp2->data!=b)
            temp2=temp2->nextvertex;
        if(temp1==NULL || temp2==NULL)
        {
            cout<<"Wrong Entry"<<endl;
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
        }
    }
    void bfsop()
    {
        if(first==NULL)
            return;
        Queue q;
        gv *v = first;
        while(v!=NULL)
        {
            
            v->processed=false;
            v=v->nextvertex;
        }
        
        gv *t=first;
        //v=first;
        while(t!=NULL) //v!=null
        {
            v=t; //assigning the inner variable
            if(v->processed==false)
            {
                if(v->inqueue==false)
                {
                    q.enqueue(v);
                    v->inqueue=true;
                }
                while(!q.queueEmpty())
                {
                    v=q.dequeue();
                    v->processed=true;
                    v->inqueue=false;
                    cout<<v->data<<" ";
                    ga *dest = v->firstarc;
                    while(dest!=NULL)
                    {
                        if(dest->adj->inqueue == false && dest->adj->processed == false)
                        {
                            q.enqueue(dest->adj);
                            dest->adj->inqueue=true;
                        }
                        dest=dest->link;
                    }
                }
            }
            t=t->nextvertex; //v=v->next vertex
        }
    }
};
int main()
{
    BFS bfs;
    char op,data1,data2;
    cout<<"\t\t1.Insert Vertex\n\t\t2.Insert Arc\n\t\t3.Breadth First Traversal\n\t\t4.Exit\n";
    do{
    cout<<"Enter The Choice: ";
    cin>>op;
        switch(op)
        {
            case '1':cout<<"Enter Vertex: ";
            cin>>data1;
            bfs.insertv(data1);
            break;
            case '2':cout<<"Enter Edge: ";
            cin>>data1>>data2;
            bfs.inserta(data1,data2);
            break;
            case '3':bfs.bfsop();
            cout<<endl;
            break;
            case '4':cout<<"Exited"<<endl;
            break;
            case '5':
            {
            gv *temp = bfs.first;
            while(temp!=NULL)
            {
                cout<<temp->data;
                temp=temp->nextvertex;
            }
            break;
            }
            default:cout<<"Invalid Choice"<<endl;
        }
    }while(true);
}
