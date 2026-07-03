class Solution {
public:
int fun(int i,int n,unordered_map <int,int> &dp)
{
    if(i==n)
    {
        return 1;
    }
    if(i>n)
    {
        return 0;
    }
    if(dp.find(i)!=dp.end())
        return dp[i];
    int a1=fun(i+1,n,dp);
    int a2=fun(i+2,n,dp);
    int ans=a1+a2;
    dp[i]=a1+a2;
    return ans;
}
    int climbStairs(int n) {
        unordered_map <int,int> dp;
        return fun(0,n,dp)
        
    }
};