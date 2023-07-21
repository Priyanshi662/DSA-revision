// Merge sort uses divide and conquer technique to sort the array
#include <iostream>
#include <algorithm>
using namespace std;
// Time complexity- O(nlogn) in all cases
// Space complexity- O(nlogn) in standard case
// in bottom up Merge sort it takes O(n) space complexity
// The recurrence relation formed is T(n)=2 if n=2
//                                   T(n)=2T(n/2)+n if n>2
// It is a stable sort
void merge(int arr[],int p,int r,int q)
{
    if(p>=q)
        return;
    int n1=q-p+1;
    int n2=r-q;
    int left[n1];
    int right[n2];
    for(int i=0;i<n1;i++)
    {
        left[i]=arr[i+p];
    }
    for(int i=0;i<n2;i++)
    {
        right[i]=arr[q+i+1];
    }
    int i=0;
    int j=0,k=p;
    while(k<r)
    {
        if(left[i]<=right[j])
            arr[k]=left[i++];
        else
            arr[k]=right[j++];
        k++;
    }
    i=0;
    while(i<n1)
        arr[k++]=left[i++];
    j=0;
    while(j<n2)
        arr[k++]=right[j++];
}
void mergeSort(int arr[],int p,int q)
{
    if(p>q)
        return;
    int r=p+(q-p)/2;
    mergeSort(arr,p,r);
    mergeSort(arr,r+1,q);
    merge(arr,p,q,r);
}
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}
