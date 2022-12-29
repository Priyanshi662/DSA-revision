#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    typedef long long ll;
    long long int findMaxProduct(vector<int>&a, int n){
        // Sorting cannot help because for negatives numerical value would be higher from left to right
        // and for positives it would be higher from right to left
        // So we need to store a count for negatives
        int mod=pow(10,9)+7;
        if(n==1)
            return a[0];
        int zeroes=0;
        int neg=0;
        ll product=1;
        int maxnegative=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            {
                //calculate number of zeroes for corner cases
                zeroes++;
                continue;
            }
            else if(a[i]<0)
            {
                neg++;
                // maxnegative is the negative integer with the least absolute value (-1>-7)
                maxnegative=max(a[i],maxnegative);
            }
            product=(product*a[i])%mod;
        }
        // if all are zeroes
        if(zeroes==n)
            return 0;
        if(neg==1 && zeroes==(n-neg))
        {
            // if only 1 negative and others zeroes
            return 0;
        }
        if(neg&1)
        {
            // if odd number of negatives are present
            product=product/maxnegative;
        }
        // if even number of negatives are present there's no need to handle seperately
        return product;
    }
};

int main()
{
    cout<<"Enter the number of elements in the array:";
    int n;
    cin >> n;
    cout<<"Enter the elements of the array:";
    vector<int>arr(n);
    for(int i = 0 ; i < n; i++){
        cin >> arr[i];
    }
    Solution ob;
    long long int ans = ob.findMaxProduct(arr, n);
    cout<<"The maximum product is:";
    cout << ans<<endl;
	return 0;
}