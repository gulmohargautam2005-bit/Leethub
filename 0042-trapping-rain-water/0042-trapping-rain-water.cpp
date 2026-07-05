class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int sum =0;
        int leftmax[n];
        int rightmax[n];
        int water[n];
        leftmax[0]=height[0];
        rightmax[n-1]=height[n-1];
        for(int j=1;j<n;j++)
        {
           leftmax[j]=max(leftmax[j-1],height[j]);
        }
        for(int j=n-2;j>=0;j--)
        {
           rightmax[j]=max(rightmax[j+1],height[j]);
        }
      
       
        for(int i =0;i<n;i++)
        {
            water[i]=min(leftmax[i],rightmax[i])-height[i];
        }
        for(int i=0;i<n;i++)
        {
            sum = sum+water[i];
        }
        return sum;
    }
};