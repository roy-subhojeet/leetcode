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
    int maxDepth(TreeNode* root) {
        return calculateMaxDepth(root, 0);
    }
    int calculateMaxDepth(TreeNode* const& root, int count)
    {
        if(root == nullptr) return count;
        int leftC = calculateMaxDepth(root->left, count+1);
        int rightC = calculateMaxDepth(root->right, count+1);
        return max(leftC, rightC);
    }
};