class Solution {
public:
    TreeNode* ans = nullptr;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return false;

        int left = dfs(root->left, p, q) ? 1 : 0;
        int right = dfs(root->right, p, q) ? 1 : 0;

        int mid = (root == p || root == q) ? 1 : 0;

        if (mid + left + right >= 2) {
            ans = root;
        }

        return (mid + left + right) > 0;
    }
};
