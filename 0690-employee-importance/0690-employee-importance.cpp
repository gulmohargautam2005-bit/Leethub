class Solution {
public:
    int pos[2001];
    int dfs(vector<Employee*>& employees, int node) {
        int total = employees[node]->importance;
        for (int i = 0; i < employees[node]->subordinates.size(); i++)
            total += dfs(employees, pos[employees[node]->subordinates[i]]);
        return total;
    }
    int getImportance(vector<Employee*> employees, int id) {
        for (int i = 0; i < employees.size(); i++)
            pos[employees[i]->id] = i;
        return dfs(employees, pos[id]);
    }
};