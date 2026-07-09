class Solution {
public:
    bool isPalindrome(string s) {
        int n =s.size();
        string result ="";
        for(int i=0;i<n;i++)
        {
            if(isalnum(s[i]))
                 result +=(char)tolower(s[i]); 
        } 
        int low=0;
        string origin =result;
        int t =result.size();
        int high = t-(low+1);    
        while(high>low)
        {
            high = t-(low+1); 
            swap(result[low],result[high]);
            low++;
        }  
        if(origin==result)
            return true;
        else 
            return false;
    }
};