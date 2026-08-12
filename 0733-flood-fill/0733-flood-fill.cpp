class Solution {
public:
    bool valid(int &r, int &c,int &n,int &m)
    {
        if(r<0 ||r>=n||c<0||c>=m)
            return false;
        return true;
    }
    void dfs(vector<vector<int>>& image,int &row, int &col, vector<vector<bool>>&check,int &color2,int &color,int (&x)[],int (&y)[])
    {
        int n  = image.size();
        int m = image[0].size();
        for(int i =0;i<4;i++)
        {
            int r = row+x[i];
            int c = col+y[i];
            if(valid(r,c,n,m) && check[r][c]==false && image[r][c]==color2)
            {
                check[r][c]=true;
                image[r][c]=color;
                dfs(image,r,c,check,color2,color,x,y);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int x[4]={1,-1,0,0,};
        int y[4]={0,0,1,-1};
        vector<vector<bool>> check (image.size(),vector<bool>(image[0].size(),false));
        int color2 = image[sr][sc];
        image[sr][sc]=color;
        vector<int> temp;
        vector<vector<int>> res;
        dfs(image,sr,sc,check,color2,color,x,y);
       
        for(int i =0;i<image.size();i++)
        {
            for(int j=0;j<image[0].size();j++)
            {
                temp.push_back(image[i][j]);
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;

    }
};