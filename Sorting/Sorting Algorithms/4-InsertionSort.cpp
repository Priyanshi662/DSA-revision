#include <iostream> 
#include <algorithm>
using namespace std;
// It is like a deck of cards
// Time complexity : O(nlogn) in best case
// O(n^2) in worst and average case
// space complexity : O(1)
// It is a stable sort
// It is used when there are only few elements in the array to be sorted
void insertionsort(int arr[],int n)
{
    for(int j=1;j<n;j++)
    {
        // assuming that 0 to j are sorted elements
        // our boundary moves forward at each iteration of j
        int ele=arr[j];
        int i=j-1;
        while(i>=0 && arr[i]>ele)
        {
            arr[i+1]=arr[i];
            i--;
        }
        // will stop at the position of element lesser than ele
        // but the shifted empty position will be at i+1
        arr[i+1]=ele;
    }
}
int main()
{
    int arr[]={3,2,5,6,1};
    int n=5;
    insertionsort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}