#include <stack>
using namespace std;
// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1?category%5B%5D=Stack&category%5B%5D=Stack&company%5B%5D=Amazon&company%5B%5D=Amazon&problemStatus=unsolved&problemType=functional&difficulty%5B%5D=1&page=1&sortBy=submissions&query=category%5B%5DStackcompany%5B%5DAmazonproblemStatusunsolvedproblemTypefunctionaldifficulty%5B%5D1page1sortBysubmissionscompany%5B%5DAmazoncategory%5B%5DStack
class Solution{
    int minele;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           if(s.empty())
                return -1;
            return minele;
       }
       
       
       /*returns poped element from stack*/
       int pop(){
            if(s.empty())
                return -1;
            int y=s.top();
            s.pop();
            int x;
            if(y<0)
            {
                x=minele;
                minele=minele-y;
            }
            else
            {
                x=y;
            }
            return x;
       }
       
       /*push element x into the stack*/
       void push(int x){
            if(s.empty())
            {
                minele=x;
                s.push(x);
            }
            else if(x<minele)
            {
                int y=x-minele;
                minele=x;
                s.push(y);
            }
            else
            {
                s.push(x);
            }
       }
};