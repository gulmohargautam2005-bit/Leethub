class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<pair<char,int>,int> f;
        int i=0;
        int j;
        while(i<n)
        {
            j=i;
            char ch = s[i];
            while(j<n && s[j]==ch)
            {
                j++;
            }
            int len = j-i;
            for(int k =1;k<=len;k++)
            {
                f[{ch,k}]+=len-k+1;
            }
            i=j;

        }
        int res =0;
        for(auto it:f)
        {
            char ch = it.first.first;
            int len = it.first.second;
            int freq= it.second;
            if(freq>=3 && len >res)
                res = len;
        }
        if(res!=0)
            return res;
        else 
            return -1;
        
        }
            
        
};