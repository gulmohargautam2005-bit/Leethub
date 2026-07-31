class Solution {
public:

    int calculate(string s) {
        stack <int> st;
        int n = s.size();
        long long number =0;
        long long result =0;
        long long sign =1;
        for(int i =0;i<n;i++)
        {
            if (s[i] == ' ')
                continue;
            if(isdigit(s[i]))
            {
                number = number*10+(s[i]-'0');
            }
            else if(s[i]=='+')
            {
                result =result +(number*sign);
                sign=1;
                number=0;
            }
            else if(s[i]=='-')
            {
                result =result +(number*sign);
                sign=-1;
                number=0;
    
            }
            else if(s[i]=='(')
            {
                st.push(result);
                st.push(sign);
                 result =0;
                 sign =1;
                 number =0;
    
            }
            else if(s[i]==')')
            {
                result = result+(number*sign);
                number=0;
                int last_sign = st.top();
                st.pop();
                int last_res= st.top();
                st.pop();
                result = result*last_sign;
                result = result+last_res;
            }
        }
        result = result +(number*sign);
        return result;

    }
};