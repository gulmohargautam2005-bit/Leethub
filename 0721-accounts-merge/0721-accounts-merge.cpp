class Solution {
public:
    void dfs(unordered_map<string,vector<string>> &graph,unordered_set<string> &visited,string email,vector<string> &emails)
    {
        visited.insert(email);
        emails.push_back(email);
        for(string neigh:graph[email])
        {
            if(visited.find(neigh)==visited.end())
            {
                dfs(graph,visited,neigh,emails);
            }
        }
        
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,vector<string>> graph;
        unordered_set<string> visited;
        vector<string> emails;
        unordered_map<string,string> link;

        vector<vector<string>> ans;
        vector<string>  account;
        int n = accounts.size();
        for(int i =0;i<n;i++)
        {
            string name = accounts[i][0];
            string first = accounts[i][1];
            link[first]=name;
            for(int j =2;j<accounts[i].size();j++)
            {
                
              string email=accounts[i][j];
              link[email] = name;
              graph[first].push_back(email);
              graph[email].push_back(first);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visited.find(accounts[i][1])==visited.end())
            {
                dfs(graph,visited, accounts[i][1],emails);
                sort(emails.begin(), emails.end());
                account.push_back(link[emails[0]]);

                for(int j = 0; j < emails.size(); j++)
                {
                    account.push_back(emails[j]);
                }

                ans.push_back(account);
                emails.clear();
                account.clear();
            }
        }
        return ans;
      
    }
};