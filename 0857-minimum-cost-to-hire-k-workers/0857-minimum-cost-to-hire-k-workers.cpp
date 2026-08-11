class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        double res= DBL_MAX;
        int sum_quality =0;
        vector<pair<double,int>>worker_ratio(n);
        priority_queue<int> pq;
        for(int i =0;i<n;i++)
        {
            worker_ratio[i]=make_pair(((double)wage[i]/quality[i]),quality[i]);
        }
        sort(worker_ratio.begin(),worker_ratio.end());
        for(int i =0;i<k;i++)
        {
          sum_quality += worker_ratio[i].second;
          pq.push(worker_ratio[i].second);
        }
        res= worker_ratio[k-1].first*sum_quality;
        for(int i = k;i<n;i++)
        {
            double ans = worker_ratio[i].first;
            sum_quality =sum_quality+worker_ratio[i].second;
            pq.push(worker_ratio[i].second);
            if(pq.size()>k)
            {
                sum_quality-=pq.top();
                pq.pop();
            }
            res=min(res,ans*sum_quality);
        }
        return res;
    }
};