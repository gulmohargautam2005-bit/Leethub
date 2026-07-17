class Solution {
public:

    int fun(int i, int j, string &s,vector<vector<int>>&dp)
    {
        if(i>j)
        {
            return 0 ;
        }
        if(i==j)
        {
            return 1;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(s[i]==s[j])
        {
            return dp[i][j]= 2+fun(i+1,j-1,s,dp);
        }
        int c1= fun(i+1,j,s,dp);
        int c2 = fun(i,j-1,s,dp);
        return dp[i][j] =max(c1,c2);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string res="";
        vector<vector<int>> dp(n);
        vector<int> temp (n+1,-1);
        for(int i=0;i<n;i++)
        {
            dp[i]=temp;
        }
        return fun(0,n-1,s,dp);
    }
};