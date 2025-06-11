#include<iostream>
using namespace std;
struct ga;
struct gv{
gv* nextvertex;
char name;
bool processed;
bool inqueue;
ga* firstarc;
};
struct ga{
gv* adj;
ga* link;
};
struct node{
gv* data;
node* link;
};
class Queue{
node* rear;
node* front;
public:
Queue(){
front=rear=NULL;
}
void EnQueue(gv* v){
node* nn=new node;
nn->data=v;
nn->link=NULL;
if(front==NULL)
front=nn;
else
rear->link=nn;
rear=nn;
}
gv* DeQueue(){
if(front==NULL)
return NULL;
else{
gv* t=front->data;
front=front->link;
if(front==NULL)
rear=NULL;
return t;
}
}
bool emptyQueue(){
if(rear==NULL)
return true;
else
return false;
}
};
class BFS{
gv* first;
public:
BFS(){
first=NULL;
}
void insertVertex(char d){
gv* nn=new gv;
nn->name=d;
nn->processed=false;
nn->inqueue=false;
nn->nextvertex=NULL;
nn->firstarc=NULL;
if(first==NULL)
first=nn;
else{
gv* temp=first;
while(temp->nextvertex!=NULL)
temp=temp->nextvertex;
temp->nextvertex=nn;
}
}
void insertArc(char d1,char d2){
gv* temp1=first;
gv* temp2=first;
while(temp1!=NULL&&temp1->name!=d1)
temp1=temp1->nextvertex;
while(temp2!=NULL&&temp2->name!=d2)
temp2=temp2->nextvertex;
if(temp1==NULL||temp2==NULL)
cout<<"Wrong Entry"<<endl;
else{
ga* nn=new ga;
nn->adj=temp2;
nn->link=temp1->firstarc;
temp1->firstarc=nn;
nn=new ga;
nn->adj=temp1;
nn->link=temp2->firstarc;
temp2->firstarc=nn;
}
}
void breadthFirstTraversal(){
if(first==NULL)return;
Queue q;
gv* v=first;
while(v!=NULL){
v->processed=false;
v=v->nextvertex;
}
v=first;
while(v!=NULL){
if(v->processed==false){
if(v->inqueue==false){
q.EnQueue(v);
v->inqueue=true;
}
while(!q.emptyQueue()){
v=q.DeQueue();
v->processed=true;
v->inqueue=false;
cout<<v->name<<" ";
ga* dest=v->firstarc;
while(dest!=NULL){
if(dest->adj->inqueue==false&&dest->adj->processed ==false){
q.EnQueue(dest->adj);
dest->adj->inqueue=true;
}
dest=dest->link;
}
}
}
v=v->nextvertex;
}
}
};
main(){
BFS bfs;
char op,data1,data2;
cout<<"\t\t1.Insert Vertex\n\t\t2.Insert Arc\n\t\t3.Breadth First Traversal\n\t\t4.Exit\n";
do{
cout<<"Enter The Choice: ";
cin>>op;
switch(op){
case '1':cout<<"Enter Vertex: ";
cin>>data1;
bfs.insertVertex(data1);
break;
case '2':cout<<"Enter Edge: ";
cin>>data1>>data2;
bfs.insertArc(data1,data2);
break;
case '3':bfs.breadthFirstTraversal();
cout<<endl;
break;
case '4':cout<<"Exited"<<endl;
break;
default:cout<<"Invalid Choice"<<endl;
}
}while(op!='4');
}
