#include<bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
vector<int> nextgreaterRight(vector<int> arr,int n)
{
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        int x=-1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]>arr[i])
            {
                x=arr[j];
                break;
            }
        }
        res.push_back(x);
    }
    return res;
}
class Solution
{
    public:
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        vector<long long> ans;
        stack<long long> st;
        int j=n-1;
        for(;j>=0;j--)
        {
            if(st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                //if stack is not empty compare the top element
                int x=st.top();
                if(x>arr[j])
                {
                    ans.push_back(x);
                }
                else 
                {
                    // pop till it encounters next greater element
                    // or the current element is the maximum till now
                    while(!st.empty() && st.top()<arr[j])
                    {
                        st.pop();
                    }
                    if(st.empty())
                        ans.push_back(-1);
                    else
                        ans.push_back(st.top());
                }
            }
            st.push(arr[j]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution obj;
        vector <long long> res = obj.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}