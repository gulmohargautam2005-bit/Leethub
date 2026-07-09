class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx =-1;
    
        idx =haystack.find(needle);
        if(idx!=-1)
            return idx;
        else 
            return -1;
    }
};