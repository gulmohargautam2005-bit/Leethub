class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i =0;
        int j=0;
        int k=0;
        int num3[n+m];
        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
            {
                num3[k]=nums1[i];
                k++;
                i++;
            }
            else
            {
                num3[k]=nums2[j];
                k++;
                j++;
            }
        }
        while(i<m)
        {
            num3[k]=nums1[i];
            k++;
            i++;
        }
        while(j<n)
        {
            num3[k]=nums2[j];
            k++;
            j++;
        }
        for(int i=0;i<n+m;i++)
        {
            nums1[i]=num3[i];
        }

        
    }
};