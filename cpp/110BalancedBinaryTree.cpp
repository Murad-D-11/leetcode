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
    int dfs(TreeNode* node) {
        if (node == NULL) return 0;
        
        int left = dfs(node->left);
        if (left == -1) return -1; // we can't break a recursion, so we just return -1 until the very end

        int right = dfs(node->right);
        if (right == -1) return -1;

        if (abs(left - right) > 1) return -1; // the decisive check

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return dfs(root) != -1;
    }
};
