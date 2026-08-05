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
     void fun(TreeNode* root,int &t, int sum,bool &b)
     {
        if(root==nullptr)
            return;
        sum= sum+root->val;
        if(root->left==nullptr && root->right == nullptr)
        {
            if(sum==t)
            {
                b=true;
            }
        }
        fun(root->left,t,sum,b);
        fun(root->right,t,sum,b);
     }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool b =false;
        int sum =0;
        fun(root,targetSum,sum,b);
        return b;

    }
};