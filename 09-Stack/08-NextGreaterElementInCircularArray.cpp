#include <vector>
#include <stack>
using namespace std;

//brute force : take another array with 2*n elements copying the array twice

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums2) {
        int n=nums2.size();
        vector<int> greater(n); 
        stack<int> st;
        for(int i=n-1;i>=0;i--)
            st.push(i);
        for(int i=n-1;i>=0;i--)
        {
            greater[i]=-1;
            while(!st.empty() && nums2[i]>=nums2[st.top()])
                st.pop();
            
            if(!st.empty())
                greater[i]=nums2[st.top()];
            // adding the right element again because it may be greater than the next current element
            st.push(i);
        }
        return greater;
    }
};