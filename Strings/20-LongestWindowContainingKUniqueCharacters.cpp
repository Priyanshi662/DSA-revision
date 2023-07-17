#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    int longestKSubstr(string s, int k) {
      int l=0,r=0;
      int count=0;
      int mx=INT_MIN;
      unordered_map<char,int> ump;
      while(r<s.length())
      {
         //increment count when the element is not in hash map
         ump[s[r]]++;
         if(ump[s[r]]==1)
         count++;
          
         if(count>k)
         {  
             while(l<r&&count>k)
             {
                 ump[s[l]]--;
                 if(ump[s[l]]==0)
                 count--;
                 l++;
             }
         }
         if(count==k)
         {
             mx=max(mx,r-l+1);
         }
         r++;
      }
      return (mx==INT_MIN?-1:mx);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}