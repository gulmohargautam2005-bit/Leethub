class Solution {
public:
    vector<string> gettokens(string value)
    {
        stringstream ss(value);
        vector<string>tokens;
        string token="";
        while(getline(ss,token,'.'))
        {
            tokens.push_back(token);
        }
        return tokens;
    }
    int compareVersion(string version1, string version2) {
      vector<string> a = gettokens(version1);
      vector<string> b = gettokens(version2);
      int n = a.size();
      int m = b.size();
      int i =0;
      int j =0;
      while(n>i || m>j)
      {
            int c=0;
            int d=0;
            if(i==n)
                c=0;
            else
                c= stoi(a[i]);
            if(j==m)
                d=0;
            else
                d= stoi(b[j]);

                if(c>d)
                {
                    return 1;
                }
                else if(d>c)
                {
                    return -1;
                }
            if(i<n && j <m)
            {
            i++;
            j++;
            }
            else if(i ==n && j<m)
            {
                j++;
            }
            else
            {
                i++;
            }

        }
      return 0;
    }
};