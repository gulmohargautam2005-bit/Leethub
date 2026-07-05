class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         int n =nums.size();
        vector<vector<int>> res;
        int k=0;
        int i=1;
        int j=0;;
        int maxdiff = nums[0] + nums[1] + nums[2];
        int diff =0;
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
                sum = nums[i]+nums[k]+nums[j];
                if(target==sum)
                {
                    return sum;
                }
                if(abs(target-sum)<abs(target-maxdiff))
                {
                   
                
                        maxdiff =sum;
            
                  
                  
                }
                else if(target >sum) 
                {
                    i++;
                }
                else
                {
                    j--;
                }
           }
        }
        return maxdiff;
        
    }
};