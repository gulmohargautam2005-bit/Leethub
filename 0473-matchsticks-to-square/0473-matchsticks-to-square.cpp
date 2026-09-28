class Solution {
public:

int count =0;
   bool back(int node ,vector<int>& matchsticks,int a,vector<bool> &visited,int sum,int count)
   {
        if (count == 4)
            return true;
        if(node == matchsticks.size())
            return false;
        if(visited[node]==true)
            return back(node + 1, matchsticks,a,visited, sum, count);
        visited[node]=true;


        if (sum + matchsticks[node] <= a)
        {
            visited[node] = true;

            if (sum + matchsticks[node] == a)
            {
                if (back(0, matchsticks,a,
                         visited, 0, count + 1))
                    return true;
            }
            else
            {
                if (back(node + 1, matchsticks, a,
                         visited, sum + matchsticks[node], count))
                    return true;
            }
        }

        visited[node]=false;
        return back(node + 1, matchsticks, a,
                    visited, sum, count);
    }
    
    

   int fun(int i,vector<int> matchsticks)
   {
        if(i == matchsticks.size())
            return 0;
        return matchsticks[i]+fun(i+1,matchsticks);
   }
    bool makesquare(vector<int>& matchsticks) {
        int p = fun(0,matchsticks);
        int sum =0;
        int count=0;
        vector<bool> visited(matchsticks.size()+1,false);
        if(p%4!=0)
            return false;
        int a = p/4;
        return back(0,matchsticks,a,visited,0,count);

    }
};