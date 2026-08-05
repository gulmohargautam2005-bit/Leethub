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
    void fun(TreeNode* root, int sum,bool &b,vector <int> temp,vector<vector<int>>&res)
     {
        if(root==nullptr)
            return;
        sum= sum*10+root->val;
        
        if(root->left==nullptr && root->right == nullptr)
        {
            temp.push_back(sum);
            res.push_back(temp);
        }
        fun(root->left,sum,b,temp,res);
        fun(root->right,sum,b,temp,res);
     }
    int sumNumbers(TreeNode* root) {
        bool b =false;
        int sum =0;
        vector <int> temp;
        vector<vector<int>> res;
        fun(root,sum,b,temp,res);
        int l =0;
        int i =0;
        while(i<res.size())
        { 
             l +=res[i][0];
             i++;
        }
        return l;
        
    }
};