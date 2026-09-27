class Solution {
public:
int ans=0;
    void fun(int n,int pos, vector <bool> & used)
    {
        if(pos>n)
        {
            ans++;
            return;
        }
        for(int num = 1;num<=n;num++)
        {
            if(used[num]==false)
                {
                    if(num % pos == 0 || pos % num == 0)
                    {
                    used[num]=true;
                    fun(n,pos+1,used);
                    used[num]=false;
                    }
                }
        }

    }
    int countArrangement(int n) {
        vector<bool> used(n+1,false);
        fun(n,1,used);
        return ans;
    }
};