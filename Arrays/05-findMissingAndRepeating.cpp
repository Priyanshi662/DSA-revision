#include <bits/stdc++.h>
using namespace std;
// Given an unsorted array Arr of size N of positive integers. 
// One number 'A' from set {1, 2, …N} is missing and one number 'B' occurs twice in array. 
// Find these two numbers.
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // We will keep marking the elements that are accessed as negative
        // Access the elements using current element as index of the accessed element
        // The unaccessed element will be the missing element 
        int *ans=new int[2]{-1};
        int val,ele;
        sort(arr,arr+n);
        for(int i=0;i<n;i++)
        {
            val=abs(arr[i]);
            ele=arr[val-1];
            if(ele>0)
            {
                arr[val-1]=-ele;
            }
            else
            {
                ans[0]=val;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            {
                // i+1 is the value that is missing since we have sorted the array
                ans[1]=i+1;
                break;
            }
        }
        return ans;
    }
};
int main() 
{
    cout<<"Enter number of elements : ";
    int n;
    cin >> n;
    cout<<"Enter Array elemets : ";
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    Solution ob;
    auto ans = ob.findTwoElement(a, n);
    cout<<"Repeating , Missing numbers : ";
    cout << ans[0] << " , " << ans[1] << "\n";
    return 0;
}