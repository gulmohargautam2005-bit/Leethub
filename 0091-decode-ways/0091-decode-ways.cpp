class Solution {
public:
    int fun(int i , int &n,string &s,vector<int> &dp)
    {
        if(i==n)
            return  1;
        if(s[i]=='0')
            return dp[i]=0;
        if(dp[i]!=-1)
            return dp[i];
        int single_digit_split= fun(i+1,n,s,dp);
        int double_digit_split  =0;
        if(i+1<n)
        {
            if(s[i]=='1'||s[i]=='2'&& s[i+1]<='6')
            {
                double_digit_split = fun(i+2,n,s,dp);
            }
        }
        return dp[i]=double_digit_split+single_digit_split;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return fun(0,n,s,dp);
        
    }
};