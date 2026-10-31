class Solution {
public:
 string fun(string s,int i )
 {
    if(s.size()<=1 || i>=s.size()-1)
        return s;
    if(s[i]!=s[i+1] && toupper(s[i])==s[i+1])
    {
        s.erase(i,2);
        return fun(s,0);
    }
    else if(s[i]!=s[i+1] && tolower(s[i])==s[i+1])
    {
        s.erase(i,2);
        return fun(s,0);

    }
    else
    {
       return  fun(s,i+1);
    }
    return s;
}

    string makeGood(string s) {
     return  fun(s,0);
    }
};