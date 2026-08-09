class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>f;
        struct cmp
        {
            bool operator()(pair<int,int>&a,pair<int,int>&b)
            {
                if(a.first!=b.first)
                    return a.first>b.first;
                return a.second>b.second;
            }
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;

        for(int i =0;i<nums.size();i++)
        {
            f[nums[i]]++;
        }
        for(auto i:f)
        {
            int ele = i.first;
            int freq = i.second;
            pair<int,int> curr = {freq,ele};
            if(pq.size()<k)
            {
                pq.push(curr);
            }
            else
            {
                 if(curr.first > pq.top().first)
                {
                    pq.pop();
                    pq.push(curr);
                }
            }
 
        }
        vector<int> v;
        for( int i=0 ;i<k;i++)
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;



        
    }
};