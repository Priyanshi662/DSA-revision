#include<bits/stdc++.h>
using namespace std;

// brute force - O(n^2)
vector<int> nextgreaterRight(vector<int> &arr,int n)
{
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        int x=-1;
        for(int j=i-1;j>=0;j--)
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

// optimal : using stack - O(n)
vector<int> nextgreaterRight2(vector<int> &arr,int n)
{
    stack<int> st;
    int i=0;
    vector<int> res;
    for(int i=0;i<n;i++)
    {
        if(st.empty())
            res.push_back(-1);
        else
        {
            if(st.top()>arr[i])
            {
                res.push_back(st.top());
            }
            else
            {
                while(!st.empty() && arr[i]>st.top())
                    st.pop();
                if(st.empty())
                    res.push_back(-1);
                else    
                    res.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    return res;
}