class Solution {
public:
 int sum=0;
    int fun(int i , int j , int &n , int &m,vector<vector<int>>& grid,vector<vector<int>> &dp)
    {
        if(i<0 ||i>=n ||j<0||j>=m)
            return  1e9;
        if(i ==n-1 && j == m-1)
            return dp[i][j]=grid[n-1][m-1];
      
        if(dp[i][j]!=-1)
            return dp[i][j];

        int a = grid[i][j]+fun(i+1,j,n,m,grid,dp);
        int b = grid[i][j]+fun(i,j+1,n,m,grid,dp);
        return dp[i][j]=min(a,b);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n =  grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return fun(0,0,n,m,grid,dp);
        
        
    }
};