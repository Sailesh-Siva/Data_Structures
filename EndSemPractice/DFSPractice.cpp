#include<iostream>
using namespace std;
struct ga;
struct gv{
gv* nextvertex;
char name;
bool processed;
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
class Stack{
node* top;
public:
Stack(){
top=NULL;
}
void pushStack(gv* v){
node* nn=new node;
nn->data=v;
nn->link=top;
top=nn;
}
gv* popStack(){
if(top==NULL)
return NULL;
else{
gv* t=top->data;
top=top->link;
return t;
}
}
gv* stackTop(){
if(top==NULL)
return NULL;
else
return top->data;
}
};
class DFS{
int count;
gv* first;
public:
DFS(){
count=0;
first=NULL;
}
void insertVertex(char d){
gv* nn=new gv;
nn->name=d;
nn->processed=false;
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
count++;
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
void depthFirstTraversal(){
if(first==NULL)return;
Stack S;
int nov=0;
gv* v=first;
while(v!=NULL){
v->processed=false;
v=v->nextvertex;
}
v=first;
S.pushStack(v);
v->processed=true;
nov++;
cout<<v->name<<" ";
while(nov!=count){
v=S.stackTop();
ga* a=v->firstarc;
while(a!=NULL&&a->adj->processed==true)
a=a->link;
if(a!=NULL){
S.pushStack(a->adj);
a->adj->processed=true;
nov++;
cout<<a->adj->name<<" ";
}
else{
S.popStack();
if(S.stackTop()==NULL){
v=first;
while(v!=NULL&&v->processed==true)
v=v->nextvertex;
if(v!=NULL){
S.pushStack(v);
v->processed=true;
nov++;
cout<<v->name<<" ";
}
}
}
}
}
};
main(){
DFS dfs;
char op,data1,data2;
cout<<"\t\t1.Insert Vertex\n\t\t2.Insert Arc\n\t\t3.Depth First Traversal\n\t\t4.Exit\n";
do{
cout<<"Enter The Choice: ";
cin>>op;
switch(op){
case '1':cout<<"Enter Vertex: ";
cin>>data1;
dfs.insertVertex(data1);
break;
case '2':cout<<"Enter Edge: ";
cin>>data1>>data2;
dfs.insertArc(data1,data2);
break;
case '3':dfs.depthFirstTraversal();
cout<<endl;
break;
case '4':cout<<"Exited"<<endl;
break;
default:cout<<"Invalid Choice"<<endl;
}
}while(op!='4');
}