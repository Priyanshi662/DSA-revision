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
    int maxProfit(int prices[],int n) {
        int min=prices[0];
        int curr_prof=0;
        int max_prof=0;
        for(int i=0;i<n;i++)
        {
            // if current element is minimum
            if(prices[i]<min)
                min=prices[i];
            // if sp-cp has a profit - store and check for max profit
            if((prices[i]-min)>0)
                curr_prof=prices[i]-min;
            max_prof=max(max_prof,curr_prof);
        }
        return max_prof;
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
    cout<<ob.maxProfit(arr,n)<<endl;
}  