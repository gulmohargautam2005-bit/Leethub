class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> res(n,1e8);
        vector <int> temp =res;
        res[src] = 0;
        for(int j=0;j<k+1;j++)
        {
           temp = res;
            for(int i=0;i<flights.size();i++)
            {
                int s =flights[i][0];
                int d =flights[i][1];
                int weight=flights[i][2];
            
                if(res[s]!=1e8 && temp[d]>weight+res[s])
                {
                    temp[d]=weight+res[s];
                }
            }
            res=temp;
           

        }
        if(res[dst]==1e8)
            return -1;
        else
            return res[dst];
       
 

    }
};