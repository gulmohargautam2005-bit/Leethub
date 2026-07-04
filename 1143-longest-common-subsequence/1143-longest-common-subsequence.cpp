class Solution {
public:
    int fun(string &text1, string &text2,vector<vector<int>>&dp, int i, int j,int &n, int &m)
    {
        if(i==n || j==m)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(text1[i]==text2[j])
        {
            return dp[i][j]= 1+fun(text1,text2,dp,i+1,j+1,n,m);
        }
        int c1 = fun(text1,text2,dp,i+1,j,n,m);
        int c2 = fun(text1,text2,dp,i,j+1,n,m);
        return dp[i][j]= max(c1,c2);

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1);
        vector<int> temp(m+1,-1);
        for(int i=0;i<n;i++)
        {
            dp[i]=temp;
        }
        return fun(text1,text2,dp,0,0,n,m);
        
    }
};