class Solution {
public:
    int Findnext(vector<vector<int>> & array, int l,int end)
    {
        int r = array.size()-1;
        int ans = array.size();
        while(r>=l)
        {
            int mid = l +(r-l)/2;
            if(array[mid][0]>=end)
            {
                ans = mid;
                r= mid-1;
            }else
            {
                l =mid+1;
            }
        }
        return ans;

    }
    int fun(vector<vector<int>>& array,int i,vector<int> &dp)
    {
        int n = array.size();
        if(i==n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int next = Findnext(array,i+1,array[i][1]);
        int take = array[i][2]+fun(array,next,dp);
        int dont_take = fun(array,i+1,dp);
        return dp[i]= max(take,dont_take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> array(n,vector<int>(3,0));
        vector<int> dp(n,-1);
        for(int i =0;i<n;i++)
        {
            array[i][0]=startTime[i];
            array[i][1]=endTime[i];
            array[i][2]=profit[i];
        }
        sort(array.begin(),array.end());
        return fun(array,0,dp);
    }
};