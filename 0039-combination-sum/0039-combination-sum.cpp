class Solution {
public:
    void fun(int idx,int n ,vector<int> temp,vector<vector<int>>&res,vector<int>& c,int target,int sum)
    {
        if(idx==n)
        {
            if(sum==target)
            {
            res.push_back(temp);
            }
            return;
        }
        fun(idx+1,n,temp,res,c,target,sum);
        if(sum+c[idx]<=target)
        {
            temp.push_back(c[idx]);
            sum = sum +c[idx];
            fun(idx,n,temp,res,c,target,sum);
            temp.pop_back();
            sum = sum-c[idx];
        }

      
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum =0;
        vector<int> temp;
        vector<vector<int>> res;
        fun(0,candidates.size(),temp,res,candidates,target,sum);
        return res;
        
    }
};