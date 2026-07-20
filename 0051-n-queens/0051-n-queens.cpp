class Solution {
public:
    vector<vector<string>> result;
    bool isqueen(int row, int col,vector<string> &board,int n)
    {
        //upper check
        for(int i =1;i<=row;i++)
        {
            if(board[row-i][col]=='Q')
                return false;
        }
        
        // upper right check
        for(int i=row-1,j =col+1;i>=0 && j <=n;i--,j++)
        {
            if(board[i][j]=='Q')
                return false;
        }
        //upper left check
        for(int i=row-1,j =col-1;i>=0 && j >=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
      return true;

    }
    void solve(vector<string> &board,int rows,int n)
    {
        if(rows>=n)
        {
            result.push_back(board);
            return;
        }
        for(int col =0;col<n;col++)
        {
          if(isqueen(rows,col,board,n))
          {
           board[rows][col]='Q';
           solve(board,rows+1,n);
           board[rows][col]='.';
          }
     
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> res(n);
        for(int i=0;i<n;i++)
        {
             res[i] = string(n, '.');
        }
    
        solve(res,0,n);
        return result;
        
    }
};