class Solution {
public:
    string decodeAtIndex(string s, int k) {
        string temp="";
        long long len=0;
        for(int i =0;i<s.size();i++)
        {
           if(isalpha(s[i]))
                len = len+1;
            else
            {
                len = len*(s[i]-'0');
            }
        }
        for(int i =s.size()-1;i>=0;i--)
        {
            k=k%len;
            if(k==0 && isalpha(s[i]))
                return string(1,s[i]);
            else if(isdigit(s[i]))
            {
                len = len/(s[i]-'0');
            }
            else
            {
                len--;
            }
        }
        return "0";
    }
};