class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans;
        vector<vector<int>> res(n+1);
        vector<int> indeg (n+1,0);
        vector<int> outdeg (n+1,0);
        for(int i =0;i<trust.size();i++)
        {
            int src = trust[i][0];
            int dest = trust[i][1];
            indeg[dest]++;
            outdeg[src]++;
        }
        for(int i =1;i<=n;i++)
        {
            if(indeg[i]==n-1 && outdeg[i]==0)
                  return i;
        }
        return -1;
    }
};