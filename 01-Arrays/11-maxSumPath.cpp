// https://leetcode.com/problems/binary-tree-maximum-path-sum/
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
     int max_path_sum(int A[], int B[], int l1, int l2)
    {
        int i=0,j=0;
        int sum1=0,sum2=0;
        int res=0;
        while(i<l1 && j<l2)
        {
            if(A[i]<B[j])
                sum1+=A[i++];
            else if(A[i]>B[j])
                sum2+=B[j++];
            else
            {
                res+=max(sum1,sum2)+A[i];
                sum1=0,sum2=0;
                i++,j++;
            }
        }
        while(i<l1)
        {
            sum1+=A[i];
            i++;
        }
        while(j<l2)
        {
            sum2+=B[j];
            j++;
        }
        return res+max(sum1,sum2);
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
    cout<<ob.max_path_sum(arr1,arr2,n1,n2);
}  