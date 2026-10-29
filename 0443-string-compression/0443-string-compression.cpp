class Solution {
public:
    int compress(vector<char>& chars) {
        unordered_map<char,int>f;
        vector<string> curr;
        unordered_set<char>ch;
        for(int i =0 ;i<chars.size();i++)
        {
           char curr_char=chars[i];
           int k =1;
           for(int j = i+1;j<chars.size();j++)
           {
                if(chars[j]!=curr_char)
                    break;
                 k++;
           }
           i=i+k-1;

           if(k>1)
           {
           curr.push_back(string(1,curr_char));
           curr.push_back(to_string(k));
           }
           else
                curr.push_back(string(1,curr_char));
        }
        chars.clear();
        for(int i =0;i<curr.size();i++)
        {
            if(curr[i].size()==1)
                chars.push_back(curr[i][0]);
            else
            {
                for(int j =0;j<curr[i].size();j++)
                    chars.push_back(curr[i][j]);
               
            }
        }
        return chars.size();
    }
};