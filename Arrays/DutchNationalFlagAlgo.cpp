// https://leetcode.com/problems/sort-colors/description/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    // Dutch national flag algo is used to sort an array containing 0,1 or 2 as elements
    // we use low,mid,high to sort elements fast
    // reduces time complexity from O(n^2) to O(n)
    // However the brute force (count the number of 0s,1s and 2s and insert in array) also take O(n) time
    // This method does sorting in 1 traversal
    public:
        void sort012(int arr[],int n)
        {
            int low=0,mid=0,high=n-1;
            while(mid<=high)
            {
                if(arr[mid]==0)
                {
                    swap(arr[low],arr[mid]);
                    mid++;
                    low++;
                }    
                else if(arr[mid]==1)
                    mid++;
                else
                {
                    swap(arr[mid],arr[high]);
                    high--;
                }
            }
        }
        void print(int arr[],int n)
        {
            for(int i=0;i<n;i++)
                cout<<arr[i]<<" ";
            cout<<endl;
        }
};
int main()
{
    int arr[10000];
    cout<<"Enter Number of elements in array :";
    int n;
    cin>>n;
    cout<<"Enter the elements of array :";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Solution ob;
    cout<<"Before Sorting :";
    ob.print(arr,n);
    ob.sort012(arr,n);
    cout<<"After Sorting :";
    ob.print(arr,n);
}  