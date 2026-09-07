class Solution {
public:
    bool dfs( int node, int destination,vector<vector<int>>&res,vector <bool> &visited)
    {
    if(node == destination)
        return true;
    visited[node] =true;
    for(int i =0;i<res[node].size();i++)
     {
        int neigh = res[node][i];
        if(visited[neigh]==false)
        {
            if(dfs(neigh,destination,res,visited))
                return true;
        }
     }
     return false;

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> res(n+1);
        vector <bool> visited(n+1,false);
        if(edges.size()==0)
            return true;
        for(int i=0;i<edges.size();i++)
        {
            int src = edges[i][0];
            int dest = edges[i][1];
            res[src].push_back(dest);
            res[dest].push_back(src);
        }
        return dfs(source,destination,res,visited);

    }
};