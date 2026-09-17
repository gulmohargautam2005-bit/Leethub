class Solution {
public:
    bool valid(int r, int c,int n)
    {
        if(r<0||r>=n ||c<0||c>=n)
            return false;
        return true;
    }
    void fun(vector<vector<int>>& grid,int row,int col,queue<pair<int,int>>&q,int (&x)[],int (&y)[])
    {
        grid[row][col]=2;
        q.push({row,col});
      
        for(int i =0;i<4;i++)
        {
            int r =row+x[i];
            int c = col +y[i];
            if(valid(r,c,grid.size())&& grid[r][c]==1)
                fun(grid,r,c,q,x,y);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int x[]={1,-1,0,0};
        int y[]={0,0,1,-1};
        bool found = false;
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(grid.size()+1,vector<bool>(grid.size()+1,false));
        int n = grid.size();
        for(int i =0;i<n && !found;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    fun(grid,i,j,q,x,y);
                    found = true;
                    break;
                }
            }
        }
        int distance =0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto[r,c]=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nr = r+x[i];
                    int nc= c +y[i];
                    if (!valid(nr, nc, n))
                        continue;
                    if(grid[nr][nc]==1)
                        return distance;
                    if(grid[nr][nc]==0)
                        {
                            grid[nr][nc]=2;
                            q.push({nr,nc});
                        }
                }
            }
            distance++;
        }
        return -1;
    }
};