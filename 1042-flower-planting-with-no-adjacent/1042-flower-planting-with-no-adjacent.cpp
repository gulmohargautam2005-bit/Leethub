class Solution {
public:
    void dfs(vector<vector<int>>& res,int node,vector<int> &color)
    {
        for(int c =1;c<=4;c++)
        {
            bool possible =true;
            for(int i=0;i<res[node].size();i++)
            {
                int neigh =res[node][i];
                if(color[neigh]==c)
                {
                  possible = false;
                  break;
                }
            }
            if(possible)
            {
                color[node]=c;
                break;
            }
            
        }
        for(int i=0;i<res[node].size();i++)
        {
                int neigh =res[node][i];
                if(color[neigh]==0)
                {
                 dfs(res,neigh,color);
                }
        }
       
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> res (n+1);
        vector<int>color(n+1,0);
        for(int i=0;i<paths.size();i++)
        {
            int src = paths[i][0];
            int dest = paths[i][1];
            res[src].push_back(dest);
            res[dest].push_back(src);
        }
        for(int i =1;i<=n;i++)
        {
            if(color[i]==0)
                dfs(res,i,color);
        }
        color.erase(color.begin());
        return color;
    }
};