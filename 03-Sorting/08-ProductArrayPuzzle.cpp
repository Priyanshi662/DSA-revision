#include <vector> 
using namespace std;
typedef long long int ll;
// https://practice.geeksforgeeks.org/problems/product-array-puzzle4525/1
vector<ll> productExceptSelf(vector<ll>& nums,int n) {
    vector<ll> left(n+1);
    vector<ll> right(n+1);
    left[0]=1;
    right[n-1]=1;
    for(int i=1;i<n;i++)
    {
        left[i]=left[i-1]*nums[i-1];
    }
    for(int j=n-2;j>=0;j--)
    {
        right[j]=right[j+1]*nums[j+1];
    }
    vector<ll> pro(n);
    for(int i=0;i<n;i++)
    {
        pro[i]=left[i]*right[i];
    }
    return pro;
}