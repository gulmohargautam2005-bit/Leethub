class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> v1;
        vector<string> v2;
        string line;
        stringstream ss(sentence1);

        while(ss>>line)
        {
            v1.push_back(line);
        }
        stringstream ss2(sentence2);
        while(ss2>>line)
        {
            v2.push_back(line);
        }
        int i =0;
        int j = 0;

        if(v1.size() < v2.size())
            swap(v1, v2);
        while(i<v2.size() && v2[i]==v1[i])
        {
                i++;
        }
        while(j<v2.size()-i && v2[v2.size()-1-j]==v1[v1.size()-1-j])
        {
                j++;
        }
        
        
        return i+j ==v2.size();




    }
};