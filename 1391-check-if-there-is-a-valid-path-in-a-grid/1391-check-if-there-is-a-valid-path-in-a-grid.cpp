class Solution {
public:
     int m;
     int  n;
    unordered_map<int,vector<vector<int>>>direction=
    {
        {1,{{0,1},{0,-1}}},
        {2,{{1,0},{-1,0}}},
        {3,{{0,-1},{1,0}}},
        {4,{{1,0},{0,1}}},
        {5,{{-1,0},{0,-1}}},
        {6,{{-1,0},{0,1}}},
    };
    bool dfs(int x,int y,vector<vector<int>> &grid,vector<vector<bool>> & visited)
    {
       if(x==m-1 && y == n-1)
            return true;
        visited[x][y] = true;
        for( auto dir : direction[grid[x][y]])
        {
            int new_x= x+dir[0];
            int new_y = y+dir[1];

            if(new_x<0 || new_x >=m || new_y<0 || new_y >=n || visited[new_x][new_y]==true)
                continue;

            for(auto newdir : direction[grid[new_x][new_y]])
            {
                if(new_x + newdir[0]==x && new_y+newdir[1]==y)
                    if(dfs(new_x,new_y,grid,visited))
                        return true;
            }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        return dfs(0,0,grid,visited);
    }
};