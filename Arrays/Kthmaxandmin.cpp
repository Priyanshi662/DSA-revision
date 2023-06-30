//https://leetcode.com/problems/kth-largest-element-in-an-array/
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int Ksmallest(int arr[],int n,int k)
        {
            priority_queue<int> pq;
            for(int i=0;i<n;i++)
            {
                //insert every element in the queue
                pq.push(arr[i]);
                if(pq.size()>k)
                    pq.pop();
            }
            return pq.top();
        }
        int Kmax(int arr[],int n,int k)
        {
            priority_queue<int,vector<int>,greater<int>> pq;
            for(int i=0;i<n;i++)
            {
                // insert every element in the queue and remove if it is smaller than k size
                pq.push(arr[i]);
                if(pq.size()>k)
                    pq.pop();
            }
            return pq.top();
        }
        void solve(int arr[],int n,int k)
        {
           cout<<k<<" minimum is : "<<Ksmallest(arr,n,k)<<endl;
           cout<<k<<" maximum is : "<<Kmax(arr,n,k)<<endl;
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
    cout<<"Enter value of K : ";
    int k;
    cin>>k;
    Solution ob;
    ob.solve(arr,n,k);
  }  