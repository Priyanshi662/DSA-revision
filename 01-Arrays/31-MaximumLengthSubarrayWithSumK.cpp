#include <vector>
#include <unordered_map>
using namespace std;
int findmaxlenBrute(vector<int>&v,int k)
{
    int n=v.size();
    for(int i=0;i<n-1;i++)
    {
        int sum=v[i];
        for(int j=i+1;j<n;j++)
        {
            sum+=v[j];
            if(sum==k)
                return j+1;
        }
    }
    return 0;
}
int findmaxlen(vector<int> &v,int k)
{
    unordered_map<int,int> mp;
    // map all the cumulative sum encountered
    int sum=0;
    int n=v.size();
    int maxlen=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum==k)
        {
            maxlen=max(maxlen,i+1);
        }
        int diff=k-sum;
        if(mp.find(diff)!=mp.end())
        {
            maxlen=max(maxlen,i-mp[diff]);
        }
        if(mp.find(sum)==mp.end())
            mp[sum]=i;
    }
    return 0;
}