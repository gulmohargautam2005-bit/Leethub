class Solution {
public:
    void fun(int idx,int n  ,vector<int> temp,vector<vector<int>> &res,vector<int>& nums)
    {
 
            res.push_back(temp);

        for(int i= idx;i<n;i++)
        {
            if(i>idx && nums[i]==nums[i-1])
                continue;
            temp.push_back(nums[i]);
            fun(i+1,n,temp,res,nums);
            temp.pop_back();
          
        }
      

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> res;
        int n =nums.size();
        sort(nums.begin(),nums.end());

        fun(0,n,temp,res,nums);
        return res;
    }
};