class Solution {
public:
bool x;
    bool fun(int i,int n,vector<int>& nums,vector <int> &dp)
    {
        if(i==(n-1))
        {   
            return dp[i]= true;
        }
        if(dp[i]!=-1)
            return dp[i];
        for(int j =i+1;j<=i+nums[i] &&  j<=n-1;j++)
        {
            if(fun(j, n, nums, dp))
                return dp[i] = true;
        }
        return dp[i]= false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector <int> dp(n,-1);
        return fun(0,n,nums,dp);

    }
};