#include <iostream>
using namespace std;

string lps(string s)
{
    int n=s.size();
    int temp[n+1];
    temp[0]=0;
    int i=0;
    int len=(n+1)/2;
    while(len<n)
    {
        if(s[i]==s[len])
        {
            len++;
            temp[len]=i;
            i++;
        }
        else
        {
            if(i!=0)
            {
                temp[len]=temp[i-1];
            }
            else
            {
                temp[len]=0;
            }
        }
    }
    return s.substr(0,temp[n-1]);
}