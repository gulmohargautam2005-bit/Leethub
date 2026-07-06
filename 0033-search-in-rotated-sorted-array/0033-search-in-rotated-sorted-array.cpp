class Solution {
public:
    int search(vector<int>& nums, int target) {
       int n = nums.size();
       int low=0;
       int h;
       int l;
       int idx=0;
       int high =n-1;
       while(high>low)
       {
            int mid = (high+low)/2;
            if(nums[mid]>nums[n-1])
            {
               idx=mid+1;
               low=mid+1;
               
               
            }
            else
            {
                 high =mid;
               
            }
       }
       if(target>=nums[idx]&& target <=nums[n-1])
       {
         l = idx;
         h = n-1;
       }
        else
        {
            l=0;
            h=idx;
        }
        while(h>=l)
        {
            int m =(h+l)/2;
            if(nums[m]==target)
            {
                return m;
            }
            if(nums[m]>target)
            {
               h = m-1;
            }
            else
            {
                l=m+1;
            }
        }
       return -1;
    }
};