class Solution {
public:
    void fun(string &s , int pos, vector<string> &ans)
    {
        if(pos==s.size())
        {
            ans.push_back(s);
            return;
        }
        if(isdigit(s[pos]))
            fun(s,pos+1,ans);
        else
        {
        s[pos]=tolower(s[pos]);
        fun(s,pos+1,ans);
        s[pos]=toupper(s[pos]);
        fun(s,pos+1,ans);
        }
  
    }
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        fun(s,0,ans);
        return ans;
    }
};