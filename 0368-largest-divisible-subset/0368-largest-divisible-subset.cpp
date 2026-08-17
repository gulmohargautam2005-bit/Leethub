class Solution {
public:
   int fun(int i, int prev, int n, vector<int>& nums,
            vector<vector<int>>& dp)
    {
        if(i == n)
            return 0;

        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1];

        // Don't take nums[i]
        int b = fun(i + 1, prev, n, nums, dp);

        // Take nums[i]
        int a = 0;

        if(prev == -1 || nums[i] % nums[prev] == 0)
        {
            a = 1 + fun(i + 1, i, n, nums, dp);
        }

        return dp[i][prev + 1] = max(a, b);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        fun(0, -1, n, nums, dp);

        // Reconstruct answer
        vector<int> result;

        int i = 0;
        int prev = -1;

        while(i < n)
        {
            // Option 1: take nums[i]
            if(prev == -1 || nums[i] % nums[prev] == 0)
            {
                int take = 1 + fun(i + 1, i, n, nums, dp);
                int skip = fun(i + 1, prev, n, nums, dp);

                if(take >= skip)
                {
                    result.push_back(nums[i]);
                    prev = i;
                    i++;
                    continue;
                }
            }

            // Skip nums[i]
            i++;
        }

        return result;
    }  
};