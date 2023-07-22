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
     void sort012(int a[], int n)
    {
        int low=0,mid=0,high=(n-1);
        while(mid<=high)
        {
            if(a[mid]==0)
            {
                swap(a[low],a[mid]);
                low++;
                mid++;
            }
            else if(a[mid]==1)
                mid++;
            else 
            {
                swap(a[mid],a[high]);
                high--;
            }
        }
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
    ob.sort012(arr,n);
    ob.print(arr,n);
}  