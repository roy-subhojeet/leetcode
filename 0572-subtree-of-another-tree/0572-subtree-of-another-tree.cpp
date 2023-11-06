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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr) return false;
        if(checkEq(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool checkEq(TreeNode* n1, TreeNode* n2)
    {
        if(n1 && !n2 || n2 && !n1) return false;
        if(n1 && n2 && n1->val != n2->val) return false;
        if(!n1 && !n2) return true;
        return checkEq(n1->left, n2->left) && checkEq(n1->right, n2->right);
    }
};