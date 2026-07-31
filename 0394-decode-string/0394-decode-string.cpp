class Solution {
public:
    string decodeString(string s) {
       int n =s.size();
       stack <int> st1;
       stack <char> st2;
       string x = "";
       string res= "";
       string t="";
       for(int i =0;i<n;i++)
       {
            if((int)s[i]>=97 && (int)s[i] <=122 ||(int)s[i]==91)
            {
                st2.push(s[i]);
            }
            else if((int)s[i]==93)
            {
                x="";
                while(st2.top()!='[')
                {
                    x = st2.top()+x;
                    st2.pop();
                }
                st2.pop();
                int k = st1.top();
                string temp = x;
                x= "";
                for(int i =0;i<k;i++)
                {
                  x=x+temp;
                }
                st1.pop();
                if(!st2.empty())
                {
                    for(int i =0;i<x.size();i++)
                    {
                        st2.push(x[i]);
                    }
                }
                else
                {
                    res += x;
                }
            }
            else if (isdigit(s[i]))
                {
                    int num = 0;

                    while (i < n && isdigit(s[i]))
                    {
                        num = num * 10 + (s[i] - '0');
                        i++;
                    }

                    st1.push(num);
                    i--;
                }
       }
    while(!st2.empty())
    {
        t = st2.top()+t;
        st2.pop();
    }
    res = res+t;
    return res;
    }
};