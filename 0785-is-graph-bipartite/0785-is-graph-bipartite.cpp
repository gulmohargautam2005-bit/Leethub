class Solution {
public:
    void dfs(vector<vector<int>>&graph,vector <int>&color,int node,int c,bool &res)
    {
        color[node]=c;
        for(int i=0;i<graph[node].size();i++)
        {
            int neigh =graph[node][i];
            if(color[neigh]==-1)
                dfs(graph,color,neigh,1-c,res);
            if(color[neigh]!=-1 && color[neigh] ==c)
                res=false;
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector <int> color (graph.size(),-1);
        int c=1;
        bool res=true;
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
                dfs(graph,color,i,c,res);
        }
       
        return res;
    }

        
    
};