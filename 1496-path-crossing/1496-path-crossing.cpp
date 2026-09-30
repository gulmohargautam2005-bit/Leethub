class Solution {
public:
    bool isPathCrossing(string path) {
        int sc =0;
        int sr =0;
        int nr =0;
        int nc=0;
        set<pair<int,int>>f;
        f.insert({0,0});

        for(int i =0;i<path.size();i++)
        {
            char ch = path[i];
            if(ch =='N')
                {
                    nr =nr+1;
                    if(f.find({nr,nc})==f.end())
                        f.insert({nr,nc});
                    else
                        return true;
                }
            else if(ch =='S')
                {
                    nr =nr-1;
                   if(f.find({nr,nc})==f.end())
                        f.insert({nr,nc});
                    else 
                        return true;
                }
            else if(ch =='E')
            {
                nc=nc+1;;
                if(f.find({nr,nc})==f.end())
                        f.insert({nr,nc});
                else
                    return true;
            }
            else
            {
                nc = nc-1;
              if(f.find({nr,nc})==f.end())
                    f.insert({nr,nc});
                else 
                    return true;
            }

        }
        return false;
    }
};