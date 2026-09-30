class Solution {
public:

    void dfs(unordered_map<string, vector<string>> & res,string node,unordered_set<string> & f,string &last)
    {
        f.insert(node);
        if(res[node].size()==0)
            last = node;
        for(int i =0;i<res[node].size();i++)
        {
            string neigh = res[node][i];
            if(f.find(neigh)==f.end())
                dfs(res,neigh,f,last);
            
        }
        
    }
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, vector<string>> res;
        unordered_set<string>f(paths.size()+1);
        string last;
        for(int i=0;i<paths.size();i++)
        {
            string src = paths[i][0];
            string dest = paths[i][1];
            res[src].push_back(dest);
        }
        dfs(res,paths[0][0],f,last);
        return last;
        
    }
};