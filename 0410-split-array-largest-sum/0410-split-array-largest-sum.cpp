class Solution {
public:
    bool check(int limit,vector<int>&nums,int &k)
    {
       int n= nums.size();
       int page=0;
       int t=1;
       for(int i=0;i<n;i++)
       {
            if(page+nums[i]<=limit)
            {
                page= page+nums[i];
            }
            else
            {
                t++;
                page=nums[i];
                if(t>k)
                    return false;
            }
       }
      return true;
    }
    int splitArray(vector<int>& nums, int k) {
        
        int sum =0;
        int maxi = INT_MIN;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            maxi = max(maxi,nums[i]);
            sum = sum +nums[i];
        }
        int low =maxi;
        int high =sum;
        while(high>=low)
        {
            int mid = (high+low)/2;
            if(check(mid,nums,k))
            {
                res =mid;
                high =mid-1;
            }
            else
            {
                low =mid+1;
            }
        }

        return res;
    }
};