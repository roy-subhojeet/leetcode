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
private:
    string ans;
public:
    string tree2str(TreeNode* root) {
        ans += to_string(root->val);
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root)
    {
        if(!root) return;
        if(!root->left && root->right) ans += "()";
        if(root->left)
        {
            ans += "(" + to_string(root->left->val);
            dfs(root->left);
            ans += ")";
        }
        if(root->right)
        {
            ans += "(" + to_string(root->right->val);
            dfs(root->right);
            ans += ")";
        }
    }
};