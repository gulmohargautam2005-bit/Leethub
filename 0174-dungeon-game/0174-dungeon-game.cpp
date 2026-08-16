class Solution {
public:
    int fun(int i, int j ,int &n, int &m,vector<vector<int>> &dungeon,vector<vector<bool>> &visited,vector<vector<int>> &dp)
    {
        if(i<0 ||i>=n || j <0 || j>= m)
            return 1e9;
        if(i ==n-1 && j ==m-1)
            return dp[i][j]= max(1, 1 - dungeon[n-1][m-1]);
        if(visited[i][j])
            return dp[i][j];
        visited[i][j]=true;
        int a = fun(i,j+1,n,m,dungeon,visited,dp)-dungeon[i][j];
        int b =  fun(i+1,j,n,m,dungeon,visited,dp)-dungeon[i][j];
        return dp[i][j]= max(1,min(a,b));
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        vector<vector<bool>> visited(n,vector<bool>(m,false));
       
        return fun(0,0,n,m,dungeon,visited,dp);

    }
};