class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int low =0;
        int high =0;
        int n =nums.size();
        priority_queue <pair<int,int>> pq;
        int maxi =INT_MIN;
        vector <int> res;
        for(high =0;high<n;high++)
        {
            pq.push({nums[high],high});
            if((high-low+1)==k)
            {
                pair<int,int> p = pq.top();
               
                res.push_back(p.first);
                low++;
                 while(!pq.empty() && pq.top().second < low)
                    {
                        pq.pop();
                    }
            }
        }
        return res;
        
    }
};