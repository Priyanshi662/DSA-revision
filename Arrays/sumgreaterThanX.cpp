#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    int subarrayWithSumgreaterThanX(int arr[],int n,int x)
    {
        int sum=0,i=0,j=0,minlen=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            // do not move j till sum<=x - minimize window only when sum>x
            while(sum>x)
            {
                minlen=min(minlen,j-i+1);
                sum-=arr[j];
                j++;
            }
        }
        return minlen;
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
    int x;
    cout<<"enter value of X :";
    cin>>x;
    cout<<ob.subarrayWithSumgreaterThanX(arr,n,x)<<endl;;
}  