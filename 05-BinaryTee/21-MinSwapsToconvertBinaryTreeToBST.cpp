#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
 public:
    void inorder(vector<int> &A,int i,int n,vector<int>& res)
    {
            if(i>=n)
            {
                return;
            }
            inorder(A,2*i+1,n,res);
            res.push_back(A[i]);
            inorder(A,2*i+2,n,res);
    }
    int swaps(vector<int> & vec,int n)
    {
        map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[vec[i]]=i;
        }
        sort(vec.begin(),vec.end());
        int count=0;
        int i=0;
        while(i<n)
        {
            if(mp[vec[i]]!=i)
            {
                count++;
                // we need to restore the array to prevent counting more than once
                swap(vec[i],vec[mp[vec[i]]]);
                continue;
            }
            i++;
        }
        return count;
    }
    int minSwaps(vector<int>&A, int n){
        vector<int> vec;
        inorder(A,0,n,vec);
        return swaps(vec,n);
    }
};