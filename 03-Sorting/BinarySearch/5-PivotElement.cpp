// https://www.techcrashcourse.com/2016/07/program-to-find-pivot-element-of-sorted-rotated-array.html
#include <iostream>
using namespace std;
// Brute Force : linear search
// optimal : Modified Binary search
int getPivotElement(int arr[],int n)
{
    int low=0;
    int high=n-1;
    while(low<high)
    {
        int mid=low+(high-low)/2;
        if(mid<n-1 && arr[mid]> arr[mid+1])
            return arr[mid];
        if(arr[low]>=arr[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return arr[low];
}