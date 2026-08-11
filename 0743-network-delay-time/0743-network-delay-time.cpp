class Solution {
public:
    void dfs(vector<vector<pair<int,int>>>& res,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>& pq,vector<int>&dest)
    {
        while(!pq.empty())
        {
            pair<int,int> p =pq.top();
            pq.pop();
            int d= p.first;
            int node = p.second;
            if(d>dest[node])
            {
                continue;
            }
            for(int i=0;i<res[node].size();i++)
            {
                int neigh=res[node][i].first;
                int weight =res[node][i].second;
                if((d+weight)<dest[neigh])
                {
                    dest[neigh]=d+weight;
                    pq.push({d+weight,neigh});
                }
            }

        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int nn = times.size();
        vector<vector<pair<int,int>>> res(n+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector <int> distance(n+1,INT_MAX);
        for(int i=0;i<times.size();i++)
        {
            int src = times[i][0];
            int dst= times[i][1];
            int weight = times[i][2];
            res[src].push_back({dst,weight});
        }
        distance[k]=0;
        pq.push({0,k});
        dfs(res, pq, distance);
        int ans = INT_MIN;
        for(int i=1;i<=n;i++)
        {
            if(distance[i]==INT_MAX)
            {
                return -1;
            }
            else
            {
                ans = max(ans,distance[i]);
            }
        }
        return ans;
    }
};