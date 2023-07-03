// Find nth string of count and say pattern
#include <iostream>
#include <string>
using namespace std;

string nthTerm(int n)
{
    string pat="1";
    for(int i=0;i<n-1;i++)
    {
        int j=0;
        string temp="";
        while(j<pat.size())
        {
            int count=1;
            while(j+1<pat.size() && pat[j]==pat[j+1])
            {
                count++;
                j++;
            }
            temp+=(count+'0');
            temp+=pat[j]+'0';
        }
        pat=temp;
    }
    return pat;
}