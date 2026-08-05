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
    bool fun(TreeNode* root,long long minval,long long maxval)
    {
        if(root==nullptr)
            return true ;
        if(root->val>=maxval || root->val<=minval)
        {
            return false;
        }
        bool r1 = fun(root->left,minval,root->val);
        bool r2 = fun(root->right,root->val,maxval);
        return (r1&r2);
    }
    bool isValidBST(TreeNode* root) {
        return fun(root,LLONG_MIN,LLONG_MAX);
    }
};