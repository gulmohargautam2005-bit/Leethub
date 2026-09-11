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
    bool fun(TreeNode* root,TreeNode* node)
    {
       
        if(root==nullptr)
            return true;
        if(root->val!=node->val)
            return false;
        bool one = fun(root->left,node);
        bool two = fun(root->right,node);
        return one && two;

    }
    bool isUnivalTree(TreeNode* root) {
        return fun(root,root);
    }
};