class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_map<string, int> indeg;
        unordered_map<string, int> outdeg;
        for(int i =0;i<n;i++)
        {
            string src = paths[i][0];
            string dest = paths[i][1];
             indeg[dest]++;
             outdeg[src]++;
        }
        for(int i =0;i<n;i++)
        {
            string dest = paths[i][1];
            if(outdeg[dest]==0)
                return dest;
        }
        return "1";
    }
};