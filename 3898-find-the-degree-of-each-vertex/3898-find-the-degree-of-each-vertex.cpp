class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        vector<vector<int>> res(matrix.size());
        vector<bool> visisted(matrix.size(),false);
        vector<int> ans(matrix.size());
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                if(matrix[i][j]==1)
                {
                    res[i].push_back(j);

                }
            }
        }
        for(int i =0;i<matrix.size();i++)
        {
            {
                ans[i]=res[i].size();
            }
        }
        return ans;
    }
};