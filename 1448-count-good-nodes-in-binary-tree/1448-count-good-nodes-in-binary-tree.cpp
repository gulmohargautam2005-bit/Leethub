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
    int fun(TreeNode* root,int & old)
    {
        int self =0;
        if(root == nullptr)
            return 0;
        if(root->val >= old)
            self =1;
        int newold = max(old,root->val);
        int left = fun(root->left,newold);
        int right = fun(root->right,newold);
        int total = self+left +right;
        return total;
        
    }
    int goodNodes(TreeNode* root) {
        int old =root->val;
        return fun(root,old);
    }
};