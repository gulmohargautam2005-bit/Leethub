class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int m = nums1.size();
       int n = nums2.size();
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
       
        if((n+m)%2==1)
        {
            double x =num3[((n+m+1)/2)-1];
            return x;
        }
        else
        {
            double x = ( num3[((n+m)/2)-1]+num3[(((n+m)/2)+1)-1] )/2.0;
            return x;
        }
        return -1;
    }

};