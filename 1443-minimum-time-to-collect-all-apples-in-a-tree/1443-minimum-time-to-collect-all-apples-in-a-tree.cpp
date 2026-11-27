class Solution {
public:
    int path =0;
    bool dfs(int node,vector<vector<int>> & res,vector<bool>&visited,vector<bool>& hasApple)
    {
       
        visited[node]=true;
        bool apple = hasApple[node];
        for(int i =0;i<res[node].size();i++)
        {
            int neigh = res[node][i];
            if(visited[neigh]==false)
            {
                if(dfs(neigh,res,visited,hasApple))
                {
                    path = path+2;
                    apple = true;
                }
                
            }
        }
        return apple;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> res(n+1);
        vector<bool> visited(n+1,false);
        for(int i =0;i<edges.size();i++)
        {
            int src = edges[i][0];
            int dest = edges[i][1];
            res[src].push_back(dest);
            res[dest].push_back(src);
        }
        dfs(0,res,visited,hasApple);
        return path;

    }
};