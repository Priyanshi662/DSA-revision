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
     int MissingNumber(int array[], int n) {
        int sumn=0;
        for(int i=1;i<=n;i++)
            sumn+=i;
        int sumarr=0;
        for(int i=0;i<n;i++)
        {
            sumarr+=array[i];
        }
        return sumn-sumarr;
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
    cout<<ob.MissingNumber(arr,n)<<endl;
}  