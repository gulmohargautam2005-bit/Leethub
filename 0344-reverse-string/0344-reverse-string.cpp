class Solution {
public:
    void reverseString(vector<char>& s) {
        int  n = s.size();
         int high =0;
         int low =n-(high+1);
         while(low>high)
         {
             low =n-(high+1);
            swap(s[high],s[low]);
            high++;
         }
        
    }
};