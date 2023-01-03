#include<bits/stdc++.h> 
using namespace std; 
// To find the smallest number with given sum of digits as S and number of digits as D
// Input: S = 9, D = 2
// Output: 18
class Solution{   
public:
    string smallestNumber(int S, int D){
        // if sum of digits is less than the number of digits then return -1
        if(D*9 <S)
            return "-1";
        string res="";
        int i=D-1;
        for(;i>=0;i--)
        {
            if(S>9)
            {
                // if sum>9 then add 9's in the number till D>0 and S>9
                res="9"+res;
                S=S-9;
            }
            else if(i==0)
            {
                // Last remaining digits of the sum will be added in the first digit 
                res=to_string(S)+res;
            }
            else
            {
                res=to_string(S-1)+res;
                i--;
                while(i>0)
                {
                    res="0"+res;
                    i--;
                }
                res="1"+res;
                break;
            }
        }
    }
};

int main() 
{ 
    int S,D;
    cin >> S >> D;
    Solution ob;
    cout << ob.smallestNumber(S,D) << endl;
    return 0; 
} 