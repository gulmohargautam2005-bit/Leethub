class Solution {
public:
    bool check(int &r,int &c,int &n,int&m)
    {
        if(r<0 || r>=n || c<0 || c>=m)
            return false;
        return true;
    }
    int dfs(priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>&pq,vector<vector<int>>&res,int (&x)[],int (&y)[],int &n,int &m,vector<vector<int>>& heights)
    {
        while(!pq.empty())
        {
            pair<int,pair<int,int>> p =pq.top();
            pq.pop();
            int d = p.first;
            int row = p.second.first;
            int col = p.second.second;
            for(int i =0;i<4;i++)
            {
                int r = row+x[i];
                int c = col +y[i];
                if(!check(r,c,n,m))
                {
                    continue;
                }
                int diff = abs(heights[row][col]-heights[r][c]);
                int absmax = max(d,diff);
                if(absmax<res[r][c])
                {
                    res[r][c]=absmax;
                    pq.push({absmax,{r,c}});
                }
            }
        }
        return res[n-1][m-1];
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int x[4] ={1,-1,0,0};
        int y[4]={0,0,1,-1};
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>> res(n,vector <int> (m,INT_MAX));
        res[0][0] = 0;
        pq.push({0,{0,0}});
        return dfs(pq,res,x,y,n,m,heights);
    }
};