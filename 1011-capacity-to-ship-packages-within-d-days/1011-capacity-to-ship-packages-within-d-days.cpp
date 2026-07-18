class Solution {
public:
    bool check(int &mid,vector<int> &weights,int &days)
    {   
        int i=0;
        int n =weights.size();
        int count =1;
        int temp=0;

        while(i<n)
        {
            if (weights[i] > mid)
                return false;
            if(temp+weights[i]<=mid)
            {
                temp=temp+weights[i];
                i++;
            }
            else
            {
                temp=0;
                count = count +1;
            }
         }
            if(count<=days)
                return true;
            return false;
    }
            

    
    int shipWithinDays(vector<int>& weights, int days) {
        int sum =0;
        int temp =0;
        int count =0;
        int res;
        for(int i=0;i<weights.size();i++)
        {
            sum = sum+weights[i];
        }
        int high =sum;
        int low =1;
        while(high>=low)
        {
            temp=0;
            int mid =(high+low)/2;
            if(check(mid,weights,days))
            {
                res =mid;
                high = mid-1;
            }
            else
            {
                low=mid+1;
            }

        }
     return res;
    }
};