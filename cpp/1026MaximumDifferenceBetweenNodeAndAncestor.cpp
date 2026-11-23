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
    int maxDiff = INT_MIN;

    void dfs(TreeNode* node, int minNode, int maxNode) {
        if (node == NULL) return;

        minNode = min(minNode, node->val);
        maxNode = max(maxNode, node->val);

        if (node->left == NULL && node->right == NULL) {
            maxDiff = max(maxDiff, abs(maxNode - minNode));
            return;
        }

        dfs(node->left, minNode, maxNode);
        dfs(node->right, minNode, maxNode);
    }

    int maxAncestorDiff(TreeNode* root) {
        dfs(root, INT_MAX, INT_MIN);
        return maxDiff;
    }
};
