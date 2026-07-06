class Solution {
public:
    int characterReplacement(string s, int k) {
        int low=0;
        int high =0;
        int n =s.size();
        int maxi2=INT_MIN;
        int maxi =INT_MIN;
        unordered_map<char,int> f;
        priority_queue <pair<int,char>> pq;
        for(high =0;high<n;high++)
        {
            f[s[high]]++;
            maxi =max(maxi,f[s[high]]);
            while((high-low+1)-maxi>k)
            {
                f[s[low]]--;
                if(f[s[low]]==0)
                    f.erase(s[low]);
                low++;
            }
            if((high-low+1)-maxi<=k)
            {
                maxi2=max(maxi2,high-low+1);

            }
        }
        return maxi2;
    }
};