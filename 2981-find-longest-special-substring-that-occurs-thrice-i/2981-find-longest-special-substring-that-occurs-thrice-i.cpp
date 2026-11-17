class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
      map<pair<char,int>,int> f;
      for(int i =0;i< n;i++)
      {
         char ch = s[i];
         int l= 0;
         for(int j =i;j<n;j++)
         {
            if(s[j]==ch)
            {
                l++;
                f[{ch,l}]++;
            }
            else 
            {
                break;
            }
         }
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