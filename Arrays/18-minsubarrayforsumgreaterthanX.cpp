#include <bits/stdc++.h>
using namespace std;
// Given an array of integers (A[])  and a number x, 
// find the smallest subarray with sum greater than 
// the given value. If such a subarray do not exist return 0 in that case.
class Solution
{
    public:
    int smallestSubWithsum(int arr[],int n,int x)
    {
        // start is the starting of the window which we have to minimize
        // ans stores number of elements in the subarray
        int ans=INT_MAX;
        int sum=0;
        int start=0;
        for(int i=0;i<n;i++)
        {
            sum=sum+arr[i]; 
            while(sum>x)
            {
                sum-=arr[start];
                ans=min(i-start+1,ans);
                start++;
            }
        }
        if(ans==INT_MAX)
            return 0;
        return ans;
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
    cout<<"Enter Value of x : ";
    int x;
    cin>>x;
    cout<<ob.smallestSubWithsum(arr,n,x)<<endl;
}  