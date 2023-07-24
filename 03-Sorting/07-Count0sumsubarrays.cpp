 #include <vector>
 #include <unordered_map>
 
 using namespace std;

 long long int findSubarray(vector<long long int> &arr, int n ) {
        unordered_map<long long int,int> mp;
        // there can be two cases
        // 1. the sum =0
        // 2. the sum seen before is seen again
        long long int sum=0;
        long long int ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            // adding map[sum] because the whole subarray has n elements so n subarray possible
            if(mp.find(sum)!=mp.end())
                ans+=mp[sum];
            if(sum==0)
                ans++;
            mp[sum]++;
        }
        return ans;
    }