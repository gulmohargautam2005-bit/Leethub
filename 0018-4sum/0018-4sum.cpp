class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int k =0;
        long long sum =0;
        int n=nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(k=0;k<n-3;k++)
        {
            if(k >0 && nums[k] == nums[k-1])
                continue;
            for(int l=k+1;l<n-2;l++)
            {
                if(l >k+1 && nums[l] == nums[l-1])
                    continue;
                int i=l+1;
                int j =n-1;
                
                while(i<j)
                {
                    sum=(long long)nums[k]+nums[l]+nums[i]+nums[j];
                    if(sum==target)
                    {
                        res.push_back({nums[k],nums[l],nums[i],nums[j]});
                        i++;
                        j--;
                        while(i < j && nums[i] == nums[i-1]) i++;
                        while(i < j && nums[j] == nums[j+1]) j--;
                    }
                    else if(sum<target)
                    {
                        i++;
                    }
                    else
                    {
                        j--;
                    }
                }

            }
         
            
        }
        return res;
        
    }
};