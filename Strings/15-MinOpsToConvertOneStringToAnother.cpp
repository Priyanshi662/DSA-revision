#include <string> 
#include <iostream>
#include <unordered_map>
using namespace std;



// If string only contains 0s and 1s
int minops(string s1,string s2)
{
    if(s1.size()!=s2.size())
        return -1;
    if(s1==s2)
        return 0;
    int c0=0;
    int c1=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]==s2[i])
            continue;
        else if(s1[i]=='0')
            c0++;
        else if(s1[i]=='1')
            c1++;
    }
    // extra characters must be swap or changed, if 0s are more than 1s then 0s are changed to 1 and rest are swapped
    return max(c0,c1);
}
int main()
{
    string s1="010101011";
    string s2="101010001";
    int count=minops(s1,s2);
    cout<<count;
    return 0;
}


// if strings can contain any character
// the only operation allowed is to move the characters to the front one at a time
// for example to convert ADBC to ABCD the opns required are:
// ADCB —> CADB (Move ‘C’ to the front)
// CADB —> BCAD (Move ‘B’ to the front)
// BCAD —> ABCD (Move ‘A’ to the front)


int minops2(string temp,string s2)
{
    if(temp.size()!=s2.size())
        return -1;
    // check if characters are equal
    int i=0;
    unordered_map<char,int> mp;
    for(auto it:temp)
        mp[it]++;
    for(auto it:s2)
    {
        if(mp.find(it)==mp.end())
            return false;
        mp[it]--;
    }
    for(auto it:mp)
    {
        if(it.second!=0)
            return false;
    }
    int n=temp.size();
    int count=0;
    for(int i=n-1,j=i;i>=0;i--,j--)
    {
        while(i>=0 && temp[i]!=s2[j])
        {
            // find the first same occurence in string to be rearranged
            i--;
            count++;
        }
    }
    return count;
}