#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({end[i],start[i]});
        }
            // vector<pair> is sorted in such a manner that the pairs are still mapped
            // with each other and they are sorted acc to first or the second part of the pair
        sort(v.begin(),v.end());
        int ans=1;
        int endlim=v[0].first;
        for(int i=1;i<n;i++)
        {
            if(v[i].second>endlim)
            {
                ans+=1;
                endlim=v[i].first;
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}