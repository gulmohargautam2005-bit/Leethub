class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double>ans;
        vector<vector<int>> res;
        q.push(root);
        while(!q.empty())
        {
            int lvlsize=q.size();
            vector<int> temp;
            while(lvlsize--)
            {
             TreeNode* t = q.front();
             q.pop();
             temp.push_back(t->val);
            if(t->left!=nullptr)
                q.push(t->left);
            if(t->right!=nullptr)
                q.push(t->right);
            }
            res.push_back(temp);
        }
        for(int i =0;i<res.size();i++)
         {
             double x=0.0;
             double divisor=0.0;
            for(int j =0;j<res[i].size();j++)
            {
               x= x+res[i][j];
               divisor =res[i].size();
            }
            ans.push_back(x/divisor);

         }
         return ans;
         
    }
};