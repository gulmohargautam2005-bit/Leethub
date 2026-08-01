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
        int r1 = 1+fun(root->left);
        int r2= 1+fun(root->right);
        return max(r1,r2);
    }
    int maxDepth(TreeNode* root) {
        return fun(root);
    }
};