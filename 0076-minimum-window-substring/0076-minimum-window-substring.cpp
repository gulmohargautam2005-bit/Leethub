class Solution {
public:
   bool check(unordered_map<char,int> &f,
           unordered_map<char,int> &f2)
{
    for(auto it : f2)
    {
        if(f[it.first] < it.second)
        {
            return false;
        }
    }
    return true;
}

    string minWindow(string s, string t) {
        int n = s.size();
        int n2 = t.size();
        int start = -1;
        int low =0;
        int maxi =INT_MAX;
        int high =0;
        unordered_map<char,int> f;
        unordered_map<char,int> f2;
        for(int i =0;i<n2;i++)
        {
            f2[t[i]]++;
        }
        for(high=0;high<n;high++)
        {
            f[s[high]]++;
            
            while(check(f,f2))
            {
                if(high - low + 1 < maxi)
                {
                    maxi = high - low + 1;
                    start = low;
                }
                f[s[low]]--;
                if(f[s[low]]==0)
                    f.erase(s[low]);
                low++;
            }
         

        }
            if(maxi!=INT_MAX)
                return s.substr(start,maxi);
            else
                return "";
    }
};