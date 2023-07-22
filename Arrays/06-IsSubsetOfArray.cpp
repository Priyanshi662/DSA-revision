// https://leetcode.com/problems/subsets/
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

    string isSubset(int a1[], int a2[], int n, int m) {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[a1[i]]++;
        }
        for(int j=0;j<m;j++)
        {
            if(mp.find(a2[j])==mp.end())
                return "No";
            mp[a2[j]]--;
            if(mp[a2[j]]<0)
                return "No";
        }
        return "Yes";
    }
};
int main()
{
    int arr1[10000];
    int arr2[10000];
    cout<<"Enter Number of elements in array :";
    int n1;
    cin>>n1;
    int n2;
    cout<<"Enter Number of elements in array :";
    cin>>n2;
    cout<<"Enter the elements of array :";
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the elements of array :";
    for(int i=0;i<n2;i++)
    {
        cin>>arr2[i];
    }
    Solution ob;
    cout<<ob.isSubset(arr1,arr2,n1,n2)<<endl;
}  