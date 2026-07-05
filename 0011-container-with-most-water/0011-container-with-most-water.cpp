class Solution {
public:
    int maxArea(vector<int>& height) {
       int i=0;
       int n = height.size();
       int j=n-1;
       int maxdepth=0;
       int maxi=0;
       while(i<=j)
       {
            int width = j-i;
            int h = min(height[i],height[j]);
            maxi =max(maxi,width*h);
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }

       }
           return maxi;
    }
};