class Solution {
public:
    bool fun(int i,int currsum, int sum,vector<int>& nums,int k,vector<bool> &check)
    {
        if(k==1)
            return true;
        if(currsum==sum)
           return fun(0,0,sum,nums,k-1,check);
        for(int j =i;j<nums.size();j++)
        {
            if(check[j]==true)
                continue;
            if(nums[j]+currsum>sum)
                continue;
            check[j]=true;
            if(fun(j+1,currsum+nums[j],sum,nums,k,check))
                return true;
            check[j]=false;

        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        vector<int>dp(nums.size(),-1);
        int sum = 0;
        int halfsum =0;
        bool ans = false;
        vector<bool> check(nums.size(),false);
        if(nums.size()<k)
            return false;
        for(int i=0;i< nums.size();i++)
        {
            sum = sum +nums[i];
        }
        if(sum%k!=0)
            return false;
        halfsum = sum/k;
        for (int x : nums) {
            if (x > halfsum)
                return false;
        }
        return fun(0,0,halfsum,nums,k,check);
        
    }
};