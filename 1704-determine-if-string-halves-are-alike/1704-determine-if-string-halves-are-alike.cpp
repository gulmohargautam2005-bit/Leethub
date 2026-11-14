class Solution {
public:
    bool halvesAreAlike(string s) {
         int count1 = 0, count2 = 0;

        string vowels = "aeiouAEIOU";
        int n = s.size();

        for(int i = 0; i < n/2; i++)
        {
            if(vowels.find(s[i]) != string::npos)
                count1++;
        }

        for(int i = n/2; i < n; i++)
        {
            if(vowels.find(s[i]) != string::npos)
                count2++;
        }

        return count1 == count2;
    }
};