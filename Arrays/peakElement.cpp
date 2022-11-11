#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    void print(int arr[],int n)
    {
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    int peakElement(int arr[], int n)
    {
       int low=0;
       int high=n-1;
       while(low<high)
       {
           int mid= low+(high-low)/2;
           if(arr[mid]<arr[mid+1])
            low=mid+1;
           else
           {
               high=mid;
           }
       }
       return low;
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
    cout<<ob.peakElement(arr,n);
}  