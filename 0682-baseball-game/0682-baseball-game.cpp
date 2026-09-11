class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack <int> st;
        for(auto x :operations)
        {
            if(x=="D")
            {
                int a =st.top();
                st.push(2*a);
            }
            else if(x=="C")
            {
                st.pop();
            }
            else if(x=="+")
            {
               int x= st.top();
               st.pop();
               int y = st.top();
               st.push(x);
               st.push(x+y);
            }
            else
            {
                st.push(stoi(x));
            }
        }
        int sum =0;
        while(!st.empty())
        {
           sum = sum + st.top();
           st.pop();
        }
        return sum;
    }
};