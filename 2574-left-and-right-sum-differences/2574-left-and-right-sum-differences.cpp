class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(nums.size());
        vector<int> left(nums.size());
        vector<int> res(nums.size());
        int sum =0;
        for(int i =0;i<n;i++)
        {
            sum = sum +nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
                left[i]=0;
            else
                left[i]=nums[i-1]+left[i-1];
            right[i]=sum-nums[i]-left[i];
            res[i]=abs(left[i]-right[i]);
        }
        return res;
    }
};