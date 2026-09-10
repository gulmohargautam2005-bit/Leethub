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
    void fun(TreeNode* root,int & sum,bool check)
    {
        if(root==nullptr)
            return;
        if(root->left == nullptr && root->right==nullptr && check==true)
        {
            sum = sum+root->val;
        }
        fun(root->left,sum,check = true);
        fun(root->right,sum,check = false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        bool check = false;
        int sum =0;
        fun(root,sum,check);
        return sum;
        
    }
};