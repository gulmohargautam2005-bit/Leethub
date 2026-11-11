class Solution {
public:
    void fun(int i , int n ,string temp,vector<string> &nums,string &res)
    {

        if( temp.size()==n && find(nums.begin(),nums.end(),temp)==nums.end())
        {
            res= temp;
            return;
        }
        if(i==n)
            return;
        temp+="0";
        fun(i+1,n,temp,nums,res);
        temp.pop_back();
        temp+="1";
        fun(i+1,n,temp,nums,res);
    }
    string findDifferentBinaryString(vector<string>& nums) {
     int n = nums[0].size();
     string temp;
     string res;
     fun(0,n,temp,nums,res);
     return res;
    }
};