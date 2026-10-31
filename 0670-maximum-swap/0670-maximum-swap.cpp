class Solution {
public:
    int maximumSwap(int num) {
        priority_queue<pair<int,int>>pq;
        vector<int> v;
        int d = num;
        int sum =0;
        int j=0;
        while(d>0)
        {
            int k = d%10;
            v.push_back(k);
            d=d/10;
        }
        reverse(v.begin(), v.end());
        for(int i =0;i<v.size();i++)
        {
            pq.push({v[i],i});
        }
        bool swaped = false;
        while( j<v.size() && !swaped)
        {
            pair<int,int> p = pq.top();
            int k =p.first;
            if(j<p.second && v[j]!=k)
            {
                swap(v[j],v[p.second]);
                swaped=true;
            }
            else if(v[j]==k)
            {
                j++;
            }
            else
            {
            pq.pop();
            }
        }
        for(int i =0;i<v.size();i++)
        {
            sum = sum*10+v[i];
        }
        return sum;
    }
};