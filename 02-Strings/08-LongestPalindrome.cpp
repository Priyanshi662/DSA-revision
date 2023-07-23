#include <string>
#include <iostream>
using namespace std;

int expandPalin(string s,int low,int high)
{
    if(low>high || s=="")
        return 0;
    while(low>=0 && high<=s.size() && s[low]==s[high])
    {
        low--;
        high++;
    }
    return high-low-1;
}
string findLongestPalin(string s)
{
    int start=0;
    int end=0;
    for(int i=0;i<s.size();i++)
    {
        int l1=expandPalin(s,i,i);
        int l2=expandPalin(s,i,i+1);
        int l=max(l1,l2);
        if(l>(end-start+1))
        {
            start=i-(l-1)/2;
            end=i+l/2;
        }
    }
    return s.substr(start,end-start+1);
}

int main()
{
    string s="fedcababachij";
    string temp=findLongestPalin(s);
    cout<<temp<<endl;
    return 0;
}