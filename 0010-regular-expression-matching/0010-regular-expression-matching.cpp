class Solution {
public:

    bool fun(int i , int j , string s , string p,vector<vector<int>> & dp)
    {
        bool first_char= false;
        if (i == s.size() && j == p.size())
            return true;
        if (j == p.size())
            return false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i<s.size() && (s[i]==p[j]||p[j]=='.'))
            first_char =true;    
        if(j + 1 < p.size() && p[j+1]=='*')
        {
            bool dont_take= fun(i,j+2,s,p,dp);
            bool take = first_char && fun(i+1,j,s,p,dp);
            return dp[i][j]= dont_take||take;
        }
        return dp[i][j]=first_char && fun(i+1,j+1,s,p,dp);
        }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return fun(0,0,s,p,dp);
    }
};