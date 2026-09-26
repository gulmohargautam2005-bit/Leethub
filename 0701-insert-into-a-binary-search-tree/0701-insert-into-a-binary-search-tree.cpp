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
    void fun(TreeNode* &root, int val)
    {
        if(root==nullptr)
        {   
            TreeNode* node = new TreeNode();
            node->val =val;
             root=node;
            return;
        }
        if(root->left == nullptr && root->right==nullptr)
        {
           if(root->val>val)
           {
                TreeNode* node = new TreeNode();
                node->val=val;
                root->left = node;
                return;
           }
            else
            {
                TreeNode* node = new TreeNode();
                node->val=val;
                root->right = node;
                return ;
            }
        }
        if(root->val>val)
            fun(root->left,val);
        if(root->val<val)
            fun(root->right,val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        fun(root,val);
        return root;
    }
};