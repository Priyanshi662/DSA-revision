#include <bits/stdc++.h>
using namespace std;
// Kadanes Algorithm is used to find largest sum contiguous subarray
// Given an array Arr[] of N integers. Find the contiguous sub-array(containing at least one number) 
// which has the maximum sum and return its sum.

class Solution
{
    public:
    void print(int arr[],int n)
    {
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    int find_arr_max(int arr[],int n)
    {
        int maxarr=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>maxarr)
                maxarr=arr[i];
        }
        return maxarr;
    }
    int dpMax_subarr_sum(int arr[],int n)
    {
        int dp[n]={0};
        dp[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            if((dp[i-1]+arr[i])>arr[i])
                dp[i]=dp[i-1]+arr[i];
            else
                dp[i]=arr[i];
            if(dp[i]<0)
                dp[i]=0;
        }
        int maxsum=find_arr_max(dp,n);
        return maxsum;
    }
    int Max_subarray_sum(int arr[],int n)
    {
        // Without dp :
        int curr_max,max_so_far;
        curr_max=0;
        max_so_far=INT_MIN;
        for(int i=0;i<n;i++)
        {
            curr_max=max(curr_max,curr_max+arr[i]);
            if(curr_max<0)
                curr_max=0;
            max_so_far=max(curr_max,max_so_far);
        }
        return max_so_far;
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
    cout<<ob.dpMax_subarr_sum(arr,n)<<endl;
    cout<<ob.Max_subarray_sum(arr,n)<<endl;
    ob.print(arr,n);
}  