class Solution {
public:
    void fun(int idx,int n ,vector<int> temp,vector<vector<int>>&res,vector<int>& c,int target,int sum)
        {
 
        if(sum==target)
        {
            res.push_back(temp);
            return;
        }
        
            
            for(int i =idx;i<n;i++)
            {
                if(i>idx && c[i]==c[i-1])
                    continue;
                if(sum + c[i] > target) break;  
                temp.push_back(c[i]);
                sum = sum +c[i];
                fun(i+1,n,temp,res,c,target,sum);
                temp.pop_back();
                sum = sum-c[i];
            }

        
        }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum =0;
        vector<int> temp;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        fun(0,candidates.size(),temp,res,candidates,target,sum);
        return res;
    }
};