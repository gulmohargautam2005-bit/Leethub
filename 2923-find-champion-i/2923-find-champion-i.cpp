class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        vector<vector<int>>res(grid.size()+1);
        int ans =0;
        vector<bool>visited(grid.size()+1,false);
        for(int i=0;i<grid.size();i++)
        {
            for(int j =0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    res[i].push_back(j);
                }
            }
        }
        for(int i =1;i<grid.size();i++)
        {
            if(res[i].size()>res[ans].size())
                ans=i;
        }
        return ans;
        
    }
};