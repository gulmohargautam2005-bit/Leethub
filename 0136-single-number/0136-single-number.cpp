class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int result =0;
        for(int i =0;i<n;i++)
        {
            result = result^nums[i];
        }
        return result;

        // unordered_map<int,int> f;
        // int sum =0;
        // for(int i =0;i<n;i++)
        // {
        //     sum = sum +nums[i];
        //     f[nums[i]]++;
        //     if(f[nums[i]]>1)
        //         sum = sum -nums[i]*f[nums[i]];
        // }        
        // return sum;
    }
};