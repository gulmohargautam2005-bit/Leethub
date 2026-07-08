class Solution {
public:
    int romanToInt(string s) {
         unordered_map<char,int> f = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        int sum =0;
        int n =s.size();
        for(int i =0;i<n;i++)
        {
            if(i+1<(n) && f[s[i]]<f[s[i+1]])
            {
                sum=sum -f[s[i]];
            }
            else
            {
                 sum=sum +f[s[i]];
            }
         
        }
      
        return sum;
    }
};