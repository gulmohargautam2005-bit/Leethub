class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.size();
        unordered_map<char,string> f1;
        unordered_map<string,char> f2;
        string temp ="";
        vector <string > word;
        for(int i=0;i<n;i++)
        {
            if(s[i]== ' ')
            {
                word.push_back(temp);
                temp="";
            }
            else
            {
                temp+=s[i];
            }
        }
        word.push_back(temp);
        if(word.size()!=pattern.size())
            return false;
        for(int i=0;i< pattern.size();i++)
        {
            if (f1.find(pattern[i]) != f1.end())
            {
                if (f1[pattern[i]] != word[i])
                    return false;
            }
            else
            {
              f1[pattern[i]]=word[i];
            }
            
        }
        for(int i=0;i< pattern.size();i++)
        {
            if (f2.find(word[i]) != f2.end())
            {
                if (f2[word[i]] != pattern[i])
                    return false;
            }
            else
            {
              f2[word[i]]=pattern[i];
            }
            
        }
        for(int i=0;i< pattern.size();i++)
        {
        
            if(f2[f1[pattern[i]]]!=f2[word[i]])
                return false;
        }
        return true;
    }
};