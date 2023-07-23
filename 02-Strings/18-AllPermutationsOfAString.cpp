#include <iostream>
#include <vector>
using namespace std;
void backtrack(string s,vector<string> &res,vector<bool> vis,string temp)
{
    if(temp.size()==s.size())
    {
        res.push_back(temp);
        return;
    }
    for(int i=0;i<s.size();i++)
    {
        if(vis[i]==false)
        {
            vis[i]=true;
            temp=temp+s[i];
            backtrack(s,res,vis,temp);
            temp.pop_back();
            vis[i]=false;
        }
    }
}
vector<string>find_permutation(string S)
{
    vector<string> res;
    vector<bool> vis(S.size(),false);
    backtrack(S,res,vis,"");
    return res;
}