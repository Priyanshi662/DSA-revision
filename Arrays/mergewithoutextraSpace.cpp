#include <bits/stdc++.h>
using namespace std;
//  Given two sorted arrays arr1[] and arr2[] of sizes n and m in 
//  non-decreasing order.
//  Merge them in sorted order without using any extra space. 
//  Modify arr1 so that it contains the first N elements and modify arr2 so that it 
//  contains the last M elements.
class Solution
{
    public:
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
}  