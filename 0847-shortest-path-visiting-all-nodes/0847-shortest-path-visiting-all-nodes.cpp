class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int,int>> que;
        set<pair<int,int>> visited;
        int path =0;
        if(graph.size()==1 || graph.size()==0)
            return 0;
        for(int i =0;i< n;i++)
        {
            int mask = (1<<i);
            que.push({i,mask});
            visited.insert({i,mask});

        }
        while(!que.empty())
        {
            int m = que.size();
            path++;
            while(m--)
            {
                pair<int,int> curr = que.front();
                que.pop();
                int node = curr.first;
                int maskvalue = curr.second;
                for(int &adj:graph[node])
                {
                    int nextmask = (1<<adj);
                    int next = maskvalue|nextmask;
                    if(next == (pow(2,n) - 1))
                        return path;
                    if (visited.find({adj,next})==visited.end())
                    {
                         visited.insert({adj,next});
                        que.push({adj,next});
                    }
                }
            }
        }
        return -1;
    }
};