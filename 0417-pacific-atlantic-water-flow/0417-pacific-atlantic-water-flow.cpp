class Solution {
public:
    bool valid(int &r,int &c,int &n,int &m)
    {
        if(r<0 ||r>=n ||c<0||c>=m)  
            return false;
        return true;
    }
    void dfs(int row,int col,int prev,vector<vector<bool>>&demo,vector<vector<int>>& heights,int (&x)[],int (&y)[])
    {
        demo[row][col] = true;
        int n = heights.size();
        int m = heights[0].size();
        for(int i=0;i<4;i++)
        {
            int r = row+x[i];
            int c = col+y[i];
            if(valid(r,c,n,m) && demo[r][c]==false && heights[r][c]>=prev)
            {
                dfs(r,c,heights[r][c],demo,heights,x,y);
            }   
        }
     
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> atlantic(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<bool>> pacific(heights.size(),vector<bool>(heights[0].size(),false));
        vector<vector<int>> res;
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        //top and bottom for pacific and atklantic values 
       // Pacific: top + left
        for(int i = 0; i < m; i++)
        {
            dfs(0, i, heights[0][i], pacific, heights, x, y);
        }

        for(int i = 0; i < n; i++)
        {
            dfs(i, 0, heights[i][0], pacific, heights, x, y);
        }

        // Atlantic: bottom + right
        for(int i = 0; i < m; i++)
        {
            dfs(n - 1, i, heights[n - 1][i], atlantic, heights, x, y);
        }

        for(int i = 0; i < n; i++)
        {
            dfs(i, m - 1, heights[i][m - 1], atlantic, heights, x, y);
        }
                for(int i=0;i<heights.size();i++)
        {
            for(int j =0;j<heights[0].size();j++)
            {
                if(pacific[i][j] && atlantic[i][j]) 
                    res.push_back({i, j});
            }
        }
        return res;       
    }
};