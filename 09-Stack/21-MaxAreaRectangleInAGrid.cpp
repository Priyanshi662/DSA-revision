#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int getMaxArea(vector<int>arr, int n)
    {
        vector<int> left;
        stack<pair<int, int>> st;
        
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and st.top().first>=arr[i])
            st.pop();
            
            st.empty()? left.push_back(-1): left.push_back(st.top().second);
            st.push({arr[i],i});
        }
        
        while(!st.empty()) st.pop();
        
        vector<int> right;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top().first>=arr[i])
            st.pop();
            
            st.empty()? right.push_back(n): right.push_back(st.top().second);
            st.push({arr[i],i});
        }
        reverse(right.begin(),right.end());
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++)
        {
            ans=max(ans,arr[i]*(right[i]-left[i]-1));
        }
        return ans;
    }
    int maxArea(int mat[1000][1000], int n, int m) {
        vector<int>temp;
        
        for(int j=0;j<m;j++)
            temp.push_back(mat[0][j]);
            
        int area=getMaxArea(temp,m);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]!=0)
                    temp[j]+=mat[i][j];
                else
                    temp[j]=0;
            }
            int tarea=getMaxArea(temp,m);
            area=max(tarea,area);
        }
        return area;
    }
};