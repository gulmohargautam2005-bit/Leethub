class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low =0;
        int high =0;
        int maxi=INT_MIN;
        int maxi2=INT_MIN;
        int n =nums.size();
        unordered_map<int,int> f;
        for(high =0;high<n;high++)
        {
            f[nums[high]]++;
            maxi = max(maxi,f[1]);
            while((high-low+1)-maxi>k)
            {
                f[nums[low]]--;
                if(f[nums[low]]==0)
                    f.erase(nums[low]);
                low++;
            }
            if((high-low+1)-maxi<=k)
            {
                maxi2=max(maxi2,high-low+1);
            }
        }
        return maxi2;
    }
};