#include <iostream>
using namespace std;

int countRev (string s)
{
    if(s.size()%2!=0)
        return -1;
        
    int o=0;
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='{')   
        {
            o++;
        }
        else
        {
            if(o==0)
            {
                o++;
                ans++;
            }
            else
            {
                o--;
            }
        }
    }
    return (ans+o/2);
}