class Solution {
public:
    bool check(string s)
    {
        int high = s.size()-1;
        int low = 0;
        while(high>low)
        {
            if(s[high]!=s[low]) 
                return false;
            high--;
            low++;
        }
        return true;
    }
    void fun(int idx,int n,string s,vector <string> &temp,vector<vector<string>> &res)
    {
        if(idx == n)
        {
            res.push_back(temp);
            return;
        }
        for(int i =idx;i<n;i++)
        {
          
            string choice = s.substr(idx,i-idx+1);
            if(check(choice))
            {
                temp.push_back(choice);
                fun(i+1,n,s,temp,res);
                temp.pop_back();
            }
          
        }

    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> temp;
        fun(0,n,s,temp,res);
        return res;

         
    }
};