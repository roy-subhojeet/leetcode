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
    int count;
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return count;
    }

    void dfs(TreeNode* root, int maxVal)
    {
        if(root == nullptr) return;
        if(root->val >= maxVal) 
        {
            ++count;
        }
        dfs(root->left, max(maxVal, root->val));
        dfs(root->right, max(maxVal, root->val));
    }
};