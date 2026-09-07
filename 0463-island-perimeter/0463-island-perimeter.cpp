class Solution {
public:
    bool check(int r,int c, int n , int m)
    {
        if(r<0 || c<0 || r>=n||c>=m)
            return false;
        return true;
    }
    void dfs(int row, int col,vector<vector<int>>& grid,vector<vector<bool>> &visited,int (&x)[],int (&y)[],int& count)
    {
        visited[row][col] = true;
         int  n = grid.size();
         int m = grid[0].size();
         for(int i =0;i<4;i++)
         {
            int r= row+x[i];
            int c = col +y[i];
            if(grid[row][col]==1 && check(r,c,n,m)==false)
                count=count+1;
            if(grid[row][col]==1 && check(r,c,n,m) && grid[r][c]==0)
                count=count+1;
            if(check(r,c,n,m) && grid[r][c]==1 &&  visited[r][c]==false)
            {
              dfs(r,c,grid,visited,x,y,count);
            }
         }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
     vector<vector<bool>> visited(n, vector<bool>(m, false));
     int x[]={0,0,1,-1};
     int y[]={1,-1,0,0};
     int count =0;
    
     for(int i =0;i<n;i++)
     {
        for(int j =0;j<m;j++)
        {
            if(grid[i][j]==1 && visited[i][j] == false)
                dfs(i,j,grid,visited,x,y,count );
        }
     }
      return count;
        
    }
};