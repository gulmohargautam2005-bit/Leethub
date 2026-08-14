class Solution {
public:
    void dfs(vector<vector<int>> &res, vector <bool>&check,int node)
    {
        check[node]=true;
        for(int i =0;i<res[node].size();i++)
        {
            int neigh =res[node][i];
            if(check[neigh]==false)
            {
                dfs(res,check,neigh);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n =isConnected.size();
        vector<vector<int>> res(n+1);
        vector <bool> check(n+1,false);
        int ans =0;
         for(int i=1;i<n+1;i++)
         {
            for(int j =1;j<n+1;j++)
            {
                int src = i-1;
                int dest = j-1;
                if(isConnected[i-1][j-1]==1)
                    res[src+1].push_back(dest+1);
            }

         }
         for(int i=1;i<=n;i++)
         {
            if(check[i]==false)
            {
                dfs(res,check,i);
                ans++;
            }
         }
         return ans;
        
    }
};