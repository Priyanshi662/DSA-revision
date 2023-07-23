#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;

// Brute Force : O(n^2)
bool compare(string s,unordered_map<char,int> mp)
    {
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])==mp.end())
                return false;
        }
        return true;
    }
	int search(string pat, string txt) {
	    int n=pat.size();
	    int m=txt.size();
	    unordered_map<char,int> mp;
	    
	    for(int i=0;i<n;i++)
	        mp[pat[i]]++;
	        
	    int count=0;
	    for(int i=0;i<m-n+1;i++)
	    {
	        string temp=txt.substr(i,n);
	        if(compare(temp,mp))
	            count++;
	    }
	    return count;
	}

//optimal : O(n)
// using sliding window technique
int search(string pat, string txt) {
    unordered_map<char,int> mp;
    for(char a : pat)
        mp[a]++;
   int count=mp.size();
   int i=0,j=0;
   int n=txt.size();
   int k=pat.size();
   int ans=0;
   while(j<n)
   {
       //calculation
       if(mp.find(txt[j])!=mp.end()){
            mp[txt[j]]--;
            if(mp[txt[j]]==0)
               count--;
       }

       if(j-i+1<k)
           j++;
       else if(j-i+1==k)
       {
           //ans calculation
           if(count==0)
                ans++;
           //check before incrementing i
        //    restoring the values of txt[i] if pattern found
        // to check for next anagram
           if(mp.find(txt[i])!=mp.end()){
                mp[txt[i]]++;
                if(mp[txt[i]]==1)
                    count++;
           }
           i++;
           j++;
       }
   }
   return ans;
}