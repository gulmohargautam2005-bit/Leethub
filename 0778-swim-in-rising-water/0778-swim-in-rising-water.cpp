class Solution {
public:
    
   bool valid(int r,int c,int n,int m)
   {
        if(r<0 || r>=n || c<0 || c>=m)
        {
            return false;
        }
        return true;
   }
    bool bfs(vector<vector<int>>& grid,int (&x)[],int (&y)[],vector<vector<bool>>&check,int guess,queue<pair<int,int>> &p)
    {
        if (grid[0][0] > guess)
            return false;
        int n =grid.size();
        int m =grid[0].size();
        while(!p.empty())
        {
           
            pair<int,int> f =p.front();
            int row =f.first;
            int col =f.second;
            p.pop();  
            if (row == n - 1 && col == m - 1)
                return true;
            for(int k =0;k<4;k++)
            {
                int r = row +x[k];
                int c = col + y[k];
              
                if( valid(r,c,n,m) && check[r][c]==false &&grid[r][c]<=guess)
                {
                    check[r][c]=true;
                    p.push({r,c});
                }
             }

        }
       
        return false;
    }
    int fun(vector<vector<int>>& grid,int (&x)[],int (&y)[],vector<vector<bool>>&check,int &res,queue<pair<int,int>> &p)
    {
        int n =grid.size();
        int m =grid[0].size();
        int low = grid[0][0];
        int high =INT_MIN;
        int guess;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j <m;j++)
            {
            high = max(high,grid[i][j]);
            }
        }
        while(high>=low)
        {
            vector<vector<bool>> check(n, vector<bool>(m, false));
            queue<pair<int,int>> p;

            check[0][0] = true;
            p.push({0,0});

            guess =low +(high-low)/2;
            if(bfs(grid,x,y,check,guess,p))
            {
                res =guess;
                high =guess-1;
            }
            else
            {
                low =guess+1;
            }
        }
        return res;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        int res =0;

        vector<vector<bool>> check (grid.size(),vector<bool>(grid[0].size(),false));
        queue <pair<int,int>>p;
        p.push({0,0});
        check[0][0]=true;
        return fun(grid,x,y,check,res,p);
    }
};