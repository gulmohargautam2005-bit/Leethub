class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<pair<int,pair<int,int>>> v;
        vector<int> res;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq2;
        long long time = 0;
        int j=0;
        for(int i=0;i<tasks.size();i++)
        {
            v.push_back({i,{tasks[i][0],tasks[i][1]}});
        }
        sort(v.begin(), v.end(), [](auto &a, auto &b)
        {
            return a.second.first < b.second.first;
        });
        while(res.size()<tasks.size())
        {
                   while(j < v.size() && v[j].second.first <= time)
                   {
                        pq2.push({v[j].second.second,v[j].first});
                        j++;      
                    }
                    if(pq2.empty())
                    {
                        time = v[j].second.first;
                    }
                    else
                    {
                    time =time+pq2.top().first;
                    res.push_back(pq2.top().second);
                    pq2.pop();

                    }
            
        }
        return res;
        
    }
};