class Solution {
public:
    int findLucky(vector<int>& arr) {
        int maxi =-1;
        unordered_map<int,int> f;
        for(int i =0;i< arr.size();i++)
        {
            f[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++)
        {
            if(f[arr[i]]==arr[i])
            {
                if(arr[i]>maxi)
                {
                    maxi = arr[i];
                }
            }
        }
        return maxi;
    }
};