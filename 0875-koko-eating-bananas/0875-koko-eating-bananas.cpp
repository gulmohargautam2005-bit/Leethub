class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int maxi = INT_MIN;
        long long sum =0;
        int res=0;
        for(int i =0;i<piles.size();i++)
        {
            maxi=max(maxi,piles[i]);
        }
        int high = maxi;
        while(high>=low)
        {
            sum=0;
            int mid = (high+low)/2;
            for(int i =0;i<piles.size();i++)
            {
                sum=sum+piles[i]/mid;
                if(piles[i]%mid!=0)
                {
                    sum++;
                }
            }
            if(sum<=h)
            {
                res = mid;
                high =mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return res;
    }
};