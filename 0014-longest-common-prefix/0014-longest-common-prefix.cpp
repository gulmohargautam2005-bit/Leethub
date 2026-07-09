class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int mini = INT_MAX;
        int idx=0;
        int t=0;
        string res="";
        char c;
        for(int i=0;i<n;i++)
        {
            mini = min(mini,(int)strs[i].size());
            idx=i;
        }
        for(int i=0;i<mini;i++)
        {
            t=0;
            c = strs[idx][i];
           for(int j=0;j<n;j++)
           {
            if( c == strs[j][i] )
               t=t+1;
           }
           if(t==n)
                res=res+c;
            else   
                break;
        }
        return res;
    }
};