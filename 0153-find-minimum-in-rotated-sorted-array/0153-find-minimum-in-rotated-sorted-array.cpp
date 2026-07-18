class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int res= 0;
        int n =nums.size();
        int high =nums.size()-1;
        while(high>=low)
        {
            int mid = (high+low)/2;
            if(nums[mid]>nums[n-1] )
            {
                low=mid+1;
                
                
            }
            else
            {
                
                res = nums[mid];
                high =mid-1;
               
            }
        }
        return res;

        
    }
};