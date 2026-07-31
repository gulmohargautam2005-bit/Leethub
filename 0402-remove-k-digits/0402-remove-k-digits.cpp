class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k==num.size())
            return "0";
       stack <char> st;
       stack <char> st2;
       int count =0;
       string s="";
       st.push(num[0]);
       for(int i =1;i<num.size();i++)
       {
            while(!st.empty() && st.top()>num[i] && count <k)
            {
                st.pop();
                count++;
            }
        
            st.push(num[i]);
            
       }
       while (count < k)
        {
            st.pop();
            count++;
        }
       while(!st.empty())
       {
         st2.push(st.top());
         st.pop();
       }
        while(!st2.empty())
       {
         s.push_back(st2.top());
         st2.pop();
       }
       int i = 0;
        while (i < s.size() && s[i] == '0')
            i++;

        s = s.substr(i);

        if (s.empty())
            s = "0";
       return s;
        
    }
};