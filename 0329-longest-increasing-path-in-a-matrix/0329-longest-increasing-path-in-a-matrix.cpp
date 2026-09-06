class Solution {
public: 
    int dfs(int i, int j ,int parent,vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(i<0||j<0||j>=matrix[0].size()||i>=matrix.size()|| parent>=matrix[i][j])
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int up =  dfs(i,j-1,matrix[i][j],matrix,dp);
        int down = dfs(i,j+1,matrix[i][j],matrix,dp);
        int left = dfs(i-1,j,matrix[i][j],matrix,dp);
        int right = dfs(i+1,j,matrix[i][j],matrix,dp);
        dp[i][j]= 1+max(max(up,down),max(left,right));
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                ans = max(ans, dfs(i,j,-1,matrix,dp));
            }
        }
 
        return ans;
    }
    
};