class Solution {
public:
    int sum =0;
    void dfs(int nx,int ny, map<pair<int,int>, vector<pair<int,int>>> &mp,set<pair<int,int>> &visited)
    {
        visited.insert({nx,ny});
        int count =0;
        for(int i =0;i<mp[{nx,ny}].size();i++)
        {
            int nbx =mp[{nx,ny}][i].first;
            int nby = mp[{nx,ny}][i].second;
            if(visited.find({nbx,nby})==visited.end())
                dfs(nbx,nby,mp,visited);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        map<pair<int,int>, vector<pair<int,int>>> mp;
        set<pair<int,int>> visited;
        set<pair<int,int>> erased;
        for(int i =0;i< stones.size();i++)
        {
            int x =stones[i][0];
            int y = stones[i][1];
            for(int j =0 ;j<stones.size();j++)
            {
                if(j!=i)
                {
                    if(stones[j][0]==x||stones[j][1]==y)
                    {
                        mp[{x,y}].push_back({stones[j][0],stones[j][1]});
                        mp[{stones[j][0],stones[j][1]}].push_back({x,y});
                    }
                }
            }
        }
        int components = 0;

        for(int i = 0; i < stones.size(); i++)
        {
            int x = stones[i][0];
            int y = stones[i][1];

            if(visited.find({x,y}) == visited.end())
            {
                components++;
                dfs(x,y,mp,visited);
            }
        }

        return stones.size() - components;
    }
};