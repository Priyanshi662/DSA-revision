#include <iostream>
using namespace std;

void buildMaxHeap(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        // if child is greater than parent
        if(arr[i] > arr[(i-1)/2])
        {
            int j=i;
            // swap till child is greater than parent
            while(arr[j]>arr[(j-1)/2])
            {    
                swap(arr[i],arr[(i-1)/2]);
                // move to parent
                j=(j-1)/2;
            }
        }
    }
}
void heapsort(int arr[],int n)
{
    buildMaxHeap(arr,n);
    for(int i=n-1;i>=0;i--)
    {
        // this loop is for decreasing the heap size
        swap(arr[0],arr[i]);
        int j=0,index;
        do{
            // left child index
            index=2*j+1;
            if(arr[index] < arr[index+1] && index <(i-1))
            {
                // move to the right child
                index++;
            }
            // if parent is not the largest , swap
            if(arr[index] > arr[j] && index < i)
                swap(arr[j],arr[index]);
            // move to the largest
            j=index;    
        }
        while(index<i);    
    }
}