#include<iostream>
#include<string.h>
using namespace std;
struct node
{
    char data;
    node *link;
};
class stack
{
    public:
    node *top;
    stack()
    {
        top=NULL;
    }
    void push(char c)
    {
        node *temp = new node;
        temp->data=c;
        temp->link=NULL;
        if(top!=NULL)
        {
            temp->link=top;       
        }
        top=temp;
    }
    void pop(char &c)
    {
        node *temp = new node;
        if(top!=NULL)
        {
            c=top->data;
            top=top->link;
        }
    }
    char stacktop()
    {
        if(top!=NULL)
        {
            return top->data;
        }
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
    bool emptyStack()
    {
        return (top == NULL);
    }
};
int main()
{
    string infix,postfix;
    stack s;
    char c;
    cin>>infix;
    for(int i=0;i<infix.length();i++)
    {
        if(infix[i]=='(')
            s.push(infix[i]);    
        else if(infix[i]==')')
        {
           s.pop(c);
           while(!s.emptyStack() && c!='(')
           {
              postfix+=c;
              s.pop(c);
           }
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            while (!s.emptyStack() && s.priority(infix[i]) <= s.priority(s.stacktop()))
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