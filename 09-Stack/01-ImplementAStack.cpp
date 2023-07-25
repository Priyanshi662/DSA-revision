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
// Java implementation:
/*
public class MyStack {
   private int maxSize;
   private long[] stackArray;
   private int top;
   
   public MyStack(int s) {
      maxSize = s;
      stackArray = new long[maxSize];
      top = -1;
   }
   public void push(long j) {
      stackArray[++top] = j;
   }
   public long pop() {
      return stackArray[top--];
   }
   public long peek() {
      return stackArray[top];
   }
   public boolean isEmpty() {
      return (top == -1);
   }
   public boolean isFull() {
      return (top == maxSize - 1);
   }
   public static void main(String[] args) {
      MyStack theStack = new MyStack(10); 
      theStack.push(10);
      theStack.push(20);
      theStack.push(30);
      theStack.push(40);
      theStack.push(50);
      
      while (!theStack.isEmpty()) {
         long value = theStack.pop();
         System.out.print(value);
         System.out.print(" ");
      }
      System.out.println("");
   }
}
*/