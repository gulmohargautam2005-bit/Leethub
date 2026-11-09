class Solution {
public:
    int countPalindromicSubsequence(string s) {
            unordered_map<char,int> f;
            
            int res=0;
            for(int i =0;i<s.size();i++)
            {
                f[s[i]]++;
            }
            for(auto ch:f)
            {
                unordered_set<char> set;
                
                if(ch.second >=2)
                {
                    int a = s.find(ch.first);
                    int b = s.rfind(ch.first);
                    int j =a+1;
                    while(j<b)
                    {
                        set.insert(s[j]);
                        j++;
                    }
                    
                }
                res= res+set.size();
                set.clear();
            }
        return res;
        
    }
};