class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        stack <int> st;
        queue <int> pq;
        vector<int> res;
        int n = graph.size();
        unordered_map <int,int> indegree;
        vector<vector<int>> reverse(n);
        for(int i=0;i<graph.size();i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                int neigh = graph[i][j];
                reverse[neigh].push_back(i);
                indegree[i]++;
            }
        }
        for(int i=0;i<graph.size();i++)
        {
            if(indegree[i]==0)
            {
                pq.push(i);
                res.push_back(i);
            }
        }
        while(!pq.empty())
        {
            int node = pq.front();
            pq.pop();
            for(int i=0;i<reverse[node].size();i++)
            {
                int neigh = reverse[node][i];
                indegree[neigh]--;
                if(indegree[neigh]==0)
                {
                    pq.push(neigh);
                    res.push_back(neigh);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};