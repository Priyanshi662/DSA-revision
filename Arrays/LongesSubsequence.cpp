#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int N)
    {
        sort(arr,arr+N);
        unordered_set<int> s;
        for(int i=0;i<N;i++)
        {
            s.insert(arr[i]);
        }
        int res=1;
        for(int i=0;i<N;i++)
        {
            if(s.find(arr[i]+1)!=s.end())
            {
                int j=arr[i];
                while(j<N && s.find(j)!=s.end())
                    j++;
                res=max(res,j-arr[i]);
            }
        }
        return res;
    }
};
int main()
{
 int n,i,a[100001];
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
    return 0;
}