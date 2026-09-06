class Solution {
public:
    int fun(int n,vector<int> &dp)
    {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        return dp[n]=(fun(n-3,dp)+fun(n-2,dp)+fun(n-1,dp));
    }
    int tribonacci(int n) {
      vector<int> dp(n+2,-1);
      return fun(n,dp);
    }
};