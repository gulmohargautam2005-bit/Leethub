class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string s1="";
        string s2="";
        for(int i =0;i<word1.size();i++)
        {
            for(int j =0;j<word1[i].size();j++)
            {
                s1=s1+word1[i][j];
            }
        }
        for(int i =0;i<word2.size();i++)
        {
            for(int j =0;j<word2[i].size();j++)
            {
                s2=s2+word2[i][j];
            }
        }
        if(s1.size()==s2.size())
        {
            for(int i =0;i<s1.size();i++)
            {
                if(s1[i]!=s2[i])
                    return false;
            }
        }
        else
            return false;
        return true;
    
    }
     
};