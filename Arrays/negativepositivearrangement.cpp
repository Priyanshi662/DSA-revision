#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    // Shift negative elements to the beginning and positive to the end
    // Brute force : Sort the elements : O(nlogn)
    // Optimal 1 : Use Partition function of quick Sort
    void QuickPartition(int arr[],int n)
    {
        int j=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
            {
                if(i!=j)
                    swap(arr[i],arr[j]);
                j++;
            }
        }
    }
    void TwoPointer(int arr[],int n)
    {
        int i=0,j=n-1;
        while(i<=j)
        {
            if(arr[i]<0 && arr[j]>0)
            {
                i++;
                j--;
            }
            else if(arr[i]<0 && arr[j]<0)
            {
                i++;
            }
            else if(arr[i]>0 && arr[j]>0)
            {
                j--;
            }
            else
            {
                swap(arr[i],arr[j]);
                i++;
                j--;
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
    ob.print(arr,n);
    ob.TwoPointer(arr,n);
    ob.print(arr,n);
}  