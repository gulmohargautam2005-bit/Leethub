class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<string> v(n+1);
        char mini ='z';
        string t;
        for(int i = n-1;i>=0;i--)
        {
            if(s[i]<mini)
            {
                v[i].push_back(s[i]);
                mini = s[i];
            }
            else
            {
               v[i].push_back(mini);
            }
        }
        int j =0;
        string p="";
        while(j<n)
        {
            char ch = s[j];
            if(v[j][0]!=ch)
                t.push_back(ch);
            else
            {
                t.push_back(ch);
                while(!t.empty())
                {
                    if( v[j+1][0]>=t.back()|| j== n-1)
                    {
                    char ch1 = t.back();
                    p.push_back(ch1);
                    t.pop_back();
                    }
                    else
                    {
                        break;
                    }
                }
              
            }
            j++;
        }
        return p;
    }
};