class Solution {
public:
    bool valid(int row,int col,int n,int m)
    {
        if(row<0 ||row>=n || col<0||col>=m)
            return false;
        return true;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        int n =grid.size();
        int m = grid[0].size();
        int fresh =0;
        int time =0;
        queue <pair<int,int>> q;
        vector<vector<bool>> check(grid.size(),vector <bool>(grid[0].size(),false));
        
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        while(!q.empty()and fresh>0)
        {
            time++;
            int life=q.size();
         
           while(life--)
           {
            pair<int,int> p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;
            for(int k=0;k<4;k++)
            {
                int row =r+x[k];
                int col =c+y[k];
                if(valid(row,col,n,m) && grid[row][col]==1 && check[row][col]==false)
                {
                    
                    fresh--;
                    check[row][col]=true;
                    grid[row][col] = 2; 
                    q.push({row,col});
                }
            }
           }
        }
        if(fresh>0)
            return -1;
        else
            return time;
    }
};;