class Solution {
public:
    int fun(vector<int>& nums,vector<vector<int>> &dp,int i,int n,int prev)
    {
        if(i==n)
            return 0;
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        if(prev==-1 || nums[i]>nums[prev])
        {
        int c1 =1+fun(nums,dp,i,n,i);
        int c2 = fun(nums,dp,i+1,n,prev);
        return dp[i][prev+1]=max(c1,c2);
        }
        return dp[i][prev+1]=fun(nums,dp,i+1,n,prev);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1);
        vector <int> temp(n+1,-1);
        for(int i=0;i<n;i++)
        {
            dp[i]=temp;
        }
        int prev =-1;
        return fun(nums,dp,0,n,prev);
        
    }
};