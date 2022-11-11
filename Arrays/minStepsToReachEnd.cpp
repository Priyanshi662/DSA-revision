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
    // Brute force - Recursion to get all nodes reachable from the current index and minimize the number of steps
    int min_steps(int arr[],int n)
    {
        int count,currEnd,reachable;
        count=0;
        currEnd=0;
        reachable=0;
        for(int i=0;i<n;i++)
        {
            if(reachable<i)
                return -1;
            if(currEnd == i)
            {
                count++;
                reachable=max(reachable,arr[i]+currEnd);
                currEnd=reachable;
            }
            if(currEnd>=n-1)
                break;
        }
        if(currEnd < n-1)
            return -1;
        return count;
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
    cout<<ob.min_steps(arr,n)<<endl;
}  