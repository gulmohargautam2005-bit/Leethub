class Solution {
public:
    bool valid(int &r,int &c,int &n,int &m)
    {
        if(r<0||r>=n ||c<0||c>=m)
            return false;
        return true;
    }
    bool dfs(queue<pair<int,int>> &pq,vector<vector<bool>>&check,int (&x)[],int (&y)[],int &guess,vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        while(!pq.empty())
        {
            if(grid[0][0]>guess)
                return false;
            pair<int,int> p = pq.front();
            int row = p.first;
            int col = p.second;
            pq.pop();
            if(grid[row][col]==grid[n-1][m-1])
                return true;
            for(int i =0;i<4;i++)
            {
                int r = row+x[i];
                int c = col +y[i];
                if(valid(r,c,n,m) && check[r][c]==false && grid[r][c]<=guess )
                {
                    pq.push({r,c});
                    check[r][c]=true;
                }
            }
        }
        return false;
    }
    void fun(vector<vector<int>>& grid,int (&x)[],int (&y)[],int & res)
    {
        int n = grid.size();
        int m = grid[0].size();
        int low = grid[0][0];
        int high = INT_MIN;
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                high = max(high,grid[i][j]);
            }
        }
        while(high>=low)
        {
            vector<vector<bool>> check(n,vector<bool>(m,false));
            queue<pair<int,int>> pq;
            pq.push({0,0});
            int guess = low + (high - low) / 2;
            if(dfs(pq,check,x,y,guess,grid))
            {
                res = guess;
                high = guess-1;
            }
            else
            {
                low= guess+1;
            }
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        int res=0;
        fun(grid,x,y,res);
        return res;
        
    }
};