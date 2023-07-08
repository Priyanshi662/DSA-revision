#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool isKAnagram(string s1,string s2,int k)
{
    unordered_map<char,int> m1;
    // we can also take an array for counting-> char ch[MAX_CHAR]
    // this will optimize the space complexity of the solution
    for(int i=0;i<s1.size();i++)
    {
        m1[s1[i]]++;
    }
    int count=0;
    for(int i=0;i<s2.size();i++)
    {
        if(m1.find(s2[i])!=m1.end())
        {    
            m1[s2[i]]--;
        }
    }
    for(auto it:m1)
    {
        if(it.second>0)
            count+=(it.second);
    }
    if(count<=k)
        return true;
    return false;
}