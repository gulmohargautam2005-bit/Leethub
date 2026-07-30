class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <string> st1 ;
        stack <string> st2;
        stack <string> st3;
        int c=0;
        int n = tokens.size();
        if(n==1)
            return stoi(tokens[0]);
        for(int i=0;i<n;i++)
        {
            st1.push(tokens[i]);
        }
        for(int i=0;i<n;i++)
        {
           st2.push(st1.top());
           st1.pop();
        }
        while(!st2.empty())
        {
            while(!st2.empty() && st2.top()!="+" && st2.top()!="/" && st2.top()!="*" && st2.top()!="-" )
            {
                st3.push(st2.top());
                st2.pop();
            }
            if(st3.size()>=2)
            {
                int a = stoi(st3.top());
                st3.pop();
                int b = stoi(st3.top());
                st3.pop();
            
                if(st2.top()=="+")
                {
                    c = a+b;
                st3.push(to_string(c));
                st2.pop();
                
                }
                else if(st2.top()=="-")
                {
                    c = b-a;
                st3.push(to_string(c));
                st2.pop();
                
                }
                else if(st2.top()=="*")
                {
                    c = a*b;
                st3.push(to_string(c));
                st2.pop();
                
                }
                else
                {
                    if(b!=0)
                        c = b/a;
                st3.push(to_string(c));
                st2.pop();
                }
            }


        }

        return c;
    }
};