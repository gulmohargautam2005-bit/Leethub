class Solution {
public:

    int fun(int i,vector<int>& prices , int fee,int k,vector<vector<int>> &dp)
    {
        if(i==prices.size())
            return 0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        if(k ==0)
            return dp[i][k] =max(-prices[i]+fun(i+1,prices,fee,1-k,dp),fun(i+1,prices,fee,k,dp));
        if(k==1)
            return dp[i][k]=max(fun(i+1,prices,fee,1-k,dp)+prices[i]-fee,fun(i+1,prices,fee,k,dp));
        return 0 ;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(2*prices.size(),vector<int>(2,-1));
        return fun(0,prices,fee,0,dp);

    }
};