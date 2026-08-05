/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void fun(TreeNode* root,int &t, int sum,bool &b,vector <int> temp,vector<vector<int>>&res)
     {
        if(root==nullptr)
            return;
        sum= sum+root->val;
        temp.push_back(root->val);
        if(root->left==nullptr && root->right == nullptr)
        {
            if(sum==t)
            {
                b=true;
                res.push_back(temp);
            
            }
        }
        fun(root->left,t,sum,b,temp,res);
        fun(root->right,t,sum,b,temp,res);
     }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        bool b =false;
        int sum =0;
        vector <int> temp;
        vector<vector<int>> res;
        fun(root,targetSum,sum,b,temp,res);
        return res;
        
    }
};