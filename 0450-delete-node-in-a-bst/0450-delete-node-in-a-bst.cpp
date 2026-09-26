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
    TreeNode* node = new TreeNode();
    TreeNode* fun(TreeNode* root,int key)
    {
        
        if(root==nullptr)
            return nullptr;
        if(root->val>key)
            root->left=fun(root->left,key);
        if(root->val<key)
            root->right=fun(root->right,key);
        if(root->val==key)
        {
            if(root->left==nullptr&&root->right==nullptr)
                return nullptr;
            if(root->left==nullptr&&root->right!=nullptr)
                return root->right;
            if(root->left!=nullptr&&root->right==nullptr)
                return root->left;
            if(root->left!=nullptr&&root->right!=nullptr)
            {
                TreeNode* temp = root->right;
                while(temp->left!=nullptr)
                {
                    temp = temp->left;
                }
                root->val = temp->val;
                root->right=fun(root->right,temp->val);
            }
        }
        return root;
        
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
            return nullptr;
        return fun(root,key);

    }
};