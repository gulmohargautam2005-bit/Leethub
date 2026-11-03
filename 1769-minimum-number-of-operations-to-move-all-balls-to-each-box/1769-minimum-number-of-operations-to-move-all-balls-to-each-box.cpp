class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int>v;
        int answer =0;
        for(int  i =0;i<boxes.size();i++)
        {
            int answer =0;
            for(int j = 0;j<boxes.size();j++)
            {
                if(boxes[j]=='1' && j!=i)
                    answer=answer+abs(j-i);
            }
            v.push_back(answer);
        }
        return v;
    }
};