class Solution {
public:
    int countHomogenous(string s) {
        int result =0;
        int MOD =1e9+7;
        for(int i =0;i<s.size();i++)
        {
            char ch = s[i];
            int j = i+1;
            int count=1;
            while(s[j]==ch)
            {
                count++;
                j++;
            }
            for(int k =1;k<=count;k++)
            {
                result = (result+k)%MOD;
            }
            i=i+count-1;
        }
        return result;
    }
};