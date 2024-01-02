class Solution {
private:
    TreeNode* prev = nullptr;

public:
/*
Why Checking Only the Last Added Node Works
Inorder Property: In a BST, the inorder traversal yields nodes in a sorted, ascending order.
Local Validity Implies Global Validity: If every node, when compared to its immediate predecessor (prev in this case), maintains the BST property (i.e., each node is greater than its previous node), then the entire tree is a valid BST.
Efficiency: This method is efficient because it only requires constant space for the prev pointer and checks each node exactly once.
*/
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }

    bool inorder(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (!inorder(root->left)) {
            return false;
        }
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }
        prev = root;
        return inorder(root->right);
    }
/* recursive traversal with valid range
    bool isValidBST(TreeNode* root) {
        return inorder(root);
    }

    bool inorder(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        if (!inorder(root->left)) {
            return false;
        }
        if (prev != nullptr && root->val <= prev->val) {
            return false;
        }
        prev = root;
        return inorder(root->right);
    }
*/
};

