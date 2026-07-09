class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return;
        int m = matrix[0].size();
        vector<pair<int,int>> p;
        for(int i=0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                if(matrix[i][j]==0)
                { 
                   p.push_back({i,j});
                }
            }
        }  
        if(p.size()==0)
            return;
        int s = p.size()-1;
        int t=0;
        
        while(s>=0)
        {
             int k=p[t].first;
             int l =p[t].second;
             for(int i=0;i<m;i++)
             {
               
                matrix[k][i]=0;
             }
            for(int i=0;i<n;i++)
             {
               
                matrix[i][l]=0;
             }
           t++;
           s--;
        }      
    }
};