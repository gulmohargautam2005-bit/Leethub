class Solution {
public:
    void dfs(vector<vector<int>>& res,vector<bool> &check,vector<bool> &path,bool &cycle,int &node)
    {
        check[node]=true;
        path[node]=true;
        for(int i =0;i<res[node].size();i++)
        {
            int neigh = res[node][i];
            if(check[neigh]==true && path[neigh]==true)
            {
                cycle=true;
                return;
            }
            if(check[neigh]==false)
            {
                dfs(res,check,path,cycle,neigh);
            }
        }
        path[node]=false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n  = numCourses;
        vector<vector<int>> res(numCourses);
        bool cycle =false;
        vector<bool> check(numCourses,false);
        vector<bool> path(numCourses,false);
        for(int i =0;i<prerequisites.size();i++)
        {
            int src = prerequisites[i][0];
            int dest = prerequisites[i][1];
            res[src].push_back(dest);
        }
        for(int i =0;i<n;i++)
        {
            if(check[i]==false)
                dfs(res,check,path,cycle,i);
        }
        return !cycle;

    }
};