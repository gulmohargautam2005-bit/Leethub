class Solution {
public:
    int appendCharacters(string s, string t) {
        int i =0;
        int j =0;
        int counter =0;
        while(j < t.size() && i < s.size())
        {
            
                if(s[i]==t[j])
                {
                    counter = counter+1;
                    j++;
                }
                i++;
            
        }
        return t.size()-counter;
    }
};