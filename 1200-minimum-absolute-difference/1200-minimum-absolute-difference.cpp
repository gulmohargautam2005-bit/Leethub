class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> res;
        vector<int> temp;
        int ans = INT_MAX;
        int a = arr[0];
        int b = arr[1];
        int diff =abs(a-b);
        ans = min(ans,diff);
                        temp.push_back(a);
                temp.push_back(b);
                res.push_back(temp);
                temp.clear();
        for(int i =1;i<arr.size()-1;i++)
        {
             a = arr[i];
            b = arr[i+1];
            diff =abs(a-b);
            if(diff==ans)
            {
                temp.push_back(a);
                temp.push_back(b);
                res.push_back(temp);
                temp.clear();
            }
            else if(diff<ans)
            {
                            ans = min(ans,diff);
                res.clear();
                temp.push_back(a);
                temp.push_back(b);
                res.push_back(temp);
                temp.clear();
            }
            else
            {
                continue;
            }
        }
        return res;
        
    }
};