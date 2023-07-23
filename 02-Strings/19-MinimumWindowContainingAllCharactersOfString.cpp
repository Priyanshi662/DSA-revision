#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_map>
using namespace std;
int findSubString(string str)
    {
        set<char> s;
        for(int i=0;i<str.size();i++)
            s.insert(str[i]);
        
        int j=0;
        int i=0;
        int minlen=INT_MAX;
        unordered_map<char,int> mp; 
        //we have to find the count of characters so mp necessary
        for(;i<str.size();i++)
        {
            mp[str[i]]++;
            // minimizing the window if the all the characters are found
            while(j<str.size() && mp.size()==s.size())
            {
                minlen=min(minlen,i-j+1);
                mp[str[j]]--;
                // with this condition the while loop ends where all the characters are present
                if(mp[str[j]]==0)
                    mp.erase(str[j]);
                j++;
            }
        }
        return minlen;
    }