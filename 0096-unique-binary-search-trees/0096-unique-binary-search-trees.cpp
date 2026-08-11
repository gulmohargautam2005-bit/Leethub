class Solution {
public:
    long long fact(int n,unordered_map<int,long long> &dp)
    {
        if(n==1)
            return dp[n]=1;
        if(n==0)
            return dp[n]=1;
        if(dp.find(n)!=dp.end())
            return dp[n];
        return dp[n]=fact(n-1,dp)*(4LL*n-2)/(n+1);
    }
    int numTrees(int n) {
        unordered_map<int,long long>dp;

        return fact(n,dp);
    }
};