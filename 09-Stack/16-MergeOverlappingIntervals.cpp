#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
//Brute force : using stack -> O(nlogn) and O(n)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort the starting intervals in ascending order
        sort(intervals.begin(),intervals.end());
        stack<vector<int>> st;
        st.push(intervals[0]);
        int i=0;

        while(!st.empty() && i<intervals.size())
        {
            // curr is the current time interval 
            vector<int> curr=st.top();
            // temp is the next time interval
            vector<int> temp=intervals[i++];
            // now if the ending of the current is after the starting of the next, we can merge
            if(curr[1]>=temp[0])
            {
                st.pop();
                // the new interval would be curr[0],max(curr[1],temp[1])
                curr[1]=max(curr[1],temp[1]);
                // store the new interval in case it can be further merged
                st.push(curr);
            }
            // else just push the next interval
            else
                st.push(temp);
        }
        vector<vector<int>> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
// optimal : using two pointer

};
class Solution1 {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& in) {
         vector<vector<int>> ans;
         ans.clear();
         sort(in.begin(),in.end());
         
         vector<int> temp=in[0];
         for(int i=0;i<in.size();i++)
         {
             if(temp[1]>=in[i][0])
             {
                 temp[1]=max(temp[1],in[i][1]);
                // in is already sorted so no need to check for .first of temp
             }
             else
             {
                 ans.push_back(temp);
                 temp=in[i];
             }
         }
         ans.push_back(temp);
         return ans;
    }
};