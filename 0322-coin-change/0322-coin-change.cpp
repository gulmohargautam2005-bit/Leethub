class Solution {
public: 
    int ans=0;
    int knapsnack(int i ,int n , int cap,vector<int>& coins,int count,vector<vector<int>> &dp )
    {
        if(cap==0)
            return 0;
        if(i==n)
            return 1e9;
        if(dp[i][cap]!=-1)
            return dp[i][cap];
        if(coins[i]>cap)
            return dp[i][cap]= knapsnack(i+1,n,cap,coins,count,dp);
        int a = 1+knapsnack(i,n,cap-coins[i],coins,count+1,dp);
        int b  = knapsnack(i+1,n,cap,coins,count,dp);
   
        return dp[i][cap]=min(a,b);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n =coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int count =0;
        if(amount ==0)
            return 0;
        int ans =knapsnack(0,n,amount,coins,count,dp);
        if(ans>=1e9)
            return -1;
        else 
            return ans;
        
    }
};