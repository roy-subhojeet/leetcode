/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans = nullptr;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

 TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;

        TreeNode* lc = dfs(root->left, p, q);
        TreeNode* rc = dfs(root->right, p, q);

        // If the current node is either p or q
        if(root == p || root == q) {
            if((lc && (lc == p || lc == q)) || (rc && (rc == p || rc == q))) {
                ans = root;
            }
            return root;
        }

        // If p and q are found on both sides of the current node
        if(lc && rc) {
            ans = root;
            return root;
        }

        // If only one of p or q is found
        return lc ? lc : rc;
    }
};