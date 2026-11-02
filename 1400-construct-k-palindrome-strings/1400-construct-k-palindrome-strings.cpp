class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int> f;
        int count=0;
        int count2=0;
        for(int i =0;i<s.size();i++)
        {
            f[s[i]]++;
        } 
        for(auto ch:f)
        {
            if(ch.second%2!=0)
                count = count+1;
        }
        return count<=k && k<=s.size();
            
    }
};