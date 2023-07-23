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
    vector<int> sumClosest(int arr[], int x,int n)
    {
        int i=0,j=n-1;
        vector<int> nums;
        int mindiff=INT_MAX;
        int first,second;
        while(i<j)
        {
           int diff=abs(x-(arr[i]+arr[j]));
           if(diff<mindiff)
            {
                mindiff=diff;
                first=arr[i];
                second=arr[j];
            }
            // Applying binary search here :
            else if((arr[i]+arr[j])>x)
                j--;
            else
                i++;
        }
        return {first,second};
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
    cout<<"Enter Value of X : ";
    int x;
    cin>>x;
    vector<int> res=ob.sumClosest(arr,x,n);
    cout<<"Sum Closest to X is formed by elements : "<<res[0]<<","<<res[1]<<endl;
    return 0;
}  