class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n =nums.size();
        vector<vector<int>> res;
        int k=0;
        int i=1;
        int j=0;;
        int sum=0;
        sort(nums.begin(),nums.end());

        for(int k=0;k<n-2;k++)
        {
        if(k >0 && nums[k] == nums[k-1])
              continue;
           i= k+1;
           j=n-1;
           while(i<j)
           {
                if(nums[k]==(-(nums[i]+nums[j])))
                {
                    res.push_back({nums[k],nums[i],nums[j]});
                    i++;
                    j--;
                    while(i<n&&nums[i]==nums[i-1])
                    {
                        i++;
                    }
                    while(j>0&&nums[j]==nums[j+1])
                    {
                        j--;
                    }

                }
                else if(nums[k]>(-(nums[i]+nums[j])) )
                {
                    j--;
                }
                else
                {
                    i++;
                }
           }
        }
        return res;
        
        
    }
};