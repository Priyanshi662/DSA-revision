#include <iostream>
#include <string>
using namespace std;

int findvalue(char r)
{
    if (r == 'I')
        return 1;
    if (r == 'V')
        return 5;
    if (r == 'X')
        return 10;
    if (r == 'L')
        return 50;
    if (r == 'C')
        return 100;
    if (r == 'D')
        return 500;
    if (r == 'M')
        return 1000;
 
    return -1;
}

int RomanToInt(string s)
{
    int n=s.size();
    int res=0;
    for(int i=0;i<n-1;i++)
    {
        char c1=s[i];
        char c2=s[i+1];
        int v1=findvalue(c1);
        int v2=findvalue(c2);
        if(v2>v1)
        {
            res+=(v2-v1);
            i++;
        }
        else
        {
            res+=v1;
        }
    }
    return res;
}
int main()
{
    string s="MCMIV";
    int res=RomanToInt(s);
    cout<<res<<endl;
    return 0;
}