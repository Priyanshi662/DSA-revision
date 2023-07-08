#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    string longestCommonPrefix (string arr[], int N)
    {
        int i,j,n;
        string s,s1,s2;
        int t=INT_MAX;
        for(i=0;i<N;i++)
        {
            s=arr[i];
            n=s.length();
            t=min(t,n);
        }//computing minimum length among the strings
        while(t>0)
        {
            s1=arr[0].substr(0,t);
            for(j=1;j<N;j++)
            {
                s2=arr[j].substr(0,t);
                if(s2!=s1)
                {
                    break;
                }
            }
            if(j==N)
            {
                return s1;
            }
            else{
                t--;
            } 
        }
        return "-1";
    }
};