#include <iostream>

using namespace std;

// heapify takes O(logn) time 
void heapify(int arr[],int i,int n)
{
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;

    if(left<n && arr[largest]<arr[left])
        largest=left;

    if(right<n && arr[largest]<arr[right])
        largest=right;

    if(largest!=i)
    {    
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }
}
// buildMaxHeap takes O(n) time
void buildMaxHeap(int arr[],int n)
{
    // n/2 -> denotes starting index of leaf nodes
    // leaf nodes are already a max heap in themselves
    for(int i=n/2-1;i>=0;i--)
    {
        heapify(arr,i,n);
    }
}
// heapsort thus takes -> O(n) + O(n logn) time -> O(nlog n) in all the cases
// it is a stable sort
// it is a non adaptive sort
void heapsort(int arr[],int n)
{
    buildMaxHeap(arr,n);
    // heap sort logic
    // at first whole array is a heap then we gradually remove the top element one by one 
    // till the size of the heap becomes 0
    for(int i=n-1;i>=0;i--)
    {
        int heapsize=i;
        swap(arr[0],arr[heapsize]);
        heapify(arr,0,heapsize);
    }
}
int main()
{
    int arr[]={3,2,5,6,1};
    int n=5;
    heapsort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
// Heap sort comparison with insertion and merge sort
// insertion sort -> like insertion sort it does not use any extra space
// merge sort -> it has time complexity of O(nlogn) in all cases
// thus it combines the best of both the algorithms
// Applications : Heap sort is used in security concerned and embedded systems , 
// and also in linux kernel because of its time complexity O(nlogn) in all the cases


/*
> Prii:
TCS Named One of the 50 Most Community-Minded Companies in the US
News Alert | 14 May 2024

> Prii:
Tata Consultancy Services is an IT services, consulting and business solutions organization that has 
been partnering with many of the world’s largest businesses in their transformation journeys for over
56 years. Its consulting-led, cognitive powered, portfolio of business, technology and engineering 
services and solutions is delivered through its unique Location Independent Agile™ delivery model, 
recognized as a benchmark of excellence in software development.

A part of the Tata group, India's largest multinational business group, TCS has over 601,000 of the 
world’s best-trained consultants in 55 countries. The company generated consolidated revenues of US 
$29 billion in the fiscal year ended March 31, 2024, and is listed on the BSE and the NSE in India. 
TCS' proactive stance on climate change and award-winning work with communities across the world 
have earned it a place in leading sustainability indices such as the MSCI Global Sustainability Index 
and the FTSE4Good Emerging Index

> Prii:
Faqir Chand Kohli joined the young Tata Consultancy Services (TCS), a division of Tata Sons established 
on April 1, 1968, by JRD Tata and Nani Palkhivala.

> Prii:
TCS said it will build a cloud-based digital ERP platform for Xerox to help boost its 
enterprise-related 
operations.


*/