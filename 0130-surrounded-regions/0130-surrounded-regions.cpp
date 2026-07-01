class Solution {
public:
      bool valid(int row,int col,int n,int m)
    {
        if(row<0 || row>=n || col<0 ||col>=m)
            return false;
        return true;
    }
    void dfs(vector<vector<char>> &grid,int row,int col,int &res,int (&x)[],int (&y)[])
    {
        grid[row][col]='#';
        int n = grid.size();
        int m = grid[0].size();
        for(int k =0;k<4;k++)
        {
           
            int r=row+x[k];
            int c=col+y[k];
            if(valid(r,c,n,m) && grid[r][c]=='O')
            {
                dfs(grid,r,c,res,x,y);
            }
        }
        
        return;
    }
    void solve(vector<vector<char>>& board) {
        int x[4]={-1,1,0,0};
        int y[4]={0,0,-1,1};
        vector<vector <bool>>check(board.size(),vector<bool> (board[0].size(),false));
        int res=0;
        int n = board.size();
        int m = board[0].size();
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
                dfs(board,0,j,res,x,y);
        }
        for(int j=0;j<m;j++)
        {
            if(board[n-1][j]=='O')
                dfs(board,n-1,j,res,x,y);
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
                dfs(board,i,0,res,x,y);
        }
         for(int i=0;i<n;i++)
        {
            if(board[i][m-1]=='O')
                dfs(board,i,m-1,res,x,y);
        }
        for(int i =0;i<n;i++)
        {
            for (int j=0;j<m;j++)
            {
                if(board[i][j]=='#')
                {
                    board[i][j]='O';
                  
                  }
                  else
                  {
                    board[i][j]='X';
                  }
            }
        }

    };
        
    
};