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
    void fun(TreeNode* root,vector <int> &val) 
    {
        if(root==nullptr)
            return;
        fun(root->left,val);
        val.push_back(root->val);
        fun(root->right,val);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector <int> v;
        fun(root,v);
        return v[k-1];
    }
};