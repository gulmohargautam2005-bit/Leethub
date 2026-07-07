class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();
        string ch1="";
        string ch2="";
        for(int i =0;i<n;i++)
        {
     
            if(s[i]!='#')
            {
                
                ch1=ch1+s[i];
            }
            else
            {
                if(!ch1.empty())
                {
                    ch1.pop_back();
                }
            }
        }
        for(int i =0;i<m;i++)
        {
            if(t[i]!='#')
            {
                
                ch2=ch2+t[i];
            }
            else
            {
                  
                if(!ch2.empty())
                {
                    ch2.pop_back();
                }
            }
        }
        if(ch1==ch2)
        {
            return true;
        }
        else{
            return false;
        }
    }
};