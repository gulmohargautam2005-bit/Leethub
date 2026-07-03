class Solution {
public:
    int fibbo(int n,unordered_map <int,int> &dp)
    {
       
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(dp.find(n)!=dp.end())
            return dp[n];
        int c1 = fibbo(n-1,dp);
        int c2 = fibbo(n-2,dp);
        dp[n]=c1+c2;
        return c1+c2;
    }
    int fib(int n) {
        unordered_map <int,int> dp;
        return fibbo(n,dp);
    }
};