class Solution {
public:
    int heightChecker(vector<int>& heights) {
        std::vector<int> count(101, 0);
        for (int h : heights) {
            count[h]++;
        }

        int mismatches = 0;
        int currentHeight = 1;

        for (int h : heights) {
            // Find the next height that still has students waiting
            while (count[currentHeight] == 0) {
                currentHeight++;
            }

            if (h != currentHeight) {
                mismatches++;
            }

            count[currentHeight]--;
        }

        return mismatches;
        
    }
};