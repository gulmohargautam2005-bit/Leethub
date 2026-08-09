class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        struct cmp
        {
          

            bool operator()(pair<int,int> &a, pair<int,int> &b)
            {
                if (abs(a.second-a.first)==abs(b.second-b.first)) {
                    return a < b; // Tie-breaker: larger value gets higher priority (sinks lower -> goes to top
                }
                return abs(a.second-a.first)<abs(b.second-b.first); // Max-heap based on distance
            
            }
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
        int  n = arr.size();
        int i;
 
        for(auto i: arr) 
        {
            pair<int,int> curr={x,i};
            if(pq.size()<k)
            {
                pq.push(curr);
            }
            else
            {
                if(abs(pq.top().second-x)>abs(i-x))
                {
                    pq.pop();
                    pq.push(curr);
                }
            }
         
        }
        vector <int> v;
        while(!pq.empty())
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        sort(v.begin(), v.end());
        return v;

        
    }
};