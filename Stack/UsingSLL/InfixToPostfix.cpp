#include <iostream>
#include <string.h>
#define size 5
using namespace std;

struct node
{
    char data;
    node *link;
};
struct stackmetadata
{
    int count;
    node *top;
};
class Stack
{
    stackmetadata *sm;

public:
    Stack()
    {
        sm = NULL;
        sm = new stackmetadata();
        sm->count = 0;
        sm->top = NULL;
    }
    void push(char d)
    {
        node *t = new node;
        t->data = d;
        t->link = sm->top;
        sm->top = t;
        sm->count++;
    }
    void pop(char &d)
    {    
        if(sm->top != NULL)
        {
            node *t = sm->top;
            sm->top = sm->top->link;
            d = t->data;
            delete t;
            sm->count--;
        }
    }
    char stackTop()
    {
        if (sm->top != NULL)
            return sm->top->data;  
    }
    bool emptyStack()
    {
        return (sm->count == 0);
    }
    int priority(char c)
    {
        if (c=='^')
            return 3;
        else if (c=='*' || c=='/')
            return 2;
        else if (c=='+' || c=='-')
            return 1;
        else
            return 0;
    }
};
int main()
{
    Stack s;
    string infix,postfix;
    
    char c;
    cin>>infix;
    int i;
    for (i = 0;i<infix.length(); i++)
    {
        if (infix[i] == '(')
            s.push(infix[i]);
        else if (infix[i] == ')')
        {   
            s.pop(c);
            while (!s.emptyStack() && c!='(')
            {
                postfix+=c;
                s.pop(c);
            }
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            while (!s.emptyStack() && s.priority(infix[i]) <= s.priority(s.stackTop()))
            {
                s.pop(c);
                postfix+=c;
            }
            s.push(infix[i]);
        }
        else
        {
            postfix+=infix[i];
        }
    }
    while (!s.emptyStack())
    {
        s.pop(c);
        postfix+=c;
    }
    cout<<postfix;
}