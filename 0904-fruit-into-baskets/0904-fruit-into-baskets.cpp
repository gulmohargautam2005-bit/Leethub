class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n= fruits.size();
        unordered_map<int,int> f;
        int low =0;
        int high =0;
        int maxi=INT_MIN;
         for(high =0;high<n;high++)
         {
           f[fruits[high]]++;
           while(f.size()>2)
           {
                f[fruits[low]]--;
                if(f[fruits[low]]==0)
                {
                    f.erase(fruits[low]);
                }
                low++;
            }
            if(f.size()==2)
            {
                maxi = max(maxi,high-low+1);
            }
         }
         if(maxi!=INT_MIN)
            return maxi;
        else
            return fruits.size();
        
    }
};