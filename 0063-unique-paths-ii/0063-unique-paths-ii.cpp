class Solution {
public:
    int fun(vector<vector<int>>& obstacleGrid,int i,int j,int &n , int &m,vector<vector<int>> &dp)
    {
        if(i<0 || i>=n || j<0 || j>=m || obstacleGrid[i][j]==1)
            return 0;
        if(i==n-1 && j ==m-1)
            return  1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        return dp[i][j]=fun(obstacleGrid,i+1,j,n,m,dp)+fun(obstacleGrid,i,j+1,n,m,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n+1);
        vector <int> temp(m+1,-1);
        for(int i =0;i<n+1;i++)
        {
           dp[i]=temp;
        }
        return fun(obstacleGrid,0,0,n,m,dp);

        
        
    }
};