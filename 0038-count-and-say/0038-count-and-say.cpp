class Solution {
public:
    string fun(int n)
    {
        string ans="";
        if(n==1)
            return to_string(1);
        string curr =fun(n-1);
        for(int i =0;i<curr.size();i++)
            {
            int ch = curr[i]-'0';
            int k =i+1;
            while(k<curr.size() && curr[k]-'0'==ch)
                k++;
            if(k==i+1)
            {
            ans = ans+to_string(1);
            ans= ans+to_string(curr[i]-'0');
            }
            else
            {
            ans = ans+to_string(k-i);
            ans= ans+to_string(curr[i]-'0');
            i=k-1;

            }
        }
        return ans;
    }
    string countAndSay(int n) {
        return fun(n);
    }
};