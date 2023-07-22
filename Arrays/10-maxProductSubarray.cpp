// https://leetcode.com/problems/maximum-product-subarray/
#include <bits/stdc++.h>

using namespace std;
class Solution{
public:
    typedef long long ll;
	ll maxProduct(vector<int> arr, int n) {
	  ll minpr=1;
	  ll maxpr=1;
	  ll res=INT_MIN;
	  for(int i=0;i<n;i++)
	  {
	      if(arr[i]==0)
	      {
	          minpr=1;
	          maxpr=1;
	      }
	      else if(arr[i]<0)
	      {
	          swap(maxpr,minpr);
	      }
	      ll num=ll(arr[i]);
	          
	          maxpr=max(num,num*maxpr);
	          minpr=min(num,(num*minpr));
	          res=max(res,maxpr);
	  }
	  return res;
	}
};
int main() {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    return 0;
}