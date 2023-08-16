#include <iostream>
using namespace std;

void push(int arr[],int &top,int x,int n)
{
    if(top!=n)
    {    arr[top+1]=x;
    top++;
    }
    else    
        cout<<"Cannot push the element - stack is full "<<endl;
}
int pop(int arr[],int &top)
{
    if(top!=-1)
    {
        int x=arr[top];
        top--;
        return x;
    }
    else
        cout<<"Cannot pop - stack is empty "<<endl;
    return -1;
}
int main()
{
    int n;
    cout<<"Enter maximum size of stack : ";
    cin>>n;
    int arr[n+1];
    int top=-1;
    int choice=-1;
    cout<<"----Enter----\n1. push\n2. pop\n -1. to end"<<endl;
    cin>>choice;
    do
    {
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Enter the number to be pushed : ";
                int x;
                cin>>x;
                push(arr,top,x,n);
                break;
            case 2:
                int rem=pop(arr,top);
                if(rem!=-1)
                    cout<<"Popped element : "<<rem;
                break;
        }
    }
    while(choice!=-1);

    while(top!=-1)
    {
        cout<<arr[top]<<" ";
        top--;
    }
    return 0;
}