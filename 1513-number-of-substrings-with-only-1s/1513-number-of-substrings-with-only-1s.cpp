class Solution {
public:
    int numSub(string s) {
    vector<string> v;
    const int MOD = 1e9 + 7;
    
    for(int i=0;i<s.size();i++)
        {
            int k =0;
            int count =0;
              if(s[i]=='1')
                {
                    k=i;
                    while( i<=s.size()-1 && s[i]!='0')
                    {
                        count++;
                        i++;
                    }
                }
            v.push_back(s.substr(k,count));

            
        }
        long long result =0;
        for(int  i =0;i<v.size();i++)
        {
            long long counter =0;
            for(int j =1;j<=v[i].size();j++)
            {
            counter = counter +j;
            }
            result =(counter + result)%MOD;
        }
        return result;
    }
};