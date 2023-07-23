#include <bits/stdc++.h>
using namespace std;
#define d 26
#define MAX_RANGE 1024
bool patternSearch(string pat,string txt)
{
    int hp=0;
    int ht=0;
    int n=pat.size();
    int m=txt.size();
    for(int i=0;i<n;i++)
    {
        hp+=((d*hp)+pat[i])% MAX_RANGE;
        ht+=((d*ht)+txt[i])% MAX_RANGE;
    }
    int h=1;
    for(int i=0;i<n;i++)
    {
        h=(h*d)%MAX_RANGE;
    }
    int flag=0;
    for(int i=0;i<=(m-n);i++)
    {
        if(ht==hp)
        {
            return true;
        }
        else
        {
            if(i<(m-n))
            {
                ht=(d*(ht-txt[i]*h)+txt[i+n])% MAX_RANGE;
                if(ht<0)    
                    ht=ht+MAX_RANGE;
            }
        }
    }
    return false;
}