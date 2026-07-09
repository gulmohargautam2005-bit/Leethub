class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> matrix2(n,vector<int>(n));
        for( int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix2[i][j]=matrix[n-(j+1)][i];
            }
        }
        for( int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                matrix[i][j]=matrix2[i][j];
            }
        }
        
    }
};