#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumCostOfBreaking(vector<int> x, vector<int> y, int m, int n){
        // number of blocks in horizontal and vertical respectively
        int h=1,v=1;
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        m=m-2;
        n=n-2;
        int cost=0;
        while(n>=0 && m>=0)
        {
            int hcost=x[m]*h;
            int vcost=y[n]*v;
            if(x[m]>y[n])
            {
                // Put a horizontal:
                cost+=hcost;
                v+=1;
                m-=1;
            }
            else
            {
                // Put a vertical:
                cost+=vcost;
                h+=1;
                n-=1;
            }
        }
        if(m==-1)
        {
            while(n>=0)
            {
                // if columns are remaining :
                cost+=(y[n]*v);
                n--;
            }
        }
        if(n==-1)
        {
            while(m>=0)
            {
                // if rows are remaining :
                cost+=(x[m]*h);
                m--;
            }
        }
        return cost;
    }
};
int main()
{
    int m, n;
    cout<<"Enter the number of rows and columns:";
    cin >> m >> n;
    vector<int>X(m - 1), Y(n - 1);
    cout<<"Enter the cost of breaking the rows";
    for(int i = 0; i < m - 1; i++){
        cin >> X[i];
    }
    cout<<"Enter the cost of breaking the columns";
    for(int i = 0; i < n - 1; i++){
        cin >> Y[i];
    }
    Solution ob;
    cout<<"The minimum cost of breaking the board is:";
    int ans = ob.minimumCostOfBreaking(X, Y, m, n);
    cout << ans<<endl;
	return 0;
}