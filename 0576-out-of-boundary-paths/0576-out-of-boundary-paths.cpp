class Solution {
public:
    long long fun(int m , int n , int maxMove, int r,int c,vector<vector<vector<int>>>&dp)
    {
     
        if(r<0 || r>=m ||c<0||c>=n)
            return 1;
        if(maxMove==0)
            return 0;
        if(dp[maxMove][r][c]!=-1)
            return dp[maxMove][r][c];
        const int MOD = 1e9 + 7;
        long long ans =
        fun(m,n,maxMove-1,r+1,c,dp)
        + fun(m,n,maxMove-1,r-1,c,dp)
        + fun(m,n,maxMove-1,r,c+1,dp)
        + fun(m,n,maxMove-1,r,c-1,dp);
        return dp[maxMove][r][c]=ans%MOD;
      

    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(maxMove+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return fun(m,n,maxMove,startRow,startColumn,dp);
    }
};