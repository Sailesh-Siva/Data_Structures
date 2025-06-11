#include<iostream>
using namespace std;
struct ga;
struct gv
{
    gv* nextvertex;
    char name;
    bool intree;
    ga* firstarc;
};
struct ga
{
    gv* adj;
    int weight;
    ga* link;
};
class MST
{
    public:
    gv *first;
    MST()
    {
        first=NULL;
    }
    void insertv(char d)
    {
        gv *n = new gv;
        n->name=d;
        n->firstarc=NULL;
        n->intree=false;
        n->nextvertex=NULL;
        if(first==NULL)
        {
            first=n;
        }
        else
        {
            gv* temp = first;
            while(temp->nextvertex!=NULL)
            {
                temp=temp->nextvertex;
            }
            temp->nextvertex=n;
        }
    }
    void inserta(char a,char b,int w)
    {
        gv *temp1 = first;
        gv *temp2 = first;
        while(temp1!=NULL && temp1->name!=a)
            temp1=temp1->nextvertex;
        while(temp2!=NULL && temp2->name!=b)
            temp2=temp2->nextvertex;
        if(temp1==NULL || temp2 == NULL)
            cout<<"Wrong Insertion";
        else
        {
            ga *n =new ga;
            n->adj=temp2;
            n->weight=w;
            n->link=temp1->firstarc;
            temp1->firstarc=n;

            n=new ga;
            n->adj=temp1;
            n->weight=w;
            n->link=temp2->firstarc;
            temp2->firstarc=n;
        }        
    }
    void display()
    {
        gv *v=first;
        while(v!=NULL)
        {
            ga* a=v->firstarc;
            cout<<v->name<<"->";
            while(a!=NULL)
            {
                cout<<a->adj->name<<",";
                a=a->link;
            }
            cout<<"null"<<endl;
            v=v->nextvertex;
        }
    }
    void mstop()
    {
        if(first==NULL)
            return;
        gv *temp=first;
        while(temp!=NULL)
        {
            temp->intree=false;
            temp=temp->nextvertex;
        }
        temp = first;
        bool tcomp=false;
        temp->intree=true;
        int sum = 0;
        while(!tcomp)
        {
            tcomp=true;
            int minedge=9999;
            gv *src=NULL;
            ga *mineedgeloc=NULL;
            temp = first;
            while(temp!=NULL)
            {
                if(temp->intree==true && temp->firstarc!=NULL)
                {
                    ga *a=temp->firstarc;
                    while(a!=NULL)
                    {
                        if(a->adj->intree==false)
                        {
                            tcomp=false;
                            if(a->weight<minedge)
                            {
                                minedge=a->weight;
                                mineedgeloc=a;
                                src=temp;
                            }
                        }
                        a=a->link;
                    }
                }
                temp=temp->nextvertex;
            }
            if(mineedgeloc!=NULL)
            {
                sum+=minedge;
                mineedgeloc->adj->intree=true;
                cout<<src->name<<"---"<<minedge<<"---"<<mineedgeloc->adj->name <<endl;
            }
        }
        cout<<"Cost of MST = "<<sum<<endl;
    }
};
int main(){
MST gph;
char op,data1,data2;
int weight;
cout<<"\t\t1.Insert Vertex\n\t\t2.Insert Arc\n\t\t3.Display\n\t\t4.Minimum Spanning Tree\n\t\t5.Exit\n";
do{
cout<<"Enter The Choice: ";
cin>>op;
switch(op){
case '1':cout<<"Enter Vertex: ";
cin>>data1;
gph.insertv(data1);
break;
case '2':cout<<"Enter Edge: ";
cin>>data1>>data2;
cout<<"Enter Weight of the Edge: ";
cin>>weight;
gph.inserta(data1,data2,weight);
break;
case '3':gph.display();
cout<<endl;
break;
case '4':gph.mstop();
break;
case '5':cout<<"Exited"<<endl;
break;
default:cout<<"Invalid Choice"<<endl;
}
}while(op!='5');
}
