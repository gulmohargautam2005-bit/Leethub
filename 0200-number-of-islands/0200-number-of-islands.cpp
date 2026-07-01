class Solution {
public:
    bool valid(int row,int col,int n,int m)
    {
        if(row<0 || row>=n || col<0 ||col>=m)
            return false;
        return true;
    }
    void dfs(vector<vector<char>> &grid,int row,int col,vector<vector <bool>> &check,int &res,int (&x)[],int (&y)[])
    {
        int n = grid.size();
        int m = grid[0].size();
        for(int k =0;k<4;k++)
        {
            int r=row+x[k];
            int c=col+y[k];
            if(valid(r,c,n,m) && grid[r][c]=='1'&&check[r][c]==false)
            {
                check[r][c]=true;
                
                dfs(grid,r,c,check,res,x,y);
            }
        }
        
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        vector<vector <bool>>check(grid.size(),vector<bool> (grid[0].size(),false));
        int res=0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(check[i][j]==false && grid[i][j]=='1')
                    {
                    check[i][j] = true;
                     res++;
                    dfs(grid,i,j,check,res,x,y);
                  
                    }
            }
        }

        return res;

    }
};