class Solution {
public:
    int fun(int n )
    {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n%2==0)
        {
            return fun(n/2);
        }
        return fun(n/2)+fun((n/2)+1);
    }
    int getMaximumGenerated(int n) {
        int ans =0;
        for(int i =0;i<=n;i++)
        {
         ans = max(ans,fun(i));
        }
        return ans;
    }
};