class Solution {
public:
    bool check(string &s,int low,int high)
    {
        while(high>low)
        {
            if(s[high]!=s[low])
                return false;
            low++;
            high--;
        }
        return true;
    }
    bool validPalindrome(string s) {
            int n = s.size();
            int count =0;
            int low =0;
            int high =n-1;
            while(high>low)
            {
                if(s[high]==s[low])
                {
                    low++;
                    high--;
                }
                else 
                 {
                    return check(s,low+1,high)||check(s,low,high-1);
                 }
            }
            return true;
        
    }
};