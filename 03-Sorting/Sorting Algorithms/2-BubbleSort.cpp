#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Time Complexity- O(n^2) in worst case
// O(n) in best case
// It is a stable sort
// but not suitable for large datasets since it is time consuming
void bubbleSort(int arr[],int n)
{
       // Pass-1
    // 3 2 1 4 2
    // 2 3 1 4 2
    // 2 1 3 4 2
    // 2 1 3 2 4
    // Pass-2
    // 1 2 3 2 4
    // 1 2 2 3 4
    // Pass-3
    // 1 2 2 3 4 -> swap=true
    // break;
    // ->sorted
  
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(n-i);j++)
        {
            // after ith elements rest of the elements will be sorted
            // we need to run this loop till n-i elements only
            if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }
}
// optimized version
void bubbleSortoptimized(int arr[],int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        flag=0;
        for(int j=0;j<(n-i);j++)
        {
            // after ith elements rest of the elements will be sorted
            // we need to run this loop till n-i elements only
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag=1;
            }
        }
        // if no swapping occurs then array is sorted
        if(flag==0)
            break;
    }
}
int main()
{
    int arr[]={3,2,5,6,1};
    int n=5;
    bubbleSort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
