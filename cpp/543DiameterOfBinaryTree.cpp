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
    int diameter = 0;

    int dfs(TreeNode* node) {
        if (node == NULL) return 0;

        int leftLen = dfs(node->left);
        int rightLen = dfs(node->right);

        diameter = max(leftLen + rightLen, diameter);
        return 1 + max(leftLen, rightLen);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter;
    }
};
