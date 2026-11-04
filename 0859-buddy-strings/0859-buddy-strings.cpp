class Solution {
public:
    bool buddyStrings(string s, string goal) {
        unordered_map<int,char>f1;
        unordered_map<int,char>f2;
        unordered_map<char,int>f3;
        unordered_map<char,int>f4;
        int count =0;
        int count2=0;
        int counter=0;
        bool ok = false;
        if(s.size()==goal.size())
        {
            for(int i =0;i<s.size();i++)
            {
                f1[i]=s[i];
                f2[i]=goal[i];
            }
            for(int j =0;j<s.size();j++)
            {
                f3[s[j]]++;
                f4[goal[j]]++;
            }

        }
        for(auto ch: f3)
        {
                if(ch.second ==f4[ch.first])
                    counter++;
        }
        if(counter==f3.size())
            ok =true;
            for(auto ch: f1)
            {
                if(ch.second !=f2[ch.first])
                    count2++;
            }
        if(count2==2 && ok ==true || (s==goal && (f3.size()!=s.size())))
            return true;
        else
            return false;
    }
     
};