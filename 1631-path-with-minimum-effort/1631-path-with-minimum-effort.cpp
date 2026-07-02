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
   int bfs(vector<vector<int>> &res,priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>&pq,int &n,int &m,vector<vector<int>> &heights,int (&x)[],int (&y)[])
   {
      while(!pq.empty())
      {
          pair<int, pair<int,int>> p = pq.top();
          int d=p.first;
          int row=p.second.first;
          int col = p.second.second;
          pq.pop();
          
          for(int k=0;k<4;k++)
          {
            int r = row +x[k];
            int c =col +y[k];
            if(!valid(r,c,n,m))
                continue;
            int diff = abs(heights[row][col]-heights[r][c]);
            int absmax =max(d,diff);
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
        int x[4]={1,-1,0,0};
        int y[4]={0,0,1,-1};
        int n =heights.size();
        int m =heights[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));

       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        res[0][0] = 0;
        pq.push({0,{0,0}});
        
    
        return bfs(res,pq,n,m,heights,x,y);
    }
        
        
};