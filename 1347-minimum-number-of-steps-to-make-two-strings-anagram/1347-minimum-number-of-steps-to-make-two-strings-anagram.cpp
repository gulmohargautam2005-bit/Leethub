class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> f1;
        unordered_map<char,int> f2;
        int count =0;
        for(int i =0;i<t.size();i++)
        {
            f1[s[i]]++;
            f2[t[i]]++;
        }
        for( auto ch:f2)
        {
            while(ch.second>0)
            {
                if(f1.find(ch.first)!=f1.end())
                {
                        
                        if(f1[ch.first]==0)
                            count++;
                        else
                            f1[ch.first]--;
                }
                    else
                        count++;
                ch.second--;
            }
        }
        return count;
    }
};