class Solution {
public:
    bool check(int i ,int j , string &s , string &p, vector<vector<int>> &dp)
    {
        if(i==0 && j==0)
            return dp[i][j]= true;
        if(j==0 && i>0)
            return dp[i][j]=false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==0 && j>0)
        {
            for(int k =0;k<j;k++)
            {
                if(p[k]!='*')
                    return dp[i][j]= false;
            }   return dp[i][j]=true;
        }
        if(s[i-1]==p[j-1] || p[j-1]=='?')
        {
            return dp[i][j]= check(i-1,j-1,s,p,dp);
        }
        if(p[j-1]=='*')
        {
            return dp[i][j]= check(i-1,j,s,p,dp)||check(i,j-1,s,p,dp);
        }
        return dp[i][j]=false;
        

    }
    bool isMatch(string s, string p) {
        int i = s.size();
        int j = p.size();
        int n = i+j;
       vector<vector<int>> dp(i + 1);
        vector<int> temp(j + 1, -1);

        for (int k= 0; k <= i; k++)
        {
            dp[k] = temp;
        }
        return check(i,j,s,p,dp);
    }
};