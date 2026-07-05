class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> res;
        vector <pair<int,int>> p;
        unordered_map<int,vector<int>>f;
        int n =nums.size();
        int i=0;
        int a=0;
        int b=0;
        int j =n-1;
        for(int i=0;i<n;i++)
        {
           f[nums[i]].push_back(i);
        }
        sort(nums.begin(),nums.end());
        while(i<=j)
        {
            int sum =nums[i]+nums[j];
            if(sum== target)
            {
                if(nums[i] == nums[j])
                {
                    res.push_back(f[nums[i]][0]);
                    res.push_back(f[nums[i]][1]);
                }
                else
                {
                    res.push_back(f[nums[i]][0]);
                    res.push_back(f[nums[j]][0]);
                }
                return res;
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
        return res;
        
    }
};