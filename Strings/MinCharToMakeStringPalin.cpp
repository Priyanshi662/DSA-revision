#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> lps(string s)
{
    int n=s.size();
    vector<int> l(n);
    int i=1;
    int len=0;
    l[0]=0;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            len++;
            l[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=l[len-1];
            }
            else
            {
                l[i]=0;
                i++;
            }
        }
    }
    return l;
}
int minCharToRemove(string s)
{
    string t=s;
    reverse(t.begin(),t.end());
    s=s+"$"+t;
    vector<int> l=lps(s);
    return t.size()-l[l.size()-1];
}