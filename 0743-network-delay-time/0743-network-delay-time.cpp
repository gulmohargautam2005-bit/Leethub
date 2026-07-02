class Solution {
public:
void bfs(vector<vector<pair<int,int>>> &res,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>&pq,vector <int> &dist)
  {
      while(!pq.empty())
      {
          pair <int,int>p =pq.top();
          int d=p.first;
          int node=p.second;
          pq.pop();
          if(d>dist[node])
              {
                  continue;
              }
          for(int i=0;i<res[node].size();i++)
          {
              int neigh = res[node][i].first;
              int weight =res[node][i].second;
          
              if((d+weight)<dist[neigh])
              {
                  dist[neigh]=d+weight;
                  pq.push({d+weight,neigh});
              }
          }
      }
  }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> res(n+1);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector <int> distance (n+1,INT_MAX);
        for(int i =0;i<times.size();i++)
        {
            int src= times[i][0];
            int dest = times[i][1];
            int weigh = times[i][2];
            res[src].push_back({dest,weigh});
          
        }
        pq.push({0,k});
        distance[k] = 0;
        bfs(res,pq,distance);
        int maxi=INT_MIN;
        for(int i=1;i<n+1;i++)
        {
            if(distance[i]==INT_MAX)
            {
                return -1;
            }
            maxi= max(maxi,distance[i]);
        }
        return maxi;
    }
        
    
};