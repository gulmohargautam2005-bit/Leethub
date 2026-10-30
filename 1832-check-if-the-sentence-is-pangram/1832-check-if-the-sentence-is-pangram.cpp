class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> f;
        for(int i =0;i<sentence.size();i++)
        {
           f.insert(sentence[i]);
        }
        if(f.size()==26)
            return true;
        else 
            return false;
    }
};