#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool isPalin(string s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<=j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void possiblepartitions(string s,int i,vector<string> temp,vector<vector<string>> &res)
    {
        if(i==s.size())
        {   
            res.push_back(temp);
            return;
        }
        for(int k=i;k<s.size();k++)
        {
            string tempstr=s.substr(i,k-i+1);
            if(isPalin(tempstr))
            {
                temp.push_back(tempstr);
                possiblepartitions(s,k+1,temp,res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        possiblepartitions(s,0,temp,res);
        return res;
    }
};