class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map <int,int> f;
        unordered_map <int,int> f2;
        int n = nums.size();
        int count =0;
        int count2=0;
        int low =0;
        int high =0;
        for(high=0;high<n;high++)
        {
            f[nums[high]]++;
            while(f.size()>k)
            {
                f[nums[low]]--;
                if(f[nums[low]]==0)
                    f.erase(nums[low]);
                low++;
            }
            count = count+(high-low+1); 
            
        }
         low=0;
        for(high=0;high<n;high++)
        {
            f2[nums[high]]++;
            while(f2.size()>k-1)
            {
                f2[nums[low]]--;
                if(f2[nums[low]]==0)
                    f2.erase(nums[low]);
                low++;
            }
                count2 = count2+(high-low+1); 
            
        }
         return count-count2;
    }
};