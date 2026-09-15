class Solution {
public:
    int fun(vector<vector<int>> & matrix,int r, int c,int &n , int &m,int k,vector<vector<int>> &dp)
    {
        if( c<0||c>=m )
            return 10000;
        if(r==(n-1))
            return matrix[r][c];
        if(dp[r][c]!=INT_MAX)
            return dp[r][c];

        

        int a =matrix[r][c]+fun(matrix,r+1,c+1,n,m,k+1,dp);
        int b = matrix[r][c]+fun(matrix,r+1,c,n,m,k+1,dp);
        int d =matrix[r][c]+fun(matrix,r+1,c-1,n,m,k+1,dp);
        return dp[r][c]=min(a,min(b,d));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MAX;
        int  k =0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
        for(int i =0;i<matrix[0].size();i++)
        {
            ans = min(ans,fun(matrix,0,i,n,m,k,dp));
        }
        return ans;
    }
};