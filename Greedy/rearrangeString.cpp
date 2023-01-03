#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
class Solution
{
    public:
    // Function to find if two strings are rotations of each other or not.
    // Brute force solution -> TC: O(N^2) SC: O(N)
    string rearrangeStringbrute(string str)
    {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        for(auto i:str)
            mp[i]++;
        for(auto it:mp)
            pq.push({it.second,it.first});
        str="";
        while(pq.size()>1)
        {
            auto top1=pq.top();
            pq.pop();
            auto top2=pq.top();
            pq.pop();
            str+=top1.second;
            str+=top2.second;
            if(--top1.first>0)
                pq.push(top1);
            if(--top2.first>0)
                pq.push(top2);
        }
        if(pq.size()>0)
        {
            if(pq.top().first==1)
                str+=pq.top().second;
            else
                return "-1";
        }
        return str;
    }
    // Optimized solution -> TC: O(NlogN) SC: O(N)
    char getMaxFreqCh(vector<int> v)
    {
        int max=v[0];
        char ch=' ';
        for(int i=0;i<26;i++)
        {
            if(v[i]>max)
            {
                max=v[i];
                ch='a'+i;
            }
        }
        return ch;
    }
    string rearrangeString(string str)
    {
        vector<int> v(26,0);
        int n=str.size();
        for(auto ch:str)
            v[ch-'a']++;
        // find maximum frequency character:
        char maxfreqch=getMaxFreqCh(v);
        int maxfreq=v[maxfreqch-'a'];
        if(maxfreq>(n+1/2))
            return "-1";
        string res(n,' ');
        // fill the max freq ch at even positions
        int ind=0;
        while(maxfreq>0)
        {
            res[ind]=maxfreqch;
            ind+=2;
            maxfreq--;
        }
        v[maxfreqch-'a']=0;
        for(int i=0;i<26;i++)
        {
            while(v[i]>0)
            {
                // fill rest at odd positions:
                ind=ind>=n?1:ind;
                res[ind]=i+'a';
                ind+=2;
                v[i]--;
            }
        }
        return res;
    }   
    
};

int main()
{
    string str;
    cout<<"Enter The string : ";
    cin>>str;
    Solution ob;
    string str1=ob.rearrangeString(str);
    if(str1!="-1")
    {
        cout<<"Rearranged string is : "<<str1;
    }
    else
    {
        cout<<"Cannot convert ";
    }
    return 0;
}