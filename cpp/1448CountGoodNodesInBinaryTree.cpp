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
    int numGoodNodes = 0;

    void dfs(TreeNode* node, int maxNode) {
        if (node == NULL) return;

        if (maxNode <= node->val) {
            maxNode = node->val;
            numGoodNodes++;
        }

        dfs(node->left, maxNode);
        dfs(node->right, maxNode);
    }

    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return numGoodNodes;
    }
};
