// It is based on heightwise sorting
// pivot element is selected in such a way that all element before it are less than it
// and after it are greater than pivot element
#include <iostream>
using namespace std;
// time complexity-
// best case -O(nlogn)
// average case - O(nlogn)
// worst case - O(n^2)
// space complexity-
// O(log n)
// it is unstable sort
int partition(int arr[],int left,int right)
{
    int pivot=arr[right];
    int i=left-1;
    for(int j=left;j<right;j++)
    {
        if(arr[j]<=arr[pivot])
        {   
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[right],arr[i+1]);
    return (i+1);
}
void quickSort(int arr[],int left,int right)
{
    if(left>right)
        return;
    int pivot=partition(arr,left,right);
    // pivot is at sorted position, sort left and right part of the array
    quickSort(arr,left,pivot-1);
    quickSort(arr,pivot+1,right);
}
int main()
{
    int arr[]={3,2,5,6,1};
    int n=5;
    quickSort(arr,0,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
// Notes:
// 1.If the input sequence is already sorted then worst case behaviour occurs for the Quick sort algorithm 
// 2. Quick sort is used for big datasets because it takes less space and worst case behavior rarely occurs
// 3. Median of three partitioning method :
// Given array 8, 1, 4, 9, 6, 3, 5, 2, 7, 0.
// Left element=8, right element=0,
// Centre=[position(left+right)/2]=6.
// 4. Quick sort uses join operation since join is a faster operation than merge.