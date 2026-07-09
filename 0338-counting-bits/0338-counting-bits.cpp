class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans;
        int res=0;
        int d=0;
        ans.push_back(0);
        for(int i =1;i<=n;i++)
        {
            
            d =i;
            while(d>=1)
            {
              res = res+d%2;
              d=d/2;
            }
            ans.push_back(res);
            res=0;
        }
        return ans;
        
    }
};