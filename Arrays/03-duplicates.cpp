// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
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
    vector<int> duplicates(int arr[], int n) {
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            int index=arr[i]%n;
            arr[index]+=n;
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(arr[i]/n > 1)
            {
                res.push_back(i);
                count++;
            }
        }
        if(count==0)
            res.push_back(-1);
        return res;
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
    vector<int> res=ob.duplicates(arr,n);
    for(int i=0;i<res.size();i++)   
        cout<<res[i]<<" ";
    
}  