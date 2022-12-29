#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a,a+n);
        int i=0;
        while(i<n && k>0 && a[i])
        {
            a[i]=-a[i];
            i++;
            k--;
        }
        sort(a,a+n);
        long long sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=a[j];
        }
        if(k==0 || k%2==0)
        {
            // no more operation needed
            return sum;
        }
        else
        {
            // a[0] is a positive number added to sum
            // k is odd -> a[0] needs to invert its sign and add to sum -> remove +ve a[0] and add -ve a[0]
            return sum-(2*a[0]);
        }
    }
};

int main()
{
    cout<<"Enter the number of elements in the array and the number of operations:";
    int n, k;
    cin>>n>>k;
    cout<<"Enter the elements of the array:";
    long long int a[n+5];
    for(int i=0;i<n;i++)
    cin>>a[i];
    Solution ob;
    cout<<"The maximum sum after "<<k<<" operations is:";
    cout<<ob.maximizeSum(a, n, k)<<endl;
	return 0;
}