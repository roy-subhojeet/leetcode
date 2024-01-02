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
    vector<int> array;
public:
    void inOrderTraversal(TreeNode* root)
    {
        if(root == nullptr) return;
        inOrderTraversal(root->left);
        array.push_back(root->val);
        inOrderTraversal(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        inOrderTraversal(root);
        return array[k-1];
    }
};