/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
   void  fun(TreeNode* root,TreeNode* p,TreeNode* q,TreeNode* &a) 
   {
        if(root==nullptr)
            return;
        if(root->val>p->val && root->val>q->val)
        {
            fun(root->left,p,q,a);
        }
        else if(root->val<p->val && root->val<q->val)
        {
            fun(root->right,p,q,a);
        }
        else
        {
            a=root;
        }
   }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* a = nullptr;
        fun(root,p,q,a);
        return a;
        
    }
};