class Solution {
public:
void fillfun(queue<string> &que,string s,unordered_set<string> &mp)
{
    for(int i =0;i<4;i++)
    {
        char ch = s[i];
        char inc = ch=='9'? '0':ch +1;
        char dec = ch =='0'? '9':ch -1;
        s[i]=inc;
        if(mp.find(s)== mp.end())
        {
            que.push(s);
            mp.insert(s);
        }
        s[i]=dec;
        if(mp.find(s)==mp.end())
        {
            que.push(s);
            mp.insert(s);
        }
        s[i]=ch;
    }
}
    int openLock(vector<string>& deadends, string target) {
        queue<string> que;
        unordered_set <string> mp(begin(deadends),end(deadends));
        string start ="0000";
        que.push(start);
        if(mp.find(start)!=mp.end())
            return -1;
        int lvl =0;
        while(!que.empty())
        {
            int  n = que.size();
            while(n--)
            {
                string s = que.front();
                que.pop();
                if(s==target)
                    return lvl;
                fillfun(que,s,mp);
            }
            lvl = lvl +1;;
        }
        return -1;
    }
};