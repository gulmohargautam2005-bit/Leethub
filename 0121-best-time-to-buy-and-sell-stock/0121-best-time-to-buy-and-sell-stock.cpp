class Solution {
public:
    int fun(vector <int>&prices,vector<vector<int>> &dp,int i, int k,int n)
    {
        if(i==n || k==0)
        {
         return 0;
        }
        if(dp[i][k]!=-1)
        {
            return dp[i][k];
        }
        if(k==2)
        {
            int c1= -prices[i]+fun(prices,dp,i+1,k-1,n);
            int c2=  fun(prices,dp,i+1,k,n);
            return dp[i][k]=max(c1,c2);
        }
        else
        {
            int c1= prices[i]+fun(prices,dp,i+1,k-1,n);
            int c2 =fun(prices,dp,i+1,k,n);
            return dp[i][k]=max(c1,c2);
        }
        
    }
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int k=2;
        vector<vector<int>> dp(n+1);
        vector<int> temp(k+1,-1);
        for(int i=0;i<n+1;i++)
        {
            dp[i]=temp;
        }
       
        return fun(prices,dp,0,k,n);

    }
};