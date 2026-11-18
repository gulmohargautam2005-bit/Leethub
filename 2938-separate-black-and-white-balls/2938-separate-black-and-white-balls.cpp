class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        int  j =0;
        long long counter =0;
        long long res=0;
        while(j<n)
        {
          if(s[j]=='1')
            counter=counter+1;
          else if (s[j]=='0')
                res= res+counter*1;
          j++;
        }
  
        return res;
    }
};