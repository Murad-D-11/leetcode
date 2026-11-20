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
    int maxDep = 0;

    void dfs(TreeNode* node, int currentDep) {
        if (node == NULL) return;

        currentDep++;
        if (node->left == NULL && node->right == NULL) {
            maxDep = max(maxDep, currentDep);
            return;
        }

        dfs(node->left, currentDep);
        dfs(node->right, currentDep);
    }

    int maxDepth(TreeNode* root) {
        dfs(root, 0);
        return maxDep;
    }
};
