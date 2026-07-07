class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())
             return 0;
        sort(nums.begin(),nums.end());
        int low=0;
        int n = nums.size();
        int high =0;
     
        int count =1;
        int maxi=1;
        while(high<n-1)
        {
         
           if(nums[high+1]-nums[high]==0)
           {
            high++;
            continue;
           }
           else if(nums[high+1]-nums[high] ==1)
           {
             count ++;
           }
           else
           {
              count =1;
           }
           maxi=max(maxi,count);
            high++;  
        }
        return maxi;
      
    }
};