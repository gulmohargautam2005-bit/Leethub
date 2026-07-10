class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n =words.size();
        int ans =0;
        vector<unordered_map<char,int>> v(words.size());
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                v[i][words[i][j]]++;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                   bool ok = true;

                    for(auto &it : v[i])
                    {
                        if(v[j].find(it.first) != v[j].end())
                        {
                            ok = false;
                            break;
                        }
                    }

                    if(ok)
                    {
                        ans = max(ans, (int)words[i].size() * (int)words[j].size());
                    }
            }
        }
        return ans;
    }
};