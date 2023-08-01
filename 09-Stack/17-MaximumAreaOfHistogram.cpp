#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<int> fillnsl(vector<int> &h)
    {
        stack<pair<int,int>> st;
        int n=h.size();
        vector<int> res;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && st.top().first>=h[i])
            {
                st.pop();
            }
            if(!st.empty())
                res.push_back(st.top().second);
            else
                res.push_back(-1);
            st.push({h[i],i});
        }
        return res;
    }
    vector<int> fillnsr(vector<int> &h)
    {
        stack<pair<int,int>> st;
        int n=h.size();
        vector<int> res;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && st.top().first>=h[i])
            {
                st.pop();
            }
            if(!st.empty())
                res.push_back(st.top().second);
            else
                res.push_back(n);
            st.push({h[i],i});
        }
        reverse(res.begin(),res.end());
        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        // the blocks btwn nsl and nsr contribute to the maximum area spanned by the current block
        // brute force would be to calculate the nsl and nsr at each step
        //optimal: precompute nsl and nsr
        // nsl
        vector<int> nsl=fillnsl(heights);
        vector<int> nsr=fillnsr(heights);
        int maxArea=INT_MIN;
        for(int i=0;i<heights.size();i++)
        {
            int currspan=nsr[i]-nsl[i]-1;
            maxArea=max(maxArea,heights[i]*currspan);
        }
        return maxArea;
    }
};