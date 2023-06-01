class Solution {
    public:
    double dp[26][26][101];
    int row[8]={-2,-1,1,2,2,1,-1,-2};
    int col[8]={-1,-2,-2,-1,1,2,2,1};
    
    double solve(int x,int y,int k,int n)
    {   
        if(x<0 || x>=n || y<0 || y>=n)
        {
            // the path leads the knight out of the board , hence invalid path
            return 0;
        }
        if(k==0)
        {   
            return 1;
        }   
        if(dp[x][y][k]!=0)
            return dp[x][y][k];  
        double rate=0;
        for(int i=0;i<8;i++)
        {
            // at each level we have to choose 1 path from 8 possible paths so probability - 0.125 * level
            rate+=(0.125*solve(x+row[i],y+col[i],k-1,n));
        }
        // for each unique path store the rate at each level
        dp[x][y][k]=rate;
        return rate;
    }

     double knightProbability(int n, int k, int row, int column) {
        return solve(row,column,k,n);
    }
};