#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void Rotate(int arr[],int n)
    {
        int x=arr[n-1];
        for(int i=n-1;i>=1;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[0]=x;
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
    ob.print(arr,n);
    ob.Rotate(arr,n);
    ob.print(arr,n);
}  