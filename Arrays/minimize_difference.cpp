#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int minimize_heights(int arr[],int n,int k)
    {
        sort(arr,arr+n);
        int curr_min=INT_MIN;
        int curr_max=INT_MAX;
        int diff=arr[n-1]-arr[0];
        for(int i=0;i<n-1;i++)
        {
            if(arr[i+1]>=k)
            {
                curr_min=min(arr[i+1]-k,arr[0]+k);
                curr_max=max(arr[i]+k,arr[n-1]-k);
                diff=min(diff,curr_max-curr_min);
            }
        }
        return diff;
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
    cout<<"Enter the value of K: ";
    int k;
    cin>>k;
    Solution ob;
    ob.print(arr,n);
    cout<<ob.minimize_heights(arr,n,k)<<endl;
}  