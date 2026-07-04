class Solution {
public:
    int fun(vector<int> &nums,vector<vector <int>>&dp,int i ,int &n,int s, int &sum)
    {
        if(i==n)
            return 0;
        if(dp[i][s]!=-1)
            return dp[i][s];
        if(s+nums[i]>sum)
            return fun(nums,dp,i+1,n,s,sum);
        int c1=nums[i]+fun(nums,dp,i+1,n,s+nums[i],sum);
        int c2=fun(nums,dp,i+1,n,s,sum);
        int ans = max(c1,c2);
        return dp[i][s]=ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        int halfsum=0;
        int s=0;
        int n =nums.size();
        for(int i=0;i<nums.size();i++)
        {
             sum=sum+nums[i];
        }
        if(sum%2==1)    
            return false;
        halfsum =sum/2;
        vector <vector<int>> dp(n+1);
        vector <int> temp(halfsum+1,-1);
        for(int i=0;i<n;i++)
        {
            dp[i]=temp;
        }
        if(fun(nums,dp,0,n,s,halfsum)==halfsum)
            return true;
        
        return false;
    }
};