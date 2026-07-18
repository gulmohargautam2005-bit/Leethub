class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long maxi = LLONG_MIN, maxi2 = LLONG_MIN, maxi3 = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            long long val = nums[i];
            if (val == maxi || val == maxi2 || val == maxi3)
                continue;

            if (val > maxi) {
                maxi3 = maxi2;
                maxi2 = maxi;
                maxi = val;
            } else if (val > maxi2) {
                maxi3 = maxi2;
                maxi2 = val;
            } else if (val > maxi3) {
                maxi3 = val;
            }
        }

        if (maxi3 != LLONG_MIN)
            return (int)maxi3;
        return (int)maxi;
    }
};
