class Solution {
public:
    bool find(vector<string>& wordDict,string temp)
    {
        for(int k =0;k<wordDict.size();k++)
        {
            if(temp==wordDict[k])
                return true ;
        }
       return false;
    }
    bool fun(int i , int n,string s,vector<string>& wordDict, vector<int> &dp)
    {
        if(i==n)
            return dp[i]= true;
        if(dp[i]!=-1)
            return dp[i];
        for(int j=i;j<n;j++)
        {
            string temp = s.substr(i,j-i+1);
            if(find(wordDict,temp) && fun(j+1,n,s,wordDict,dp))
                return dp[i]=true;
        }
        return dp[i]= false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        bool x;
        return fun(0,n,s,wordDict,dp);
        
    }
};