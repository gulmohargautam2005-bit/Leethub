class Solution {
public:
    int candy(vector<int>& ratings) {
        int count = 0;
        int n = ratings.size();
        unordered_map <int,int> mp;
        for(int i =0;i<ratings.size();i++)
        {
            mp[i]++;
        }
        for(int i =1;i<ratings.size();i++)
        {
            if(ratings[i]>ratings[i-1])
            {
                mp[i]=mp[i]+mp[i-1];     
             }
        }
        for( int i =n-2;i>=0;i--)
        {
            if(ratings[i+1]<ratings[i])
            {
                mp[i]=max(mp[i+1]+1,mp[i]);
            }
        }
        for(int i =0;i<ratings.size();i++)
        {
            count = count +mp[i];
        }
        return count;
    }
};