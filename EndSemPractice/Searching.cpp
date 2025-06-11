#include<iostream>
using namespace std;
void binarysearch(int arr[],int high,int low,int target)
{   
    int mid = (high+low)/2;
    if(high>=low)
    {
        if(target>arr[mid])
            binarysearch(arr,high,mid+1,target);
        else if(target<arr[mid])
            binarysearch(arr,mid-1,low,target);
        else
        {
            cout<<"Target Found at "<<mid<<endl;
        }
    }
    else
    {
        cout<<"Element Not Found"<<endl;
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
void sequentialsearch(int arr[],int n,int target)
{
    static int i;
    if(i<n)
        if(arr[i]==target)
            cout<<"Element found at "<<i<<endl;
        else    
        {
            i++;
            sequentialsearch(arr,n,target);
        }
    else
        cout<<"Element not found"<<endl;
}
int main()
{
    int arr[]={1,3,4,6,8,9,10,27,42,43,85},n=11;
    binarysearch(arr,n,0,27);
    //sequentialsearch(arr,n,3);
    display(arr,n);
}