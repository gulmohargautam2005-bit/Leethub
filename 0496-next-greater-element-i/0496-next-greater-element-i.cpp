class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int t=0;
        int d=0;
        vector<int> res;
        for(int i=0 ;i<n1;i++)
        {
            t=0;
            for(int j =0;j<n2;j++)
            {
                
                if(nums2[j]==nums1[i])
                {
                    for(int k =j+1;k<n2;k++)
                    {
                        if(nums2[k]>nums1[i])
                        {
                            d = nums2[k];
                            t =1;
                            break;
                        }
                    }
                }
            } 
            if(t==1)
                res.push_back(d);    
            else
                res.push_back(-1);   
        }
        return res;
    }
};