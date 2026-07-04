class Solution {
public:
    int fun(int m, int n,int i,int j,vector<vector<int>>&dp)
    {
        if(i==m-1 && j==n-1)
            return 1;
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(i<0 ||i>=m ||j<0||j>=n)
        {
            return 0;
        }
        
         return dp[i][j]= fun(m,n,i+1,j,dp)+fun(m,n,i,j+1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1);
        vector<int> temp(n+1,-1);
        for(int i=0;i<m+1;i++)
        {
            dp[i]=temp;
        }

        return fun(m,n,0,0,dp);
    }
};