class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int low =0;
        int mid=0;
        while(low<n)
        {
            if(nums[low]==0)
            {
            
                low++;
            
            }
            else
            {
                swap(nums[low],nums[mid]);
                low++;
                mid++;
            }
      
        }
    }
};