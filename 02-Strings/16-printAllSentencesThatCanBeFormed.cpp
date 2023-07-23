//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;
// Given a list of word lists of size  M * N. 
// The task is to return all sentences possible taking one word from a list at a time via recursion. 
// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    void print(vector<vector<string>>&list,vector<vector<string>> &res
    ,vector<string> temp,int n)
    {
        if(list.size()==0)
            return;
        if(n==list.size())
        {
            res.push_back(temp);
            temp.clear();
            return;
        }
        int m=list[n].size();
        for(int i=0;i<m;i++)
        {
            temp.push_back(list[n][i]);
            print(list,res,temp,n+1);
            temp.pop_back();
        }
    }
    vector<vector<string>> sentences(vector<vector<string>>&list){
        vector<vector<string>> res;
        vector<string> temp;
        print(list,res,temp,0);
        return res;
    }
};


//{ Driver Code Starts.
int main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<vector<string>>list(m, vector<string>(n));
	    for(int i = 0 ; i < m; i++){
	        for(int j = 0; j < n; j++){
	            cin >> list[i][j];
	        }
	    }
	    Solution ob;
	    vector<vector<string>>ans = ob.sentences(list);
	    for(auto it : ans){
	        for(auto it1 : it){
	            cout << it1 << " ";
	        }
	        cout << endl;
	    }
	}
	return 0;
}

// } Driver Code Ends