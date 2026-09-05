class Solution {
public:
    bool backtrack(int start,
                   int currSum,
                   int target,
                   int k,
                   vector<int>& nums,
                   vector<bool>& used) {

        // We have successfully formed k-1 subsets.
        // The remaining elements automatically form the last subset.
        if (k == 1)
            return true;

        // Current subset is complete
        if (currSum == target) {
            return backtrack(0, 0, target, k - 1, nums, used);
        }

        for (int i = start; i < nums.size(); i++) {

            // Already used
            if (used[i])
                continue;

            // Don't exceed target
            if (currSum + nums[i] > target)
                continue;

            // Take nums[i]
            used[i] = true;

            if (backtrack(i + 1,
                          currSum + nums[i],
                          target,
                          k,
                          nums,
                          used))
                return true;

            // Undo
            used[i] = false;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int total = 0;

        for (int x : nums)
            total += x;

        // Total must be divisible by k
        if (total % k != 0)
            return false;

        int target = total / k;

        // If any number itself is greater than target,
        // it can never belong to a valid subset.
        for (int x : nums) {
            if (x > target)
                return false;
        }

        vector<bool> used(nums.size(), false);

        return backtrack(0, 0, target, k, nums, used);
    }
};