#include <bits/stdc++.h>
using namespace std;
// Sorts the given array in ascending order using max heap 
// for descending order use min heap
class Solution
{
    public:
    //Heapify function to maintain heap property.
    void heapify(int arr[], int n, int i)  
    {
        int largest=i;
        int left=2*i;
        int right=2*i+1;
        if(arr[left]>largest)
            largest=arr[left];
        if(arr[right]>largest)
            largest=arr[right];
        if(i!=largest)
        {
            swap(arr[i],arr[largest]);
            heapify(arr,n,largest);
        }
    }

    public:
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
        int heapsize=n;
        // heapsize/2 is the last non leaf node in the array
        for(int i=(heapsize/2);i>=0;i--)
        {
            heapify(arr,heapsize,i);
        }
    }

    public:
    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        buildHeap(arr,n);
        for(int i=n-1;i>=0;i--)
        {
            swap(arr[0],arr[i]);
            heapify(arr,i,0);
        }
    }
};

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int arr[1000000],n,i;
    cout<<"Enter number of elements in array : ";
    scanf("%d",&n);
    cout<<"Enter the elements in the array : ";
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    Solution ob;
    ob.heapSort(arr, n);
    cout<<"After sorting the array using heap sort in ascending order : ";
    printArray(arr, n);
    return 0;
}