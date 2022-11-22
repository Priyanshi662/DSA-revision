#include <bits/stdc++.h>
using namespace std;
// Given Two sorted arrays - find the median of the merged sorted array formed from these 
// The median will be the mean of the middle two elements since the array sizes are same
class Solution
{
    public:
    void print(int arr[],int n)
    {
        for(int i=0;i<n;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    int medianArrsBrute(int a[],int b[],int n)
    {
        // TC & SC : O(n)
        vector<int> v;
        for(int i=0;i<n;i++)
            v.push_back(a[i]);
        for(int i=0;i<n;i++)
            v.push_back(b[i]);
        sort(v.begin(),v.end());
        return (v[n-1]+v[n])/2;
    }
    int getmedian(int a[],int n)
    {
        if(n%2==0)
            return a[n/2]+a[n/2-1];
        else
            return a[n/2];
    }
    int medianArrs(int a[],int b[],int n)
    {
        //TC : O(logn) and SC : O(logn)
        if(n<0)
            return -1;
        if(n==1)
            return (a[0]+b[0])/2;
        if(n==2)
            return (min(a[0],b[0])+max(a[1],b[1]))/2;
        int m1=getmedian(a,n);
        int m2=getmedian(b,n);
        if(m1<m2)
        {
            if(n%2==0)
            {
                return medianArrs(a+n/2+1,b,n-n/2+1);
            }
            else
            {
                return medianArrs(a+n/2,b,n-n/2);
            }
        }
        else
        {
            if(n%2==0)
                return medianArrs(a,b+n/2+1,n-n/2+1);
            else
                return medianArrs(a,b+n/2,n-n/2);
        }
    }
};
int main()
{
    int arr1[1000];
    int arr2[1000];
    cout<<"Enter Number of elements in arrays :";
    int n1;
    cin>>n1;
    cout<<"Enter the elements of array 1:";
    for(int i=0;i<n1;i++)
    {
        cin>>arr1[i];
    }
    cout<<"Enter the elements of array 2:";
    for(int i=0;i<n1;i++)
    {
        cin>>arr2[i];
    }
    Solution ob;
    cout<<ob.medianArrs(arr1,arr2,n1);
}  