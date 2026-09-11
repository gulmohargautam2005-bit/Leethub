class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int> que;
        for(int i =0;i<tickets.size();i++)
        {
            que.push(i);
        }
        int time =0;
        while(!que.empty())
        {
            time++;
            int id = que.front();
            que.pop();
            tickets[id]--;
            if(id ==k && tickets[id]==0)
                return time;
            if(tickets[id]!=0)
                que.push(id);
        }
        return 0;
    }
};