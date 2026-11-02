class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> f1;
        unordered_map<char,int> f2;
        int count =0;
        int count3=0;
        int count2=0;
        if(word1.size()!=word2.size())
            return false;
        for(int i =0;i<word1.size();i++)
        {
            f1[word1[i]]++;
        }
        for(int i =0;i<word2.size();i++)
        {
            f2[word2[i]]++;
        }
        bool ok = false;
        for(auto ch:f1)
            {
                if(f2.find(ch.first)!=f2.end())
                    count++;
            }
        if(count == f1.size())
            ok =true;
        else
        {
            return false;
        }
        vector<int> a;
        vector<int> b;
        if(ok)
        {
            for(auto ch1:f1)
                a.push_back(ch1.second);
            for(auto ch2:f2)
                b.push_back(ch2.second);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int c=0;
        for(int i =0;i<a.size();i++)
        {
            if(a[i]==b[i])
                c++;
        }
        if(c==a.size())
            return true;
        else 
            return false;
       
    }
};
