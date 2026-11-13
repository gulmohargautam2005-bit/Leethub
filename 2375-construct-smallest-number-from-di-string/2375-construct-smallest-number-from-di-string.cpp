class Solution {
public:
   

    bool  fun(int pos, string &pattern,vector<bool> &used,string &path)
    {
        if(path.size()==pattern.size()+1)
            return true;
        for(int i =1;i<=9;i++)
        {
            if(used[i]==true)
                continue;
            if(pos>0)
            {
                int prev = path.back()-'0';
                if(pattern[pos-1]=='I' && i<prev)
                    continue;
                if(pattern[pos-1]=='D' && i>prev)
                    continue;
            }
            used[i]=true;
            path.push_back('0'+i);
            if(fun(pos+1,pattern,used,path))
                return true;
            path.pop_back();
            used[i]=false;
                
        }
        return false;
    }
    string smallestNumber(string pattern) {
        vector<bool> used(10, false);
        string path;

        fun(0,pattern,used,path);
        return path;

    }
};