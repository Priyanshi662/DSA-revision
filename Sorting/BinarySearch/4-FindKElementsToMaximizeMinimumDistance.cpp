// https://www.geeksforgeeks.org/place-k-elements-such-that-minimum-distance-is-maximized/

#include <iostream>
#include <vector>
using namespace std;

int isFeasible(vector<int> & arr,int mid,int n,int k)
{
    int pos=0;
    int count=1;
    for(int i=1;i<n;i++)
    {
        // if there are k elements present with the minimum distance as mid
        // the difference is calculated consecutively
        int curr_diff=arr[i]-arr[pos];
        if(curr_diff >= mid)
        {
            pos=i;
            count++;
        }
        if(count==k)
            return 1;
    }
    return 0;
}
int findDistance(vector<int> arr,int k)
{
    sort(arr.begin(),arr.end());
    int low=1;
    int n=arr.size();
    int high=arr[n-1];
    int res=-1;
    while(low<high)
    {
        int mid=low+(high-low)/2;
        if(isFeasible(arr,mid,n,k))
        {
            // maximizing the minimum distance in k elements
            res=max(res,mid);
            // increasing the mid value (diff value)
            low=mid+1;        
        }
        else
            high=mid-1;
        // decreasing the value of diff
    }
    return res;
}