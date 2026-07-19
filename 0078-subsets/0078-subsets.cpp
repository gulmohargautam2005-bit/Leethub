class Solution {
public:
    void fun(int idx,int &n,vector<int> temp,vector<vector<int>> &res,vector<int>&nums)
    {
        if(idx ==n)
        {
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        fun(idx+1,n,temp,res,nums);
        temp.pop_back();
        fun(idx + 1, n, temp, res, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector <int> temp;
        vector<vector<int>> res;
        fun(0,n,temp,res,nums);
        return res;
    }
};