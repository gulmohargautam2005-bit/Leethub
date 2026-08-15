class Solution {
public:
    bool ans =true; 
    void dfs(vector<vector<int>> &res,vector <int> &color,int node,int c)
    {
        color[node]=c;
        for(int i=0;i<res[node].size();i++)
        {
            int neigh = res[node][i];
            if(color[neigh]!=-1 && color[neigh]==c)
                ans= false;
            if(color[neigh]==-1)
                dfs(res,color,neigh,1-c);
        }
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> res(n+1);
        vector <int> color(n+1,-1);
        int c=1;
        for(int i=0;i<dislikes.size();i++)
        {
            int src = dislikes[i][0];
            int dest = dislikes[i][1];
            res[src].push_back(dest);
            res[dest].push_back(src);
        }
        for(int i=0;i<res.size();i++)
        {
            if(color[i]==-1)
                dfs(res,color,i,c);
        }
        return ans;
    }
};