class Solution {
public:
    int fun(int i, int n, int cap ,vector<int> &coins,vector<vector<int>>&dp)
    { 
        if(cap==0)
            return dp[i][cap]= 1;
        if(i==n)
            return 0;
        if(dp[i][cap]!=-1)
            return dp[i][cap];
        if(coins[i]>cap)
            return dp[i][cap]= fun(i+1,n,cap,coins,dp);
        int a = fun(i,n,cap-coins[i],coins,dp);
        int b  = fun(i+1,n,cap,coins,dp);
        return dp[i][cap]=a+b;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return fun(0,n,amount,coins,dp);
        
    }
};