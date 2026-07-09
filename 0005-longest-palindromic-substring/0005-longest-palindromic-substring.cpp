class Solution {
public:
    bool check(string &s,int i,int j)
    { 
        if(i>=j)
            return true;
        if(s[i]==s[j])
            return check(s,i+1,j-1);
    
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int maxlen = INT_MIN;
        int start =0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                
                if(check(s,i,j)==true)
                {
                    if(j-i+1>maxlen)
                    {
                        maxlen = j-i+1;
                        start =i;

                    }
                }
                     
            }
        }
    return s.substr(start,maxlen);
        
    }
};