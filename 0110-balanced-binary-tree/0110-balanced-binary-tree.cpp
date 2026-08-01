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
    int fun(TreeNode* root)
    {
        if(root==nullptr)
            return 0;
        int r1=fun(root->left);
        int r2 = fun(root->right);
        return 1+max(r1,r2);
 
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)
            return true;
        int r1 = fun(root->left);
        int r2 = fun(root->right);
       return abs(r1-r2) <= 1 &&
       isBalanced(root->left) &&
       isBalanced(root->right);
    }
};