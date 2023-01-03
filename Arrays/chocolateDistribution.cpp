#include <bits/stdc++.h>
using namespace std;
class Solution{
	// This is a type of greedy problem
    public:
    typedef long long ll;
    ll findMinDiff(vector<ll> a,ll n,ll m)
    {
        sort(a.begin(),a.end());
        ll mindiff=INT_MAX;
        ll i=0;
        for(;i<=n-m;i++)
        {
            mindiff=min(mindiff,(a[i+m-1]-a[i]));
        }
        return mindiff;
    }   
};

int main() {
		long long n;
		cout<<"Enter number of packets : ";
		cin>>n;
		vector<long long> a;
		long long x;
		cout<<"Enter number of chocolates in each packet : ";
// 		There are M students, the task is to distribute chocolate packets among M students such that :
// 		1. Each student gets exactly one packet.
// 		2. The difference between maximum number of chocolates given to a student and minimum number of chocolates given to a student is minimum.
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		cout<<"Enter number of children : ";
		long long m;
		cin>>m;
		Solution ob;
		cout<<"Ans: ";
		cout<<ob.findMinDiff(a,n,m)<<endl;
	return 0;
}