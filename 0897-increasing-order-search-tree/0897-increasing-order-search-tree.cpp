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
    TreeNode* head=nullptr;
    TreeNode* prev=nullptr;
    void fun(TreeNode* root)
    {
        
        if(root==nullptr)
            return;

        fun(root->left);
        if(head == nullptr)
            head = root;
        if(prev!=nullptr)
            {
                prev->right=root;
                prev->left =nullptr;
            }
        prev =root;
        fun(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        fun(root);
        prev->left = nullptr;
        prev->right = nullptr;
        return head;
    }
};