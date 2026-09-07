class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        int ans=0;
        vector<vector<int>> res(2*n);
        for(int i=0;i<n;i++)
        {
            int src = edges[i][0];
            int dest = edges[i][1];
            res[src].push_back(dest);
            res[dest].push_back(src);
        }
        for(int i =0;i<=n+1;i++)
        {
            if(res[i].size()>res[ans].size())
            {
                ans = i;
            }
        }
        return ans;
    }
};