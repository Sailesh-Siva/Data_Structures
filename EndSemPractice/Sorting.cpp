#include<iostream>
using namespace std;
void bubblesort(int arr[],int n)
{   
    int walker,current=0;
    while(current<n)
    {
        walker=n-1;
        while(walker>current)
        {
            if(arr[walker]<arr[current])
            {
                swap(arr[walker],arr[current]);
            }
            walker--;
        }
        current++;
    }
}
void insertionsort(int arr[],int n)
{
    int walker,temp,current=1,counter=0;
    bool flag=true;
    while(current<n)
    {
        temp=arr[current];
        walker=current-1;
        while(walker>=0 and temp<arr[walker])
        {
            arr[walker+1]=arr[walker];
            walker--;
        }
        arr[walker+1]=temp;
        current++;
    }    
}
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int arr[]={6,1,4,3,8,9,10,43,27,42,85},n=11;
    //bubblesort(arr,n);
    insertionsort(arr,n);
    display(arr,n);
}