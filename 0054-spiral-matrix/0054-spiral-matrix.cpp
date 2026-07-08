class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int > res;
        vector<vector<int>> ans;
        int top =0;
        int bottom= n-1 ;
        int left=0;
        int right=m-1 ;
        while(bottom >=top && right>=left)
        {
            for( int  i=left;i<=right;i++)
            {
                res.push_back(matrix[top][i]);
            }
            top++;
      
            for(int j=top;j<=bottom;j++)
            {
              res.push_back(matrix[j][right]);
            }
            right--;
            
            if(top<=bottom)
            {
                for(int i =right;i>=left;i--)
                {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left<=right)
            {
                for(int j =bottom ;j>=top;j--)
                {
                    res.push_back(matrix[j][left]);
                }
                left++;
            }
       
        }
       return res;

    }
};