// check if the given a string are a valid shuffle of other string or not
#include <bits/stdc++.h>
using namespace std;

bool isValidShuffle(string s1,string s2)
{
    if(s1.size()>s2.size())
        return false;
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s2.find(s1))
        return true;
    else    
        return false;
}
// without find function
bool compare(char c1[],char c2[])
{
    for(int i=0;i<256;i++)
    {
        if(c1[i]!=c2[i])
            return false;
    }
    return true;
}
bool isValidShuffle2(string pat,string text)
{
    int n =pat.size();
    int m =text.size();
    
    char pch[n];
    char tch[m];
    for(int i=0;i<n;i++)
    {
        pch[pat[i]]++;
        tch[text[i]]++;
    }
    for(int i=n;i<m;i++)
    {
        if(compare(tch,pch))
            return true;
        tch[text[i]]++;
        tch[text[i-n]]--;
    }
    if(compare(tch,pch))
        return true;
    return false;
}
int main()
{
    string s2="Priyanshi";
    string s1="anshiy";
    cout<<isValidShuffle(s1,s2)<<endl;
    return 0;
}

// Check if it is a valid shuffle of two strings
bool shuffle2Check(string str1,string str2,string str){
    if((str1.size()+str2.size())!=str.size())
        return false;
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    sort(str.begin(),str.end());
    int i=0,j=0,k=0;
    while(k<str.length()){
        if(i<str1.length()&&str1[i]==str[k])
        i++;
        else if(j<str2.length()&&str2[j]==str[k])
        j++;
        else
        return false;
    k++;
    }
    if(i<str1.length()||j<str2.length())
    return false;
    else
    return false;
}