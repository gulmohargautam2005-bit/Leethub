class Solution {
public:
    int fun(int i, int n, int cap, vector<int> &nums,vector<vector<int>> &dp,int &sum)
    {
        if(abs(cap) > sum)
            return 0;
        if(i==n &&cap==0)
            return 1;
        if(i==n && cap!=0)
            return 0;
        if(dp[i][cap+sum]!=-1)
            return dp[i][cap+sum];
        int a = fun(i+1,n,cap-nums[i],nums,dp,sum);
        int b = fun(i+1,n,cap+nums[i],nums,dp,sum);
        return dp[i][cap+sum]=a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum =0;
        for(int i =0;i<n;i++)
        {
            sum = sum+nums[i];
        }
     
        vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));
        return  fun(0,n,target,nums,dp,sum);
        
    }
};