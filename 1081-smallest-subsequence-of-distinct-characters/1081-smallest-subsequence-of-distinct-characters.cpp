class Solution {
public:
    string smallestSubsequence(string s) {
vector<int> last_index(256, -1);
vector<int> visited(256, 0);
        string res="";
        for(int i =0;i<s.size();i++)
        {
            last_index[s[i]]=i;
        }
        for(int i =0;i<s.size();i++)
        {
            if(visited[s[i]]==1)
                continue;
             
             while(res.size()>0 && s[i]<res.back() && last_index[res.back()]>i)
             {

                visited[res.back()]=0;
                res.pop_back();
             }
             res.push_back(s[i]);
             visited[s[i]]=1;
        }
        return res;
    }
};