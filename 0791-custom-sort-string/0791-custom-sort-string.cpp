class Solution {
public:
    string customSortString(string order, string s) {
        string temp =s;
        string ans="";
        for(int i =0;i<order.size();i++)
        {
            char ch = order[i];
            for(int j =0;j<s.size();j++)
            {
                if(ch==s[j])
                {
                    ans = ans+ch;
                    s.erase(j,1);
                    j=-1;
                }

            }
        }
        ans = ans+s;
        return ans;
        
    }
};