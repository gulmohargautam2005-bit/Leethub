class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> f;
        priority_queue <int> pq;
        int m= tasks.size();
        int time=0;
         for(auto ch :tasks)
         {
            f[ch-'A']++;
         }
         for(int i=0;i<26;i++)
         {
            if(f[i]>0)
            {
              pq.push(f[i]);
            }
            
         }
          while(!pq.empty())
          {
            int count=0;
            vector <int> temp;
            for(int i =0;i<n+1;i++)
            {
                if(!pq.empty())
                {
                int freq=pq.top();
                pq.pop();
                freq--;
                temp.push_back(freq); 
                 count++; 
                }   
               
            }
            for(int &i:temp)
            {
                if(i>0)
                {
                    pq.push(i);
                }
            }
            if(pq.empty())
                time +=count;
            else
                time +=n+1;

          }
          return time;
    }
};