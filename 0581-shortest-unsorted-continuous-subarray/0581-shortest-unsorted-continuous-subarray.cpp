class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int m=0;
        int start =0;
        int end =0;
        int mini =  INT_MAX;
        int maxi =INT_MIN;
        for(int i=0;i<n;i++)
        {
            int j =n-1-i;
            maxi = max(maxi,nums[i]);
            if(nums[i]<maxi)
            {
                end=i;
            }
            mini = min(mini,nums[j]);
            if(nums[j]>mini)
            {
                start=j;
            }
        }
        if( start ==0 && end==0)
            return 0;
        else
            return end-start+1;
    }
};