class Solution {
public:
vector<vector<int>>res;
    void dfs(int node,vector<vector<int>>& graph,vector<bool>& visited,vector<int> & temp,int old)
    {
       temp.push_back(node);
       if( node ==graph.size()-1)
       {
            res.push_back(temp);
       }
       for(int i =0;i<graph[node].size();i++)
       {
        int neigh = graph[node][i];
        dfs(neigh,graph,visited,temp,old);
        temp.pop_back();    
       }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
       vector<bool> visited(graph.size(),false);
       vector<int> temp;
       dfs( 0,graph,visited,temp,0);
       return res;
     
    }
};