class Solution {
public:
    bool check (unordered_map <char,int> &f,unordered_map <char,int> &f2,int &mini)
    {
        for(auto it :f2)
        {
            if(f[it.first]>=it.second)
            {
              mini = min(mini,f[it.first]/it.second);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    int maxNumberOfBalloons(string text) {
        int n =text.size();
        string s = "balloon";
        unordered_map <char,int> f;
        unordered_map <char,int> f2;
        int low =0;
        int count =0;
        int high =0;
        int m =INT_MAX;
        for(int i =0;i<s.size();i++)
        {
            f2[s[i]]++;
        }
        for(high =0;high<n;high++)
        {
            f[text[high]]++;
            if((high-low+1)==n)
            {
                if(check(f,f2,m))
                    return m;
            }
        }
        return 0;
    }
};