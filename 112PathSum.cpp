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
    bool dfs(TreeNode* node, int currentSum, int targetSum) {
        if (node == NULL) return false;
        currentSum += node->val;

        if (node->left == NULL && node->right == NULL)
            return currentSum == targetSum;

        return dfs(node->left, currentSum, targetSum) || dfs(node->right, currentSum, targetSum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root, 0, targetSum);
    }
};
