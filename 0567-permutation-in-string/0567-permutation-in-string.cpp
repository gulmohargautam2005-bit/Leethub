class Solution {
public:
    bool check( unordered_map <char,int> &f, unordered_map <char,int> &f2)
    { 
       for( auto it: f2)
       {
        if(f[it.first]<it.second)
            return false;
       }
       return true;
    }

    
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        int n2= s1.size();
        int low =0;
        int high =0;
        unordered_map <char,int> f;
        unordered_map <char,int> f2;
        for(int i =0;i< n2;i++)
        {
            f2[s1[i]]++;
        }
       for(high =0;high<n;high++)
       {
            f[s2[high]]++;
            if((high-low+1)==n2 )
            {
                if(check(f,f2))
                    return true;
                f[s2[low]]--;
                if(f[s2[low]]==0)
                    f.erase(s2[low]);
                low++;
            }
       }
        return false;
    }
};