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
    
    TreeNode* fun(TreeNode* root1,TreeNode* root2)
    {
        TreeNode* root3=new TreeNode();
        if(root1==nullptr and root2==nullptr)
            return nullptr;
        if(root1!=nullptr)
        {
            root3->val = root3->val+root1->val;
        }
        if(root2!=nullptr)
        {
            root3->val = root3->val+root2->val;
        }
        root3->left= fun(root1?root1->left:nullptr,root2?root2->left:nullptr);
        root3->right= fun(root1?root1->right:nullptr,root2?root2->right:nullptr);
        return root3;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return fun(root1,root2);
    }
};