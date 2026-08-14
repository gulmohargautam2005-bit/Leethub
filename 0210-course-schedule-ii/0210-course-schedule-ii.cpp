class Solution {
public:
    // void dfs(vector<vector<int>> &res,vector<bool> &check,vector<bool> &path,bool &cycle,int node)
    // {
    //     check[node]=true;
    //     path[node]=true;
    //     for(int i =0;i<res[node].size();i++)
    //     {
    //         int neigh = res[node][i];
    //         if(check[neigh]==true && path[neigh]==true)
    //         {
    //             cycle=true;
    //             return;
    //         }
    //         if(check[neigh]==false)
    //         {
    //             dfs(res,check,path,cycle,neigh);
    //         }
    //     }
    //     path[node]=false;
    // }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> res(numCourses);
        vector<int> ans;
        unordered_map<int,int> indegree;
        queue<int> pq;
        bool cycle=false;
        for(int i=0;i<prerequisites.size();i++)
        {
            int  dest = prerequisites[i][0];
            int  src = prerequisites[i][1];
            res[src].push_back(dest);
            indegree[dest]++;
        }
        for(int i =0;i<numCourses;i++)
        {
            if(indegree[i]==0)
            {   ans.push_back(i);
                pq.push(i);
            }
        }
        while(!pq.empty())
        {
            int node = pq.front();
            pq.pop();
            for(int i =0;i<res[node].size();i++)
            {  
                int neigh = res[node][i];
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {   ans.push_back(neigh);
                    pq.push(neigh);
                }
            }
        }
     
        if(ans.size() != numCourses)
        {
            return {};
        }

        return ans;
            
            }
};