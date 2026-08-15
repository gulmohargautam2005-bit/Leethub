class Solution {
public:
    int fun(vector<int>& nums,int i ,int n,vector<int> &dp)
    {

        if(i>n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int a = nums[i]+fun(nums,i+2,n,dp);
        int b= fun(nums,i+1,n,dp);
        return dp[i]=max(a,b);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        vector<int> dp1(n,-1);
        vector<int> dp2(n,-1);
        return max(fun(nums,0,n-2,dp1),fun(nums,1,n-1,dp2));
        
    }
};