#include <bits/stdc++.h>
using namespace std;
// Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. 
// Merge them in sorted order without using any extra space. 
class Solution
{
    public:
    void print(int arr[],int n)
    {
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    // Using insertion sort like approach

    void merger(int arr1[],int arr2[],int n1,int n2)
    {
        // 2 4 6 7  , 1 8 9 ,n1=4, n2=3
        for(int i=n2-1;i>=0;i--)
        {
            // Taking the last element of array 2
            int last=arr1[n1-1];
            // Taking j from n1-2 because we are shifting from arr1[j] to arr1[j+1]
            int j=n1-2;
            while(arr1[j]>arr2[i] && j>=0)
            {
                arr1[j+1]=arr1[j];
                j--;
            }
            if(last>arr2[i])
            {
                arr1[j+1]=arr2[i];
                arr2[i]=last;
            }
        }
    }
};
int main()
{
    int arr1[10000];
    int arr2[10000];
    cout<<"Enter Number of elements in array :";
    int n1;
    cin>>n1;
    int n2;
    cout<<"Enter Number of elements in array :";
    cin>>n2;
    cout<<"Enter the elements of array :";
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the elements of array :";
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    Solution ob;
    ob.merger(arr1,arr2,n1,n2);
    ob.print(arr1,n1);
    ob.print(arr2,n2);
}  