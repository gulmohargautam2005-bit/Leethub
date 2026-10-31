class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_set<char> f;
        int last_index[26]={};
        int visited[26]={0};
        string res="";
        for(int i =0;i<s.size();i++)
        {
          char ch = s[i];
          last_index[ch-'a']=i;
        }

        for(int i =0;i<s.size();i++)
        {
            char ch = s[i];
            if(visited[ch-'a']==1)
                continue;
            while(res.size()>0 && res.back()>ch && last_index[res.back()-'a']>i )
            {
               
                visited[res.back()-'a']=0;
                 res.pop_back();
            }
            res.push_back(ch);
            visited[ch-'a']=1;

        }
        return res;
    }
};