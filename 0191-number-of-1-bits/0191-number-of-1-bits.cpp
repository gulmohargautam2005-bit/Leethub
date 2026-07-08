class Solution {
public:
    int hammingWeight(int n) {
        int sum=0;
        while(n>=1)
        {
            int d = n%2;
            sum = sum+d;
            n=n/2;
        }
        return sum;
    }
};