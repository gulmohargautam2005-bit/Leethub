class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Step 1: Mark visited numbers by negating values at target indices
        for (int i = 0; i < nums.size(); ++i) {
            int targetIndex = abs(nums[i]) - 1;
            if (nums[targetIndex] > 0) {
                nums[targetIndex] = -nums[targetIndex];
            }
        }
        
        // Step 2: Indices with positive values correspond to missing numbers
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        
        return result;
    }
};