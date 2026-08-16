class Solution {
public:

    int fun(int i1 ,int j1 ,int i2, int &n, int &m,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp)
    {
        int j2 = i1+j1-i2;
        if(i1<0 || i1>=n || i2<0 || i2>=n || j1<0 ||j1>=m||j2<0 ||j2>=m)
            return INT_MIN;
        if(grid[i1][j1]==-1 || grid[i2][j2]==-1 )
            return INT_MIN;
        int cherrie = grid[i1][j1];
        if(i1!=i2)
            cherrie = cherrie +grid[i2][j2];
        if(dp[i1][j1][i2]!=-1)
            return dp[i1][j1][i2];
        if( i1 == n-1 && j1 == m-1)
            return dp[i1][j1][i2]=cherrie;
        int a = fun(i1+1,j1,i2+1,n,m,grid,dp);
        int b = fun(i1,j1+1,i2+1,n,m,grid,dp);
        int c = fun(i1,j1+1,i2,n,m,grid,dp);
        int d = fun(i1+1,j1,i2,n,m,grid,dp);
        int best = max(max(a,b),max(c,d));
        if(best == INT_MIN)
            return dp[i1][j1][i2] = INT_MIN;
        return  dp[i1][j1][i2]= cherrie+best;


    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(n,-1)));
        int cherrie=0;
        int a =fun(0,0,0,n,m,grid,dp);
        if(a<0)
            return 0;
        else
            return a;
        
    }
};