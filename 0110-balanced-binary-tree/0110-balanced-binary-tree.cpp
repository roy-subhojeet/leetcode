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
    bool isBal = true;
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return isBal;
    }
    int dfs(TreeNode* root)
    {
        if(root == nullptr) return 0;
        int leftD = dfs(root->left);
        int rightD = dfs(root->right);
        if(abs(leftD - rightD) > 1) isBal = false;
        return 1 + max(leftD, rightD);
    }
};