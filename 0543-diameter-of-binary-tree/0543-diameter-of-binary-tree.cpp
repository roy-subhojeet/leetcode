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
    int dia = INT_MIN;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        calDiameter(root);
        return dia;
    }
    int calDiameter(TreeNode* const& root)
    {
        if(root == nullptr) return 0;
        int leftC = calDiameter(root->left);
        int rightC = calDiameter(root->right);
        dia = max(dia, leftC + rightC);
        return max(leftC , rightC) + 1;
    }
};