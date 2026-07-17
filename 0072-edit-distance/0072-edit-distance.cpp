class Solution {
public:
    int check(string &word1,string &word2,int i,int j,vector<vector<int>>&dp)
    {
        int m = word1.size();
        int n =word2.size();
        if(i==m)
            return n-j;
        if(j==n)
            return m-i;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(word1[i]!=word2[j])
          {
            
            int r1= 1+check(word1,word2,i+1,j+1,dp);
            int r2= 1+check(word1,word2,i+1,j,dp);
            int r3= 1+check(word1,word2,i,j+1,dp);
            return dp[i][j]= min(r1,min(r2,r3));

          }
        return dp[i][j]=check(word1,word2,i+1,j+1,dp);
        
        
    }
    int minDistance(string word1, string word2) {
       int i=0;
       int j=0;
       int count =0;
       int n = word1.size()+word2.size();
       vector<vector<int>> dp(n);
       vector <int> temp(n,-1);
       for(int i=0;i<n;i++)
       {
           dp[i]=temp;
       }
       return check(word1,word2,i,j,dp);
    }
};