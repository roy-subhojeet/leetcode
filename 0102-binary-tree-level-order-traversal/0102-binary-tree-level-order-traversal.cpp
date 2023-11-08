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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            auto sz = q.size();
            vector<int> res;
            while(sz--)
            {
                auto elem = q.front();
                res.push_back(elem->val);
                q.pop();
                if(elem->left != nullptr) q.push(elem->left);
                if(elem->right != nullptr) q.push(elem->right);
            }
            if(!res.empty())ans.push_back(res);

        }
        return ans;
    }
    /* This is Wrong Post Order Traversal != Level Order Traversal
    int dfs(TreeNode* root)
    {
        if(root == nullptr) return 1001;
        auto l = dfs(root->left);
        auto r = dfs(root->right);
        vector<int> res;
        if(l != 1001) res.push_back(l);
        if(r != 1001) res.push_back(r);
        if(l== 1001 && r == 1001) {}
        else ans.push_back(res);
        return root->val;
    }
    */
};