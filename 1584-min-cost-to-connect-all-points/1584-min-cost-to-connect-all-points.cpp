class Solution {
public:
    int sum =0;
    void bfs(vector<vector<int>>& points,priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> &pq,vector <bool>& visited)
    {
        while(!pq.empty())
        {
            
            pair<int,int> a = pq.top();
            pq.pop();
            int weight= a.first;
            int index = a.second;
            int x= points[index][0];
            int y= points[index][1];
            if(visited[index]==true)
                continue;
            sum = sum+weight;
            visited[index]=true;
            for(int i=0;i<points.size();i++)
            {
             
                if(visited[i]==false)
                {
                    int x2 = points[i][0];
                    int y2= points[i][1];
                    int weight = abs(x-x2)+abs(y-y2);
                    pq.push({weight,i});
                }
            }
        }

    }
    int minCostConnectPoints(vector<vector<int>>& points) {
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
         vector<bool>visited(points.size(),false);
         pq.push({0,0});
         bfs(points,pq,visited);
         return sum;
    }
};