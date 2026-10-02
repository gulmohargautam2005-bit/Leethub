class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n = sentences.size();
        int ans = 0;
        int count =0;
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<sentences[i].size();j++)
            {
                if(sentences[i][j]==' ')
                    count = count+1;;
            }
            if(count>=ans)
                ans=count;
            count =0;
        }
        return ans+1;
    }
};