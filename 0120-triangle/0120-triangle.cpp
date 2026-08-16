class Solution {
public:
    int fun(int i,int j,int &n,vector<vector<int>>& triangle,vector<vector<int>> &dp,vector<vector<bool>> &visited)
    {
        if(i ==n)
            return 0;
        if(visited[i][j])
            return dp[i][j];
        visited[i][j]=true;
        int a = triangle[i][j]+fun(i+1,j,n,triangle,dp,visited);
        int b = triangle[i][j]+fun(i+1,j+1,n,triangle,dp,visited);
        return dp[i][j]=min(a,b);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        return fun(0,0,n,triangle,dp,visited);
        
    }
};