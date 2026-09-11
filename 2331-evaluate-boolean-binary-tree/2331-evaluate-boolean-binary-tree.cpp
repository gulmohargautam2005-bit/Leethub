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
    int  fun(TreeNode* root)
    {
        if(root->left==nullptr && root->right==nullptr)
            return root->val;
         int  a = fun(root->left);
         int b = fun(root->right);
         if(root->val==2)
            return a||b;
         if(root->val==3)
            return a&&b;
        return 0;

    }
    bool evaluateTree(TreeNode* root) {
        int ans = fun(root);
        if(ans==1)
            return true ;
        else 
            return false;
    }
};