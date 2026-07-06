class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low=0;
        int n = nums.size();
        int high = n-1;
        int peak=0;
        while(high>low)
        {
            int mid = (high+low)/2;
            if(nums[mid+1]>nums[mid])
            {
                peak =mid+1;
                low=mid+1;
               
            }
            else
            {
                 high = mid;
              

            }
        }
        return peak;
    }
};