#include <bits/stdc++.h>
using namespace std;
class Solution{
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
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	return 0;
}