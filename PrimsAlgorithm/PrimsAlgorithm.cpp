#include<iostream>
using namespace std;

class arc;
class vertex{
    public:
    bool intree = false;
    char data = '\0';
    arc* farc = NULL, *rarc = NULL;
    vertex* nxtv;
    vertex(char data = '\0') : data(data){}
};

class arc{
    public:
    vertex* adj = NULL;
    arc* link = NULL;
    int wt = 0;
    arc(vertex* adj = NULL, int wt = 0) : adj(adj), wt(wt){}
};

class graph {
    vertex *first, *rear;
    public:
    graph() : first(NULL), rear(NULL){}
    void addVertex(char data){
        vertex* temp = new vertex(data);
        if(first) rear = rear->nxtv = temp;
        else first = rear = temp;
        cout<<"VERTEX INSERTION SUCCESSFUL\n\n";
    }
    void addEdge(char data1, char data2, int wt){
        vertex *d1, *d2;
        d1 = d2 = first;
        for(; d1 and d1->data != data1; d1 = d1->nxtv);
        for(; d2 and d2->data != data2; d2 = d2->nxtv);
        if(not d1 or not d2) {
            cout << "INVALID INPUT\n\n";
            return;
        }
        arc* a = new arc(d1,wt);
        if(d2->farc) d2->rarc = d2->rarc->link = a;
        else d2->rarc = d2->farc = a;
        a = new arc(d2,wt);
        if(d1->farc) d1->rarc = d1->rarc->link = a;
        else d1->rarc = d1->farc = a;
        cout<<"EDGE INSERTION SUCCESSFUL\n\n";
    }
    void display(){
        for(vertex*temp = first; temp; temp = temp->nxtv){
            cout << temp->data <<" --> ";
            for(arc*a = temp->farc; a; a = a->link){
                cout<<a->adj->data<<", ";
            }
            cout<<"NULL\n";
        }
    }
    void prims(){
        if(!first){
            cout<<"EMPTY GRAPH";
            return;
        }
        int min = 9999;
        int sum = 0;
        bool tree_complete = false;
        for(vertex*temp = first; temp; temp = temp->nxtv) temp->intree = false;
        vertex* temp = first, *minedge = NULL, *src = NULL;
        temp->intree = true;
        while(not tree_complete){ 
            tree_complete = true; min = 9999;
            for(temp = first; temp; temp = temp->nxtv){
                if(temp->intree and temp->farc){
                for(arc* a = temp->farc; a; a = a->link){
                    if(!a->adj->intree){
                        tree_complete = false;
                        if(a->wt < min){
                            min = a->wt;
                            minedge = a->adj;
                            src = temp;
                        }
                    }
                }}
            }
            if(minedge){
                sum += min;
                minedge->intree = true;
                cout << src->data << " --( " << min << " )--> " << minedge->data << endl;
            }
        }    
        cout << sum;
    }
};

int main(){
    graph g;
    char arr[] = {'A', 'B', 'C', 'D'};
    for(int i=0; i<4; i++)
        g.addVertex(arr[i]);
    g.addEdge('A', 'B', 1);
    g.addEdge('A', 'C', 2);
    g.addEdge('A', 'D', 1);
    g.addEdge('C', 'D', 2);
    g.addEdge('C', 'B', 3);
    g.display();
    g.prims();
}