class Solution {
public:
    void dfs(int node ,vector<vector<int>> &rooms,vector<bool> & visited)
    {
        visited[node]=true;
        for(int i =0;i<rooms[node].size();i++)
        {
            int neigh = rooms[node][i];
            if(visited[neigh]==false)
            {
                dfs(neigh,rooms,visited);
            }
        }
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        dfs(0,rooms,visited);
        for(int i =0;i<rooms.size();i++)
        {
            if(visited[i]==false)
            {
                return false;
            }
        }
        return true;
    }
};