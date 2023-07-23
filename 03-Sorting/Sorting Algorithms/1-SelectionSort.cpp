#include <algorithm>
#include <iostream>
using namespace std;

// time complexity -> O(n^2)
// it is not stable sort -> change in order of duplicate elements
void Selectionsort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int mini=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[mini]>arr[j])
                mini=j;
        }
        swap(arr[i],arr[mini]);
    }
}
int main()
{
    int arr[]={3,2,5,6,1};
    int n=5;
    Selectionsort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}