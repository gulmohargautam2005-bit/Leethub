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
    TreeNode* fun(int preorder_s,int postorder_s,int preorder_e,vector<int>& preorder, vector<int>& postorder)
    {
        if(preorder_s>preorder_e)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[preorder_s]);
        if(preorder_s==preorder_e)
        {
            return root;
        }
        int nextnode= preorder[preorder_s+1];
        int j =postorder_s;
        while(postorder[j]!=nextnode)
        {
            j++;
        }
        int num = j-postorder_s+1;
        
        root->left =fun(preorder_s+1,postorder_s,preorder_s+num,preorder,postorder);
        root->right=fun(preorder_s+num+1,j+1,preorder_e,preorder,postorder);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        int idx =0;
        return fun(0,0,n-1,preorder,postorder);
    }
};