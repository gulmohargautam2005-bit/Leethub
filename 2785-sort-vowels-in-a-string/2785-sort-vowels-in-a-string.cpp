class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<int> v;
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
        unordered_set<char> mp = {'a', 'e', 'i', 'o', 'u','A','E','I','O','U'};
       for(int i = 0;i<n;i++)
       {
          if(mp.find(s[i])!=mp.end())
          {
            v.push_back(i);
            pq.push({int(s[i]),s[i]});
          }
       }
       string t =s;
       for(int i =0;i<v.size();i++)
       {
        pair<int,char> p = pq.top();
        pq.pop();
         t[v[i]]=p.second;
       }
       return t;

    }
};